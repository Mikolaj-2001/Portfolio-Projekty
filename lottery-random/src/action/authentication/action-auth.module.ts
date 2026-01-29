import { Module } from '@nestjs/common';
import { ActionAuthServiceService } from './action-auth-service.service';
import { AuthControllerController } from './auth-controller.controller';

@Module({
  providers: [ActionAuthServiceService],
  controllers: [AuthControllerController]
})
export class ActionAuthModule {}
