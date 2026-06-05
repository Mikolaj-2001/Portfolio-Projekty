import { Controller, Post, Body, Param, Get, Render, Query, UseGuards, Req } from '@nestjs/common';
import { AuthMiddelware } from '../user/auth-configuration/config-auth.middelware';
import { ActionServiceService } from 'src/action-service/action-service.service';
import { CreateAction } from './action-dto/action-create.dto';
import { UpdateAction } from './action-dto/action-update.dto';
import { UserServiceService } from 'src/user-service/user-service.service';
import { Types } from 'mongoose';
import { IsMongoId } from 'class-validator';

// DTO for delete action
class DeleteActionDto {
    @IsMongoId()
    readonly id!: string;
}

@Controller('user/action')
export class ActionController {
    constructor(
        private readonly actionService: ActionServiceService,
        private readonly userService: UserServiceService,
    ) { }
    @Get('lottery')
    @Render('pageView/lotteryNumbers')
    async getLotteryNumbers(@Query('option') option?: number) {
        const userID = new Types.ObjectId();
        /* Tworzenie struktury dla nowej akcji */
        const createActionDto: CreateAction = {
            userID: userID,
            option: option || 0,
            description: ""
        };
        const action = await this.actionService.create(createActionDto);
        // Pobierz dane użytkownika
        const user = await this.userService.findById(userID.toString());
        return {
            user: user ? {
                _id: user._id,
                userName: user.userName,
                email: user.email,
                password: "***"
            } : undefined,
            action: {
                _id: action._id,
                option: action.option,
                description: action.description
            },
            option: action.option
        };
    }

    @Post('update/:id')
    @UseGuards(AuthMiddelware)
    @Render('pageView/lotteryNumbers')
    async updateAction(@Param('id') id: string, @Body() updateActionDto: UpdateAction, @Req() req) {
        if (!id) {
            return { message: 'Brak wymaganych danych do aktualizacji.' };
        }
        const updatedAction = await this.actionService.update(id, updateActionDto);
        if (!updatedAction) {
            return { message: 'Nie znaleziono akcji do aktualizacji.' };
        }
        // Użyj user z req ustawionego przez middleware
        const user = req.user || (updatedAction.userID && await this.userService.findById(updatedAction.userID.toString()));
        return {
            user: user ? {
                _id: user._id,
                userName: user.userName,
                email: user.email,
                password: "***"
            } : undefined,
            action: {
                _id: updatedAction._id,
                option: updatedAction.option,
                description: updatedAction.description
            },
            option: updatedAction.option,
            message: 'Akcja została zaktualizowana.'
        };
    }

    @Post('delete/:id')
    @UseGuards(AuthMiddelware)
    @Render('pageView/lotteryNumbers')
    async deleteAction(@Param('id') id: string, @Body() deleteActionDto: DeleteActionDto, @Req() req) {
        if (!id || !deleteActionDto.id || id !== deleteActionDto.id) {
            return { message: 'Brak ID akcji do usunięcia lub ID niezgodne.' };
        }
        const actionToDelete = await this.actionService.findOne(id);
        if (!actionToDelete) {
            return { message: 'Nie znaleziono akcji do usunięcia.' };
        }
        const user = req.user || (actionToDelete.userID && await this.userService.findById(actionToDelete.userID.toString()));
        await this.actionService.remove(id);
        return {
            user: user ? {
                _id: user._id,
                userName: user.userName,
                email: user.email,
                password: "***"
            } : undefined,
            message: "Akcja została usunięta. Wybierz 'Uruchom Loterię' żeby wylosować nową opcję."
        };
    }

    @Post('create')
    async createAction(@Body() createActionDto: CreateAction) {
        return await this.actionService.create(createActionDto)
    }

}
