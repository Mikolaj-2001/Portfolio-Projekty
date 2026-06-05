import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { NestExpressApplication } from '@nestjs/platform-express';
import { join } from 'path';
import * as hbs from 'hbs';
import rateLimit from 'express-rate-limit';
import cookieParser = require('cookie-parser');

async function bootstrap() {
  console.log('Uruchamianie programu...')
  const app = await NestFactory.create<NestExpressApplication>(AppModule);/* Uruchamia i tworzy instancje klasy uruchomieniowej projektu Nest.js */

  // WAŻNE: Dodaj cookie parser PRZED innymi middleware
  app.use(cookieParser());

  /* Ograniczenie liczby prób logowania czasowo */
  const loginLimitation = rateLimit({
    windowMs: 20 * 60 * 1000, // 20 minut-czas odnowienia limitu
    max: 5,  // 5 prób na 20 minut
    message: 'Osiągnięto maksymalną ilość prób. Spróbuj później.',
    standardHeaders: true, // Informacje o limicie w nagłówkach
    legacyHeaders: false, // Wyłączenie starych nagłówków
  })

  // Konfiguracja Handlebars dla widoków
  app.setBaseViewsDir(join(__dirname, '..', 'src', 'views'));
  app.setViewEngine('hbs');

  // Konfiguracja plików statycznych (CSS, JS, obrazy)
  app.useStaticAssets(join(__dirname, '..', 'public'));
  console.log('📁 Static assets path:', join(__dirname, '..', 'public'));

  // Konfiguracja partials
  hbs.registerPartials((join(__dirname, '..', 'src', 'views', 'partials')));
  hbs.registerPartials((join(__dirname, '..', 'src', 'views', 'Personalities')));

  // Obsługa metody switch case w widoku Handlebars
  // Umożliwia użycie switch case w szablonach Handlebars
  hbs.registerHelper('switch', function (this: any, value: any, options: any) {
    this.switch_value = value;
    this.switch_break = false;
    return options.fn(this);/* Oznacza funkcję zawierającą kod HTML */
  });

  hbs.registerHelper('case', function (this: any, value: any, options: any) {
    if (value == this.switch_value) {
      this.switch_break = true;
      return options.fn(this);
    }
  });

  hbs.registerHelper('default', function (this: any, options: any) {
    if (this.switch_break == false) {
      return options.fn(this);
    }
  });

  console.log('Program uruchumiony pomyślnie!')

  app.use('/user/login', loginLimitation); // Ograniczenie liczby prób logowania

  await app.listen(process.env.APP_PORT ?? 3000);
  console.log('Program działą na porcie:', process.env.APP_PORT ?? 3000);
}
bootstrap();
