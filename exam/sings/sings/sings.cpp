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
            return true;
        }
    }
    return false;
}

void InputTextInFile(std::string path)
{
    std::fstream Sing(path,std::ios::app);
    std::string buffer;
    size_t key;
    Sing << "Текст";
    do
    {
        std::cout << "1 - Ввести текст с клавиатуры" << std::endl
            << "2 - Ввести текст из файла" << std::endl;
        std::cin >> key;
        if (key == 1)
        {
            std::cout << "Для окончания ввода введите 0" << std::endl;
            while (true)
            {
                getline(std::cin, buffer);
                if (buffer.find("0") != std::string::npos)
                {
                    buffer.erase(buffer.find("0"), 1);
                    Sing << buffer << std::endl;
                    break;
                }
                Sing << buffer << std::endl;
            }
        }
        else if (key == 2)
        {
            std::string pathToFile;
            std::cout << "Введите путь до файла:" << std::endl;
            std::cin.ignore(20, '\n');
            getline(std::cin, pathToFile);
            std::ifstream in(pathToFile);
            if (in.is_open())
            {
                while (getline(in, buffer))
                {
                    Sing << buffer << std::endl;
                }
                in.close();
            }
            else
            {
                std::cout << "Файл не был найден" << std::endl;
            }
        }
    } while (key != 1 && key != 2);
}

void AddSing(std::string Directory)
{
    std::cin.ignore(20, '\n');
    std::string buffer;
    
    std::cout << "Название песни:" << std::endl;
    getline(std::cin, buffer);
    std::string path = Directory + "\\" + buffer + ".txt";
    size_t i = 2;
    while (IsFileByPath(path))
    {
        path = Directory + "\\" + buffer + " (" + std::to_string(i) + ")" + ".txt";
        i++;
    }
    std::fstream Sing(path, std::ios::app);

    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, buffer);
    Sing << "Автор: " << buffer << std::endl;

    size_t year;
    std::cout << "Год выпуска песни:" << std::endl;
    std::cin >> year;   
    Sing << "Год выпуска: " << year << std::endl;

    Sing.close();
    InputTextInFile(path);
}

void DeleteTextSing(std::string Directory)
{
    std::cin.ignore(20, '\n');
    std::string NameSing;
    std::cout << "Название песни:" << std::endl;
    getline(std::cin, NameSing);
    std::string pathToSing = Directory + "\\" + NameSing;

    std::string AuthorSing;
    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, AuthorSing);
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;

    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path pathToFile = entry.path();
        std::string pathToFile_str = pathToFile.string();
        if (pathToFile_str.find(pathToSing) != std::string::npos)
        {
            std::ifstream Sing(pathToFile_str);

            std::string buffer;
            getline(Sing, buffer);
            if (buffer == AuthorSingForSearch)
            {
                Sing.close();
                remove(pathToFile_str.c_str());
                std::cout << "Песня успешна удалёна" << std::endl;
                return ;
            }
        }
    }
    std::cout << "Песня не была найдена" << std::endl;
}

void EditTextInFile(std::string Directory) 
{
    std::cin.ignore(20, '\n');
    std::string NameSing;
    std::cout << "Название песни:" << std::endl;
    getline(std::cin, NameSing);
    std::string pathToSing = Directory + "\\" + NameSing;

    std::string AuthorSing;
    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, AuthorSing);
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;

    std::string tempPath = Directory + "\\" + "temp.txt";

    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path pathToFile = entry.path();
        std::string pathToFile_str = pathToFile.string();
        if (pathToFile_str.find(pathToSing) != std::string::npos)
        {
            std::ifstream Sing(pathToFile_str);
            std::string buffer;
            getline(Sing, buffer);
            if (buffer == AuthorSingForSearch)
            {
                std::ofstream temp(tempPath);
                temp << buffer;
                while (getline(Sing, buffer))
                {
                    if (buffer != "Текст")
                    {
                        temp << buffer;
                    }
                    else
                    {
                        break;
                    }
                }
                Sing.close();
                InputTextInFile(tempPath);
                rename(tempPath.c_str(), pathToSing.c_str());
                return;
            }
            Sing.close();
        }
    }
    std::cout << "Песня не была найдена" << std::endl;
}

void SaveTextSingInFile(std::string Directory)
{
    std::cin.ignore(20, '\n');
    bool isFindingSing = false;
    bool isNotFindingFileForSaving = false;
    std::string NameSing;
    std::cout << "Название песни:" << std::endl;
    getline(std::cin, NameSing);
    std::string pathToSing = Directory + "\\" + NameSing;

    std::string AuthorSing;
    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, AuthorSing);
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;

    std::string pathToFileForSaving;
    std::cout << "Введите путь до файла" << std::endl;
    getline(std::cin, pathToFileForSaving);
    std::fstream FileForSaving(pathToFileForSaving);

    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path pathToFile = entry.path();
        std::string pathToFile_str = pathToFile.string();
        if (pathToFile_str.find(pathToSing) != std::string::npos)
        {
            std::ifstream Sing(pathToFile_str);
            std::string buffer;
            getline(Sing, buffer);
            if (buffer == AuthorSingForSearch)
            {
                while (getline(Sing, buffer))
                {
                    if (buffer == "Текст")
                    {
                        break;
                    }
                }

                if (FileForSaving.is_open())
                {
                    while (getline(Sing, buffer))
                    {
                        std::cout << buffer << std::endl;
                    }
                    Sing.close();
                    return;
                }
                else if (!isNotFindingFileForSaving)
                {
                    isNotFindingFileForSaving = true;
                    std::cout << "Не удалось найти файл по заданному пути" << std::endl;
                }
                isFindingSing = true;
            }
            Sing.close();
        }
    }
    if (!isFindingSing)
    {
        std::cout << "Песня не была найдена" << std::endl;
    }
}

void PrintTextSing(std::string Directory)
{
    std::cin.ignore(20, '\n');
    bool isFindingSing = false;

    std::string NameSing;
    std::cout << "Название песни:" << std::endl;
    getline(std::cin, NameSing);
    std::string pathToSing = Directory + "\\" + NameSing + ".txt";

    std::string AuthorSing;
    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, AuthorSing);
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;

    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path pathToFile = entry.path();
        std::string pathToFile_str = pathToFile.string();
        if (pathToFile_str.find(pathToSing) != std::string::npos)
        {
            std::ifstream Sing(pathToFile_str);
            std::string buffer;
            getline(Sing, buffer);
            if (buffer == AuthorSingForSearch)
            {

                while (getline(Sing, buffer))
                {
                    if (buffer == "Текст")
                    {
                        break;
                    }
                }
                std::cout << "Текст: " << std::endl;
                while (getline(Sing, buffer))
                {
                    std::cout << buffer << std::endl;
                }
                Sing.close();
                return;
            }
            Sing.close();
            isFindingSing = true;
        }
    }
    if (!isFindingSing)
    {
        std::cout << "Песня не была найдена" << std::endl;
    }
}

void PrintSingsByAuthor(std::string Directory)
{
    std::cin.ignore(20, '\n');
    bool isFindingSing = false;

    std::string AuthorSing;
    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, AuthorSing);
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;

    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path pathToFile = entry.path();
        std::string pathToFile_str = pathToFile.string();
        std::ifstream Sing(pathToFile_str);
        std::string buffer;
        getline(Sing, buffer);
        if (buffer == AuthorSingForSearch)
        {
            std::string findingSing = pathToFile.stem().string();

            if (findingSing.rfind('(') != std::string::npos)
            {
                size_t indexForDeleteAfter = findingSing.rfind('(') - 1;
                findingSing.erase(indexForDeleteAfter);
            }
            std::cout <<"Песня: " << findingSing << std::endl;
            Sing.close();
            isFindingSing = true;
        }
        Sing.close();
    }

    if (!isFindingSing)
    {
        std::cout << "Файлы по автору не были найдены" << std::endl;
    }
}

void PrintSingsByWord(std::string Directory)
{
    std::cin.ignore(20, '\n');
    bool isFindingSing = false;

    std::string word;
    std::cout << "Слово из песни:" << std::endl;
    getline(std::cin, word);
    for (const auto& entry : std::filesystem::directory_iterator("Sings"))
    {
        std::filesystem::path pathToFile = entry.path();
        std::string pathToFile_str = pathToFile.string();
        std::ifstream Sing(pathToFile_str);
        std::string buffer;
        getline(Sing, buffer);
        std::string author = buffer;
        getline(Sing, buffer);
        while (getline(Sing, buffer))
        {
            if (buffer.find(word) != std::string::npos)
            {
                std::string findingSing = pathToFile.stem().string();
                
                if (findingSing.rfind('(') != std::string::npos)
                {
                    size_t indexForDeleteAfter = findingSing.rfind('(') -1;
                    findingSing.erase(indexForDeleteAfter);
                }
                std::cout << "Песня: " << findingSing << " " << author << std::endl;
                Sing.close();
                isFindingSing = true;
            }
        }
        Sing.close();
    }
    if (!isFindingSing)
    {
        std::cout << "Текст с словом \"" << word << "\" не был найден" << std::endl;
    }
}

void Menu()
{
    std::string Directory = "Sings";

    while (true)
    {
        std::cout << std::endl
                << "1 - Добавить текст песни" << std::endl
                << "2 - Изменить текст песни" << std::endl
                << "3 - Удалить песню" << std::endl
                << "4 - Сохранить текст песни в файл" << std::endl
                << "5 - Отобразить текст на экран" << std::endl
                << "6 - Отобразить песни одного автора" << std::endl
                << "7 - Отобразить все песни с определенным словом" << std::endl
                << "0 - Выйти" << std::endl;
        size_t key;
        std::cin >> key;
        std::cout << std::endl;
        if (key == 1)
        {
            AddSing(Directory);
        }
        else if (key == 2)
        {
            EditTextInFile(Directory);
        }
        else if (key == 3)
        {
            DeleteTextSing(Directory);
        }
        else if (key == 4)
        {
            SaveTextSingInFile(Directory);
        }
        else if (key == 5)
        {
            PrintTextSing(Directory);
        }
        else if (key == 6)
        {
            PrintSingsByAuthor(Directory);
        }
        else if (key == 7)
        {
            PrintSingsByWord(Directory);
        }
        else if (key == 0)
        {
            break;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Menu();
    return 0;
}