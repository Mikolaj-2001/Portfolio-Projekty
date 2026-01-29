import { Injectable } from '@nestjs/common';

@Injectable()
export class AppService {
  getAppInfo(): { name: string; version: string; description: string } {
    return {
      name: 'Lottery Random App',
      version: '1.0.0',
      description: 'Aplikacja losująca typy osobowości dla użytkowników'
    };
  }

  getWelcomeMessage(): string {
    return 'Witaj w aplikacji loterii typów osobowości!';
  }
}
