import { Test, TestingModule } from '@nestjs/testing';
import { AppController } from './app.controller';
import { AppService } from './app.service';

describe('AppController', () => {
  let appController: AppController;

  beforeEach(async () => {
    const app: TestingModule = await Test.createTestingModule({
      controllers: [AppController],
      providers: [AppService],
    }).compile();

    appController = app.get<AppController>(AppController);
  });

  describe('root', () => {//describe to jest grupa testów, można mieć kilka describe w jednym pliku.Służy do organizowania testów w logiczne grupy.
    it('should return "Hello World!"', () => {
      expect(appController.getHello()).toBe('Hello World!');//tutaj można zmienić na to co jest w app.service.ts w getWelcomeMessage()
    });
  });
});
