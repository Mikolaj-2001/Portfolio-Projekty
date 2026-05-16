import { Test, TestingModule } from '@nestjs/testing';
import { UserServiceService } from './user-service.service';
import { describe, it, beforeEach, expect } from '@jest/globals';

describe('UserServiceService', () => {
  let service: UserServiceService;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [UserServiceService],
    }).compile();

    service = module.get<UserServiceService>(UserServiceService);
  });

  it('should be defined', () => {
    expect(service).toBeDefined();
  });
});
