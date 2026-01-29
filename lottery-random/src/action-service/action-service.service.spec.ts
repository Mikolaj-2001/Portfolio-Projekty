import { Test, TestingModule } from '@nestjs/testing';
import { ActionServiceService } from './action-service.service';

describe('ActionServiceService', () => {
  let service: ActionServiceService;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [ActionServiceService],
    }).compile();

    service = module.get<ActionServiceService>(ActionServiceService);
  });

  it('should be defined', () => {
    expect(service).toBeDefined();
  });
});
