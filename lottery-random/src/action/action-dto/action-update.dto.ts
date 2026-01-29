import { PartialType } from "@nestjs/mapped-types";
import { CreateAction } from "./action-create.dto";

export class UpdateAction extends PartialType(CreateAction){
}//Ta klasa jest używana do aktualizacji istniejących akcji