import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { UserModuleModule } from './user-module/user-module.module';
import { ActionModuleModule } from './action-module/action-module.module';
import { MongooseModule } from '@nestjs/mongoose';
import { ConfigModule } from '@nestjs/config';

@Module({
  imports: [
    UserModuleModule, 
    ActionModuleModule, 
    MongooseModule.forRoot('mongodb://localhost:27017/lottery-random'),
    ConfigModule.forRoot({isGlobal:true})// Dodaj konfigurację globalną,czyli dostęp do zmiennych środowiskowych w całej aplikacji
  ],
  controllers: [AppController], // Tylko główny kontroler
  providers: [], 
})
export class AppModule {}
