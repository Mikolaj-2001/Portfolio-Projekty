import { Injectable, UnauthorizedException } from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { InjectModel } from '@nestjs/mongoose';
import { Model, Types } from 'mongoose';
import { User } from '../user-schema/user.schema';
import { Response } from 'express';
import { UserNewLogin } from '../user-dto/user-newLogin.dto';
import { ConfigService } from '@nestjs/config';
import { FileConfiguring } from '../../user-service/user-fileCreation.service';
import { UserServiceService } from '../../user-service/user-service.service';

@Injectable()
export class UserAuthServiceService {
    [x: string]: any;
    constructor(
        private readonly jwtService: JwtService,
        @InjectModel(User.name) private userModel: Model<User>,
        private configService: ConfigService,
        private readonly fileConfiguring: FileConfiguring,
        private readonly userService: UserServiceService,
    ) { }

    async findUserByEmail(email: string) {
        return this.userService.findByEmail(email);
    }

    async generateAuthToken(identifier: string, res: Response): Promise<void> {
        let user = await this.userModel.findOne({
            $or: [/* Oznacza dopasuj dokument,jeżeli którykolwiek warunek jest spełniony */
                { email: identifier },
                { userName: identifier },
            ]
        });
        /* Obsługa zaszyfrowanych danych użyutkownika w celu ich porównania pod względem zgodności */
        if (!user) {
            const users = await this.userModel.find();

            for (const dbUser of users) {
                try {
                    const decryptedEmail = (dbUser as any).getDecryptedEmail()
                    if (decryptedEmail == identifier) {
                        user = dbUser;
                        break; // Przerywamy pętlę, gdy znajdziemy użytkownika
                    }
                } catch (error) {
                    continue;
                }
            }
        }
        if (!user) {
            throw new UnauthorizedException('Brak obecności podanego użytkownika')
        }
        /* metoda as any pozwala na dostęp do metod instancji, które nie są typowane,czyli inaczej wykorzystanie metody na komponentach modelu User*/
        const decryptedEmail = (user as any).getDecryptedEmail();
        const payload = { email: decryptedEmail, id: user._id, userName: user.userName };

        const token = this.jwtService.sign(payload, {
            secret: this.configService.get<string>('JWT_TOKEN'),
            expiresIn: this.configService.get<string>('JWT_TOKEN_EXPIRES_IN') || '1h'
        });

        res.cookie('jwt', token, {
            httpOnly: true,/* Ustawianie cookies jako niedostępnych z poziomu JavaScript,czyli nie można ich odczytać ani zmodyfikować z poziomu klienta */
            sameSite: 'strict',/* Wysyłanie cookies z żądaniem do domen o tym samym adresie  */
            secure: process.env.Node_ENV === 'production',/* ustawienie przesyłania tylko przez żądanie HTTPS i ustawienie,aby działa w trybie produkcyjnym na serwerze HTTPS */
            maxAge: 3600000,/* Długość ważności cookies */
        })/* Ta struktura zapewnia bezpieczeństwo przechowywania danych w serwerze HTTP */
    }

    async login(identifier: string, password: string, res: Response): Promise<any> {
        let user = await this.userModel.findOne({
            $or: [
                { email: identifier },
                { userName: identifier },
            ]
        })
        if (!user) {
            const users = await this.userModel.find();

            for (const dbUser of users) {
                try {
                    const decryptedEmail = (dbUser as any).getDecryptedEmail()
                    if (decryptedEmail == identifier) {
                        user = dbUser;
                        break; // Przerywamy pętlę, gdy znajdziemy użytkownika
                    }
                } catch (error) {
                    continue;
                }
            }
        }
        if (!user) {
            throw new UnauthorizedException("Użytkownik nie odnaleziony w bazie")
        }

        const decryptedPassword = (user as any).getDecryptedPassword();
        const passwordIsValid = (password === decryptedPassword);
        if (!passwordIsValid) {
            throw new UnauthorizedException("Hasło jest nieprawidłowe")
        }
        await this.generateAuthToken(identifier, res)
        const decryptedEmail = (user as any).getDecryptedEmail(); // Używamy metody zdefiniowanej w user.schema.ts
        return {
            message: "Zalogowano pomyślnie",
            user: {
                id: user._id,
                email: decryptedEmail,
                userName: user.userName,
            }
        }
    }

    async register(userData: UserNewLogin): Promise<User | null | any> {
        const { email, userName, password } = userData

        let existenceOfUser = await this.userModel.findOne({
            $or: [/* „Zwróć dokumenty, które spełniają przynajmniej jeden z poniższych warunków.” */
                { email: email },
                { userName: userName }
            ]
        });

        if (existenceOfUser) {
            throw new UnauthorizedException('Użytkownik o podanych danych już istnieje')
        }
        const existingUsers = await this.userModel.find({});//Szukamy tutaj użytkowników,aby sprawdzić czy nie istnieje już taki użytkownik we wszystkich dokumentach bazy danych,dlatego używamy find({}) bez żadnych warunków
        for (const user of existingUsers) {
            try {
                const decryptedEmail = (user as any).getDecryptedEmail();
                if (decryptedEmail == email) {
                    throw new UnauthorizedException("Użytkownik o podanym adresie email już istnieje")
                }
            } catch (error) {
                continue
            }
        }

        const newUser = new this.userModel({
            email,
            userName,
            password,
        })

        const savedUser = await newUser.save();

        // Zapisz też do pliku JSON - przekaż ID użytkownika
        try {
            await this.fileConfiguring.createFile({
                createUserDto: { userName, email, password },
                asignActionDto: { option: 0, description: 'default', userID: savedUser._id as Types.ObjectId }
                // przekazujemy userID jako Types.ObjectId,aby zachować zgodność z typem w schemacie mongoose
            });
        } catch (error) {
            console.log('Błąd podczas tworzenia pliku zapasowego:', error);
        }

        return savedUser;
    }

    async verifyToken(token: string): Promise<any> {
        try {
            const decoded = this.jwtService.verify(token, {
                secret: this.configService.get<string>('JWT_TOKEN')
            });
            return decoded;
        } catch (error) {
            throw new UnauthorizedException('Nieprawidłowy token');
        }
    }

    async deleteUser(email: string, userID: string): Promise<any> {
        try {
            await this.userModel.deleteOne({ email, _id: userID });
            return { message: "Użytkownik został usunięty" };
        } catch (error) {
            throw new UnauthorizedException('Błąd podczas usuwania użytkownika');
        }
    }
} 
