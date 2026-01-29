import { Module } from '@nestjs/common';
import { UserAuthServiceService } from './user-auth-service.service';

@Module({
  providers: [UserAuthServiceService]
})
export class UserAuthModule {}
