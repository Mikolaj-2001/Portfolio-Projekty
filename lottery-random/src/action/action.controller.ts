import { Controller, Post, Body, Param, Get, Render, Query } from '@nestjs/common';
import { ActionServiceService } from 'src/action-service/action-service.service';
import { CreateAction } from './action-dto/action-create.dto';
import { UserServiceService } from 'src/user-service/user-service.service'; // Importuj UserServiceService
import { Types } from 'mongoose';

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
        return {/* Tutaj zwracam obiket z polami danych po utorzeniu nowej akcji */
            action: {
                _id: action._id,
                option: action.option,
                description: action.description
            },
            option: action.option
        };
    }

    @Get('update/:id')
    @Render('pageView/lotteryNumbers')
    async updateActionByGet(@Param('id') id: string) {
        // Aktualizuj akcję z nową losową opcją
        const updatedAction = await this.actionService.update(id, { option: Math.floor(Math.random() * 4) + 1 });

        // Pobierz dane użytkownika
        const user = await this.userService.findById(updatedAction.userID.toString());

        // Zwróć zaktualizowane dane do widoku
        return {
            user: {
                _id: updatedAction.userID,
                id: updatedAction.userID, // Dodaj też 'id' dla kompatybilności
                userName: user?.userName,
                email: user?.email,
                password: "***"
            },
            action: {
                _id: updatedAction._id,
                option: updatedAction.option,
                description: updatedAction.description
            },
            option: updatedAction.option,
        };
    }

    @Get('delete/:id')
    @Render('pageView/lotteryNumbers')
    async deleteActionByGet(@Param('id') id: string) {
        // Znajdź akcję przed usunięciem żeby pobrać userId
        const actionToDelete = await this.actionService.findOne(id);
        const userId = actionToDelete.userID;

        // Usuń akcję
        await this.actionService.remove(id);

        // Pobierz dane użytkownika
        const user = await this.userService.findById(userId.toString());/* Konwertujemy na string ze względu na to,że id jest typu ObjectId */

        // Zwróć widok bez wylosowanej opcji
        return {
            user: {
                _id: userId,
                id: userId, // Dodaj też 'id' dla kompatybilności
                userName: user?.userName,
                email: user?.email,
                password: "***"
            },
            // Brak action i option - widok będzie pusty
            message: "Akcja została usunięta.Wybierz 'Uruchom Loterię' żeby wylosować nową opcję."
        };
    }

    @Post()
    async createAction(@Body() createActionDto: CreateAction) {
        return await this.actionService.create(createActionDto)
    }

}
