import { Controller, Post, Body, UnauthorizedException, Res, Get, Render, Req, UseGuards, Query, Param } from '@nestjs/common';
import { LoginAuthService } from './authentication2/user-jwt-auth.guard';
import { UserRegistered } from './user-dto/user-registered.dto';
import { UserNewLogin } from './user-dto/user-newLogin.dto';
import { UserAuthServiceService } from './authentication2/user-auth-service.service';
import { Response } from 'express';
import { Request } from 'express';
import { AuthMiddelware } from './auth-configuration/config-auth.middelware';
import { FileConfiguring } from 'src/user-service/user-fileCreation.service';
import * as fs from 'fs';
import * as path from 'path';

interface AuthenticatedRequest extends Request {// Rozszerzenie interfejsu Request o właściwość user, która będzie przechowywać dane uwierzytelnionego użytkownika
    user?: any;
}

@Controller('user')
export class UserController {
    constructor(private readonly loginAuthService: LoginAuthService,
        private readonly Authentication: UserAuthServiceService,//readonly, ponieważ nie planujemy przypisywać nowej instancji tej usługi do tej właściwości, a jedynie korzystać z jej metod do obsługi logiki uwierzytelniania i rejestracji użytkowników.
        private readonly fileConfiguring: FileConfiguring
    ) { }

    @Post('register')
    async register(@Body() registerDto: UserNewLogin, @Res() res: Response) {
        try {
            const resultingRegistration = await this.Authentication.register(registerDto)

            if (resultingRegistration) {
                return res.redirect('/user/login');
            } else {
                throw new UnauthorizedException('Rejestracja nie powiodła się')
            }
        } catch (error) {
            const errorMessage = error instanceof Error ? error.message : String(error);
            console.log('❌ Błąd podczas rejestracji:', errorMessage);
            throw new UnauthorizedException('Błąd podczas procesu rejestracji użytkownika: ' + errorMessage)
        }
    }

    @Get('register')
    @Render('pageView/loggingView')
    async showRegisterForm() {
        return {
            user: {
                email: '',
                userName: ''
            }
        };
    }

    @Get('login')
    @Render('pageView/RegisteredUser')
    async showLoginForm() {
        return {
            user: {
                email: '',
                userName: ''
            }
        }
    }

    @Post('login')
    async login(
        @Body() loginDto: UserRegistered,
        @Res() res: Response,
    ) {
        try {
            console.log('🔍 Próba logowania dla:', loginDto.email);
            const firstProcedure = await this.Authentication.login(loginDto.email, loginDto.password, res)
            console.log('✅ firstProcedure wynik:', firstProcedure);

            const secondProcedure = await this.loginAuthService.validateTheUser(loginDto.email, loginDto.password);
            console.log('✅ secondProcedure wynik:', secondProcedure);

            if (!firstProcedure || !secondProcedure) {
                console.log('❌ Walidacja nie powiodła się - firstProcedure:', !!firstProcedure, 'secondProcedure:', !!secondProcedure);
                throw new UnauthorizedException('Dane są nieprawidłowe')
            }

            // Pobierz użytkownika z bazy, aby mieć pewność, że _id jest obecne
            const userFromDb = await this.Authentication.findUserByEmail(loginDto.email);
            console.log('USER przekazywany do widoku:', userFromDb);
            if (!userFromDb) {
                throw new UnauthorizedException('Nie znaleziono użytkownika w bazie danych');
            }
            return res.render('pageView/lotteryNumbers', {
                user: {
                    ...userFromDb.toObject(),
                    _id: userFromDb._id,
                },
                ValidationCompleteness: firstProcedure,
                userValidation: secondProcedure,
                option: 0
            });
        } catch (error) {
            const errorMessage = error instanceof Error ? error.message : String(error);
            console.log('❌ Błąd podczas logowania:', errorMessage);
            throw error;
        }
    }

    @Get('lottery')
    @UseGuards(AuthMiddelware)
    @Render('pageView/lotteryNumbers')
    async showLottery(@Req() req: AuthenticatedRequest) {
        const authenticatedUser = req.user as any;
        if (!authenticatedUser) {
            throw new UnauthorizedException('Użytkownik nie został uwierzytelniony');
        }
        const userFromDb = await this.Authentication.findUserByEmail(authenticatedUser.email);
        if (!userFromDb) {
            throw new UnauthorizedException('Nie znaleziono użytkownika w bazie danych');
        }
        return {
            user: {
                ...userFromDb.toObject(),
                _id: userFromDb._id,
            }
        };
    }

    @Get('action/lottery/:id')
    @Render('pageView/lotteryNumbers')
    async getLotteryAction(@Query('option') option: number, @Param('id') id: string) {
        return { option, userId: id };
    }

    @Post('lottery')
    @Render('pageView/LotteryNumbers')
    async processLottery() { }

    @Get('DataView')
    @UseGuards(AuthMiddelware)
    @Render('pageView/DataView')
    async ShowDataView(@Req() req: AuthenticatedRequest) {
        const authenticatedUser = req.user as any;
        if (!authenticatedUser) {
            throw new UnauthorizedException('Użytkownik nie został uwierzytelniony');
        }

        const filePath = path.join(process.cwd(), 'userData', 'userIndication.json');/* Ten kod pozwala na odczyt pliku JSON z folderu userData */
        const dataLoading = fs.readFileSync(filePath, 'utf-8');
        const jsonData = JSON.parse(dataLoading)

        const userData = jsonData.find(u => u.email === authenticatedUser.email);
        if (!userData) {
            throw new UnauthorizedException('Nie znaleziono danych użytkownika');
        }

        return { user: userData };
    }

    @Post('DataView')
    @UseGuards(AuthMiddelware)
    @Render('pageView/DataView')
    async ProcessDataLinkView(@Req() req: AuthenticatedRequest) {
        const authenticatedUser = req.user as any;

        if (!authenticatedUser) {
            throw new UnauthorizedException('Użytkownik nie został uwierzytelniony')
        }

        const userResponse = {
            userName: authenticatedUser.userName,
            encryptedEmail: authenticatedUser.encryptedEmail,
            encryptedId: authenticatedUser.encryptedId,
        }

        return {
            user: userResponse
        }
    }

    @Post('logout')
    async logout(@Res() res: Response) {
        try {
            res.clearCookie('jwt', {
                httpOnly: true,
                secure: process.env.NODE_ENV === "production", // Ustawienie przesyłania tylko przez żądanie HTTPS i ustawienie, aby działa w trybie produkcyjnym na serwerze HTTPS
                sameSite: "strict"
            });
            return res.redirect('/user/login');
        } catch (error) {
            const errorMessage = error instanceof Error ? error.message : String(error);
            console.log('❌ Błąd podczas wylogowania:', errorMessage); 
            throw error;
        }
    }

    @Post('delete')
    @UseGuards(AuthMiddelware)
    async deleteUser(@Req() req: AuthenticatedRequest, @Res() res: Response) {
        const authenticatedUser = req.user as any;

        if (!authenticatedUser) {
            throw new UnauthorizedException('Użytkownik nie został uwierzytelniony');
        }

        await this.Authentication.deleteUser(authenticatedUser.email, authenticatedUser.userID);
        await this.fileConfiguring.deleteFile(authenticatedUser.email, authenticatedUser.userID);

        await this.fileConfiguring.detectAllUsers();

        return res.redirect('/user/register');
    }

    /* @Post('face-recognition')
    async faceStoring(@Body() body: { image: string }) {
        const folderPath = 'c:/Users/kazac/OneDrive/Pulpit/Loteria/lottery-random/src/biometricSecurity/faceRecognition';
        const filePath = path.join(folderPath, 'faceScan.png');
        // Sprawdź, czy folder istnieje, jeśli nie, utwórz go

        if (!fs.existsSync(folderPath)) {
            return { success: false, message: 'Folder nie istnieje' };
        }

        const base64Data = body.image.replace(/^data:image\/png;base64,/, '');// Usuń prefiks danych base64, jeśli istnieje, aby uzyskać czyste dane base64,co pozwoli na zapis pliku w formie szyfrowanej
        const imageBuffer = Buffer.from(base64Data, 'base64');// Konwertuj dane base64 na bufor,czyli surowe dane binarne obrazu,aby obraz został zapisany w serwerze

        fs.writeFileSync(filePath, imageBuffer);// Zapisz bufor jako plik obrazu na dysku,aby próściej mówiąc zapisać obraz

        return { success: true, message: 'Obraz został zapisany pomyślnie' };
    } */
}

