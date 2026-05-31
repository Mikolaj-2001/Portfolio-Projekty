import { Injectable } from "@nestjs/common";
import { promises as fs, constants } from 'fs';
import * as path from 'path';

@Injectable()
export class FileConfiguring {

    // Tworzy folder w głównym katalogu projektu, nie w dist/
    /* Zamiast tworzyć folder w dist/, tworzymy go w głównym katalogu projektu i tym samym zapewniamy, że pliki użytkowników będą przechowywane w odpowiednim miejscu i nie zostaną usunięte podczas budowy projektu */
    private readonly folderPath = path.join(process.cwd(), 'userData');
    private readonly filePath = path.join(this.folderPath, 'userIndication.json');

    private async ensuringFolderExistence(): Promise<void> {
        try {
            await fs.access(this.folderPath, constants.F_OK/* Sprawdzanie czy plik/folder istnieje */)/* constants.F_OK sprawdza, czy plik/folder istnieje */
        } catch {
            await fs.mkdir(this.folderPath, { recursive: true }/* Utworzy ten folder,jeżeli nie jest obecny*/)/* recursive jest potrzebne, aby utworzyć wszystkie brakujące foldery w ścieżce */
        }
    }

    private async ensuringFileExistance(): Promise<void> {
        try {
            await fs.access(this.filePath, constants.F_OK)
        } catch {
            await fs.writeFile(this.filePath, JSON.stringify([], null, 2), 'utf-8')
        }
    }

    async createFile(input: { createUserDto: { userName: string; email: string; password: string }, asignActionDto: { option: number; description: string; userID?: any } }): Promise<string> {

        const { createUserDto, asignActionDto } = input

        const userIndicationFile = {
            userName: createUserDto.userName,
            email: createUserDto.email,
            password: createUserDto.password,
            action: {
                option: asignActionDto.option,
                description: asignActionDto.description,
                userID: asignActionDto.userID
            },
            createdAt: new Date().toISOString() // Dodanie daty utworzenia
        }

        console.log('📁 Dane użytkownika zapisane w folderze:', this.folderPath); // Debug: gdzie tworzymy plik

        await this.ensuringFolderExistence();
        await this.ensuringFileExistance()

        const detectingFilePath = await fs.readFile(this.filePath, 'utf-8')
        const usersArray = JSON.parse(detectingFilePath)

        // Zabezpieczenie przed duplikatami 
        //Metoda some sprawdza,czy jakikolwiek element w tablicy jest powtórzony
        const userExists = usersArray.some((existingUser: any) =>
            existingUser.email === createUserDto.email ||
            existingUser.userName === createUserDto.userName ||
            existingUser.action.userID === asignActionDto.userID
        );

        if (userExists) {
            console.log('⚠️ Użytkownik już istnieje w spisie użytkowników. Plik nie może zostać z tego względu zmodyfikowany');
            return this.filePath;
        }

        usersArray.push(userIndicationFile)

        await fs.writeFile(this.filePath, JSON.stringify(usersArray, null, 2), 'utf-8');

        return this.filePath;
    }

    async deleteFile(email: string, userID: string): Promise<string> {
        await this.ensuringFolderExistence();
        await this.ensuringFileExistance();

        const detectingFilePath = await fs.readFile(this.filePath, 'utf-8');
        const usersArray = JSON.parse(detectingFilePath);

        const updatedUsersArray = usersArray.filter((user: any) => user.email !== email && user.action.userID !== userID);

        if (updatedUsersArray.length === usersArray.length) {
            console.log('⚠️ Użytkownik nie istnieje w spisie użytkowników lub został już usunięty.');
            return this.filePath;
        }

        await fs.writeFile(this.filePath, JSON.stringify(updatedUsersArray, null, 2), 'utf-8');

        return this.filePath;
    }

    async detectAllUsers(): Promise<any[]> {
        await this.ensuringFileExistance();
        await this.ensuringFolderExistence();
        const fileContent = await fs.readFile(this.filePath, 'utf-8');
        return JSON.parse(fileContent)
    }
}