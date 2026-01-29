import { Injectable } from "@nestjs/common";
import { UserServiceService } from "../../user-service/user-service.service";
import { User } from "../user-schema/user.schema";

@Injectable()
export class LoginAuthService {
    constructor(private readonly userService: UserServiceService) { }

    async validateTheUser(email: string, password: string): Promise<User | null> {
        let attempts = 0;
        let user: User | null = null;

        do {
            user = await this.userService.findByEmail(email)

            if (user) {
                const decryptedPassword = (user as any).getDecryptedPassword();
                if (decryptedPassword === password) {
                    return user;
                }
            }
            attempts++;
        } while (attempts < 5)
        console.log("Osiągnięto maksymalną ilość prób.Spróbuj za 20 minut")
        return null
    }
}