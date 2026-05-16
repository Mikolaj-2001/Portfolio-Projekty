import { IsString, IsNotEmpty, IsMongoId, IsNumber } from "class-validator"
import { Types } from "mongoose"

export class CreateAction {
    @IsMongoId()
    readonly userID!: Types.ObjectId

    @IsNotEmpty()
    @IsNumber()
    readonly option!: number

    @IsNotEmpty()
    @IsString()
    readonly description!: string

}