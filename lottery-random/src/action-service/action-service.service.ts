import { Injectable, NotFoundException } from '@nestjs/common';
import { InjectModel } from '@nestjs/mongoose';
import { Model } from 'mongoose';
import { Action } from 'src/action/action-schema/action.schema';
import { User } from 'src/user/user-schema/user.schema';
import { CreateAction } from 'src/action/action-dto/action-create.dto';
import { UpdateAction } from 'src/action/action-dto/action-update.dto';

@Injectable()
export class ActionServiceService {
    constructor(
        @InjectModel(Action.name) private actionModel: Model<Action>,
        @InjectModel(User.name) private userModel: Model<User>,
    ) { }

    async create(createAction: CreateAction,
    ): Promise<Action> {
        const options: number[] = [1, 2, 3, 4, 5, 6];

        const selectedOption = options[Math.floor(Math.random() * options.length)];

        const map: Record<number, string> = {
            1: "Opis 1",
            2: "Opis 2",
            3: "Opis 3",
            4: "Opis 4",
            5: "Opis 5",
            6: "Opis 6",
        }

        const description = map[selectedOption] ?? 'Brak wymaganego opisu';//?? operator nullish coalescing, który zwraca wartość po lewej stronie, jeśli nie jest null lub undefined, w przeciwnym razie zwraca wartość po prawej stronie. W tym przypadku, jeśli map[selectedOption] jest null lub undefined, zostanie użyty domyślny opis 'Brak wymaganego opisu'.
        createAction = { ...createAction, option: selectedOption, description };// tworzy nowy obiekt createAction, który zawiera wszystkie właściwości z oryginalnego createAction oraz dodatkowe właściwości option i description.

        const newAction = new this.actionModel(createAction)

        switch (createAction.option) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                console.log('Nie wylosowano żadanej opcji')
                break;
        }
        return await newAction.save()
    }

    async findOne(actionId: string): Promise<Action> {
        const action = await this.actionModel.findById(actionId).exec();

        if (!action) {
            throw new NotFoundException(`Akcja o podanym identyfikatorze ${actionId} nie znaleziona`);
        }

        return action;
    }

    async update(
        actionId: string,
        updateActionDto: UpdateAction,
    ): Promise<Action> {
        const updateAction = await this.actionModel
            .findByIdAndUpdate(actionId, updateActionDto, { new: true })//new: true - zwraca zaktualizowany dokument zamiast oryginalnego przed aktualizacją

        if (!updateAction) {
            throw new NotFoundException(`Akcja o podanym identyfikatorm:${actionId} nie istnieje lub nie znaleziona`)
        }
        const userId = updateAction.userID

        if (userId) {
            const info = `Użytkownik wybrał ${updateAction.option}`
            await this.userModel.findByIdAndUpdate(userId, { $set: { updatedAction: info } })
        }
        return updateAction
    }

    async remove(actionId: string): Promise<void> {
        const action = await this.actionModel.findByIdAndDelete(actionId).exec()

        if (!action) {
            throw new NotFoundException(`Akcja o podanym identfikatorze ${actionId} nie znaleziona`)
        }

        await this.userModel.updateMany(
            { action: actionId },
            { $pull: { action: actionId } },
        )

    }
}
