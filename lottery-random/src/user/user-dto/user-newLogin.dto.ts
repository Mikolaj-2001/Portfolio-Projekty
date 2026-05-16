import { IsString, IsEmail, IsStrongPassword, IsNotEmpty } from "class-validator"

export class UserNewLogin {
    @IsNotEmpty()
    @IsString()
    userName!: string

    @IsNotEmpty()
    @IsString()
    @IsEmail()
    email!: string

    @IsNotEmpty()
    @IsString()
    @IsStrongPassword({
        minLength: 8,
        minSymbols: 2,
        minLowercase: 2,
        minUppercase: 1,
    })
    password!: string
}