import { Controller, Get, Render } from '@nestjs/common';

@Controller()
export class AppController {
  @Get()
  @Render('pageView/RegisteredUser')
  getLogin() {
    return { message: 'Zaloguj się do aplikacji loterii' };
  }
}
