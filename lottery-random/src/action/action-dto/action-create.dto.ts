import { IsString, IsNotEmpty, IsMongoId, IsNumber } from "class-validator"
import { Types } from "mongoose"

export class CreateAction {
    @IsMongoId()
    readonly userID: Types.ObjectId

    @IsNotEmpty()
    @IsNumber()
    option: number

    @IsNotEmpty()
    @IsString()
    description: string

}