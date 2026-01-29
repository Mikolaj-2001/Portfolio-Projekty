import { Injectable, NestMiddleware, UnauthorizedException } from "@nestjs/common";
import { Request, Response, NextFunction } from 'express';
import { UserAuthServiceService } from "../authentication2/user-auth-service.service";

@Injectable()
export class AuthMiddelware implements NestMiddleware {
    constructor(private readonly userAuthService: UserAuthServiceService) { }

    async use(req: Request, _res: Response, next: NextFunction) {
        console.log('🔍 AuthMiddleware - Sprawdzanie trasy', req.method, req.path);
        
        const token = req.cookies?.jwt;

        if (!token) {
            console.log('❌ Brak tokenu dla trasy:', req.path);
            throw new UnauthorizedException('Brak tokenu uwierzytelniającego');
        }

        try {
            const authorizingUser = await this.userAuthService.verifyToken(token);
            req['user'] = authorizingUser;
            console.log('✅ Token zweryfikowany dla trasy:', req.path, '- użytkownik:', authorizingUser.email);
            // Token jest prawidłowy - pozwól na dostęp do wszystkich widoków
            next();
        } catch (err) {
            console.log('❌ Nieprawidłowy token dla trasy:', req.path, 'Error:', err.message);
            throw new UnauthorizedException('Nieprawidłowy token');
        }
    }
}
