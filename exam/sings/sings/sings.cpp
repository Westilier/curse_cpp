#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <filesystem>

enum keys {
    Add = 1,
    EditText = 2,
    DeleteText = 3,
    SaveText = 4,
    PrintText = 5,
    PrintByAuthor = 6,
    PrintByWord = 7,
    Exit = 0
};

bool IsFileByPath(std::string const& path)
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

void InputTextInFile(std::string const& path)
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

std::string InputSingName(std::string const& Directory)
{
    std::string NameSing;
    std::cout << "Название песни:" << std::endl;
    getline(std::cin, NameSing);
    std::string pathToSing = Directory + "\\" + NameSing;

    return pathToSing;
}

std::string InputSingAuthor(std::string const& Directory)
{
    std::string AuthorSing;
    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, AuthorSing);
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;

    return AuthorSingForSearch;
}

void AddSing(std::string const& Directory)
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

void DeleteTextSing(std::string const& Directory)
{
    std::cin.ignore(20, '\n');

    std::string pathToSing = InputSingName(Directory);
    std::string AuthorSingForSearch = InputSingAuthor(Directory);

    for (const auto& entry : std::filesystem::directory_iterator(Directory))
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

void EditTextInFile(std::string const& Directory)
{
    std::cin.ignore(20, '\n');

    std::string pathToSing = InputSingName(Directory);
    std::string AuthorSingForSearch = InputSingAuthor(Directory);
    std::string tempPath = Directory + "\\" + "temp.txt";

    for (const auto& entry : std::filesystem::directory_iterator(Directory))
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

void SaveTextSingInFile(std::string const& Directory)
{
    std::cin.ignore(20, '\n');

    bool isFindingSing = false;
    bool isNotFindingFileForSaving = false;

    std::string pathToSing = InputSingName(Directory);
    std::string AuthorSingForSearch = InputSingAuthor(Directory);

    std::string pathToFileForSaving;
    std::cout << "Введите путь до файла" << std::endl;
    getline(std::cin, pathToFileForSaving);
    std::fstream FileForSaving(pathToFileForSaving);

    for (const auto& entry : std::filesystem::directory_iterator(Directory))
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

void PrintTextSing(std::string const& Directory)
{
    std::cin.ignore(20, '\n');
    bool isFindingSing = false;

    std::string pathToSing = InputSingName(Directory);
    std::string AuthorSingForSearch = InputSingAuthor(Directory);

    for (const auto& entry : std::filesystem::directory_iterator(Directory))
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

void PrintSingsByAuthor(std::string const& Directory)
{
    std::cin.ignore(20, '\n');
    bool isFindingSing = false;

    std::string AuthorSingForSearch = InputSingAuthor(Directory);

    for (const auto& entry : std::filesystem::directory_iterator(Directory))
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

void PrintSingsByWord(std::string const& Directory)
{
    std::cin.ignore(20, '\n');
    bool isFindingSing = false;

    std::string word;
    std::cout << "Слово из песни:" << std::endl;
    getline(std::cin, word);
    for (const auto& entry : std::filesystem::directory_iterator(Directory))
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
        switch (static_cast<keys>(key))
        {
            case Add:
            {
                AddSing(Directory);
                break;
            }
            case EditText:
            {
                EditTextInFile(Directory);
                break;
            }
            case DeleteText:
            {
                DeleteTextSing(Directory);
                break;
            }
            case SaveText:
            {
                SaveTextSingInFile(Directory);
                break;
            }
            case PrintText:
            {
                PrintTextSing(Directory);
                break;
            }
            case PrintByAuthor:
            {
                PrintSingsByAuthor(Directory);
                break;
            }
            case PrintByWord:
            {
                PrintSingsByWord(Directory);
                break;
            }
            case Exit:
            {
                return;
            }
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