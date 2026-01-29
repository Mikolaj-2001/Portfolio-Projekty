import { Injectable } from '@nestjs/common';
import { InjectModel } from '@nestjs/mongoose';
import { Model } from 'mongoose';
import { User } from 'src/user/user-schema/user.schema';
import { Action } from 'src/action/action-schema/action.schema';

@Injectable()
export class UserServiceService {
    constructor(
        @InjectModel(User.name) private userModel: Model<User>,
        @InjectModel(Action.name) private actionModel: Model<Action>,
    ) { }
    private users: any[] = [];

    async create(createUserDto: { userName: string, email: string; password: string }, asignActionDto: { option: number, description: string }) {
        const createdAction = new this.actionModel(asignActionDto)
        const savedAction = await createdAction.save();
        const userFinalModel = { ...createUserDto, action: savedAction._id }
        const createdUser = new this.userModel(userFinalModel);
        const savedUser = await createdUser.save();
        const newJsonFormat = savedUser.toJSON();
        this.users.push(newJsonFormat);
        return newJsonFormat
    }

    async update(
        actionId: string,
        updateUserDto: { userName?: string, email?: string, password?: string, action?: { option?: number, description?: string } }
    ) {
        const user = await this.userModel.findOne({ action: actionId })
        if (!user) {
            throw new Error("Akcja o podanym id nie posiada przypisanego użytkownika")
        }
        if (updateUserDto.action) {
            await this.actionModel.findByIdAndUpdate(actionId, updateUserDto.action, { new: true })
        }
        const updateUser = await this.userModel.findByIdAndUpdate(user._id, updateUserDto.action, { new: true }).lean()
        return updateUser
    }

    async remove(actionId: string) {
        const user = await this.userModel.findOne({ action: actionId });
        if (!user) {
            throw new Error('Akcja o podanym id nie posiada przypisanego użytkownika')
        }

        await this.userModel.findByIdAndDelete(user._id)
        await this.actionModel.findByIdAndDelete(actionId)

        this.users = this.users.filter(u => u._id !== user._id);
        // Usuwamy użytkownika z lokalnej tablicy,poprzez filtrację polegającą na tym,że zostaną tylko ci użytkownicy,którzy nie mają tego id
    }

    async findById(userId: string): Promise<User | null> {
        return this.userModel.findById(userId).lean().exec()
    }

    async findByEmail(email: string): Promise<User | null> {
        // Pierwsza próba - szukaj niezaszyfrowanego emaila
        let user = await this.userModel.findOne({ email }).exec();
        
        // Jeśli nie znaleziono, sprawdź zaszyfrowane emaile
        if (!user) {
            const allUsers = await this.userModel.find({}).exec();
            
            for (const dbUser of allUsers) {
                try {
                    const decryptedEmail = (dbUser as any).getDecryptedEmail();
                    if (decryptedEmail === email) {
                        user = dbUser;
                        break;
                    }
                } catch (error) {
                    continue;
                }
            }
        }
        
        return user;
    }
}
