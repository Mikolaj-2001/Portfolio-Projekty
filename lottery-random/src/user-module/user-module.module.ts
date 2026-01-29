import { Module, NestModule, MiddlewareConsumer, forwardRef, RequestMethod } from '@nestjs/common';
import { MongooseModule } from '@nestjs/mongoose';
import { UserController } from '../user/user.controller';
import { AuthControllerController } from 'src/action/authentication/auth-controller.controller';
import { UserAuthServiceService } from 'src/user/authentication2/user-auth-service.service';
import { LoginAuthService } from 'src/user/authentication2/user-jwt-auth.guard';
import { UserServiceService } from 'src/user-service/user-service.service';
import { UserSchema } from 'src/user/user-schema/user.schema';
import { ActionModuleModule } from 'src/action-module/action-module.module';
import { AuthMiddelware } from 'src/user/auth-configuration/config-auth.middelware';
import { JwtModule } from '@nestjs/jwt';
import { ConfigService } from '@nestjs/config';
import { FileConfiguring } from 'src/user-service/user-fileCreation.service';

@Module({
    imports: [
        MongooseModule.forFeature([{ name: 'User', schema: UserSchema }]),
        forwardRef(() => ActionModuleModule), // Użyj forwardRef żeby uniknąć cyklicznej zależności
        JwtModule.registerAsync({
            useFactory: /* Wstrzykuje zależność */(cfg: ConfigService) => ({
                secret: cfg.get<string>('JWT_TOKEN'),
                signOptions: { expiresIn: cfg.get<string>('JWT_TOKEN_EXPIRES_IN') || '1h' },
            }),
            inject: [ConfigService],/* Wstrzykiwanie listy zależności jako argument danej funkcji */
        })
    ],
    controllers: [UserController, AuthControllerController], // Kontrolery użytkowników
    providers: [UserAuthServiceService, UserServiceService, LoginAuthService, AuthMiddelware, FileConfiguring], // Dodaj middleware do providers
    exports: [UserServiceService, UserAuthServiceService, LoginAuthService] // Eksportuj serwisy
})
export class UserModuleModule implements NestModule {
    configure(consumer: MiddlewareConsumer) {
        consumer
            .apply(AuthMiddelware)
            .exclude(
                'user/login',
                'user/register',
                'user/user/login',      // Dodaj duplikowane trasy
                'user/user/register'    // Dodaj duplikowane trasy
            )
            .forRoutes(
                { path: 'user/*path', method: RequestMethod.ALL },/* RequestMethod.ALL oznacza wszystkie metody HTTP,czyli GET, POST, PUT, DELETE.Sprawdza obecność tokenu dla wszystkich tras użytkownika */
                { path: 'action/*path'/* Oznacza dopasuj wszystkie trasy zaczynające się od "action/" itd. */, method: RequestMethod.ALL }
            )
    }
}
