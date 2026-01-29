import { Module, forwardRef } from '@nestjs/common';
import { MongooseModule } from '@nestjs/mongoose';
import { ActionController } from 'src/action/action.controller';
import { ActionServiceService } from 'src/action-service/action-service.service';
import { Action, ActionSchema } from 'src/action/action-schema/action.schema';
import { User, UserSchema } from 'src/user/user-schema/user.schema';
import { UserModuleModule } from 'src/user-module/user-module.module';

@Module({
    imports: [
        MongooseModule.forFeature([
            { name: Action.name, schema: ActionSchema },
            { name: User.name, schema: UserSchema },
        ]),
        forwardRef(() => UserModuleModule), // Użyj forwardRef żeby uniknąć cyklicznej zależności.Zwraca moduł UserModuleModule, aby uniknąć cyklicznych zależności i zapobiec błędom
    ],
    controllers: [ActionController],
    providers: [ActionServiceService],
    exports: [ActionServiceService, MongooseModule] // Eksportuj serwis i MongooseModule dla innych modułów
})
export class ActionModuleModule {}

