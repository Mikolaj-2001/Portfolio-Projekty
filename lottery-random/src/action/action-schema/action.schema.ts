import { Prop, Schema, SchemaFactory } from "@nestjs/mongoose"
import { Document, Types } from "mongoose"
import { IsString, IsNotEmpty, IsNumber, IsMongoId } from "class-validator"

@Schema({ timestamps: true })
export class Action extends Document {

    @Prop({ required: true })
    @IsMongoId()
    userID!: Types.ObjectId

    @Prop({ required: true })
    @IsNotEmpty()
    @IsNumber()
    option!: Number

    @Prop({ required: true })
    @IsNotEmpty()
    @IsString()
    description!: string

    @Prop({ type: Types.ObjectId, ref: "User" })
    userId!: Types.ObjectId/* userId! oznacza, że pole jest wymagane */
}

export const ActionSchema = SchemaFactory.createForClass(Action)
