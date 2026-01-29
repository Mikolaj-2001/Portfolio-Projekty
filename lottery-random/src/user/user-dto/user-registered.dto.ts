import { IsNotEmpty, IsString, IsNumber } from "class-validator"

export class UserRegistered {
    userName: string
    readonly email: string
    password: string

    @IsNotEmpty()
    @IsString()
    @IsNumber()
    readonly option: Number
}