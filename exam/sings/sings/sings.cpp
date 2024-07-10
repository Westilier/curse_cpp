#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <filesystem>


bool IsFileByPath(std::string path)
{
    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path FileName = entry.path();
        if (FileName.string() == path)
        {
            std::cout << 10;
            return true;
        }
    }
    std::cout << 20;
    return false;
}

void InputTextInFile(std::string path)
{
    std::ofstream Sing(path,std::ios::app);
    std::string buffer;
    size_t key;
    do
    {
        std::cout << "1 - Ввести текст с клавиатуры" << std::endl
            << "2 - Ввести текст из файла" << std::endl;
        std::cin >> key;
        Sing << "Текст ";
        if (key == 1)
        {
            std::cout << "Для окончания ввода введите 0" << std::endl;
            while (true)
            {
                getline(std::cin, buffer);
                if (buffer == "0")
                {
                    break;
                }
                Sing << buffer << std::endl;
            }
        }
        else if (key == 2)
        {
            std::string pathToFile;
            std::cout << "Введите путь до файла:";
            std::cin.ignore(20, '\n');
            getline(std::cin, pathToFile);
            std::cout << pathToFile;
            std::ifstream in(pathToFile);
            while (getline(in, buffer))
            {
                Sing << buffer << std::endl;
            }
            in.close();
        }
    } while (key != 1 && key != 2);
}

void AddSing(std::string Directory)
{
    std::string buffer;
    
    std::cout << "Название песни:" << std::endl;
    getline(std::cin, buffer);
    std::string path = Directory + "\\" + buffer + ".txt";
    size_t i = 1;
    while (IsFileByPath(path))
    {
        path = Directory + "\\" + buffer + "(" + std::to_string(i) + ")" + ".txt";
        i++;
    }
    std::ofstream Sing(path);

    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, buffer);
    Sing << "Автор: " << buffer << std::endl;

    size_t year;
    std::cout << "Год выпуска песни:" << std::endl;
    std::cin >> year;   
    Sing << "Год выпуска: " << year << std::endl;

    InputTextInFile(path);
    
    Sing.close();
}

void DeleteTextSing(std::string Directory, std::string NameSing, std::string AuthorSing)
{
    std::string path = Directory + "\\" + NameSing;
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;

    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path pathToFile = entry.path();
        std::string pathToFile_str = pathToFile.string();
        if (pathToFile_str.find(path) != std::string::npos)
        {
            std::ifstream Sing(pathToFile_str);

            std::string buffer;
            getline(Sing, buffer);
            if (buffer == AuthorSingForSearch)
            {
                Sing.close();
                remove(pathToFile_str.c_str());
            }

        }
    }
}
void EditTextInFile(std::string Directory, std::string NameSing, std::string AuthorSing) 
{
    std::string tempPath = Directory + "\\" + "temp.txt";

    std::string filePath = Directory + "\\" + NameSing;
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;

    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path pathToFile = entry.path();
        std::string pathToFile_str = pathToFile.string();
        if (pathToFile_str.find(filePath) != std::string::npos)
        {
            std::ifstream Sing(pathToFile_str);
            std::ofstream temp(tempPath);

            std::string buffer;
            getline(Sing, buffer);
            if (buffer == AuthorSingForSearch)
            {
                temp << buffer;
                while (getline(Sing, buffer))
                {
                    temp << buffer;
                    if (buffer != "Текст")
                    {
                        break;
                    }
                }
                InputTextInFile(NameSing);
                Sing.close();
                rename(tempPath.c_str(), filePath.c_str());
            }
        }
    }
}
    

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string str = "Sings\\123.txt";
    std::string Directory = "Sings";
    AddSing(Directory);
    DeleteTextSing(Directory, "123", "123");
}






