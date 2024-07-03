#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

struct Sing
{
    std::string name;
    std::string author;
    size_t year;
};

void AddSing(std::string NameFileWithSings)
{
    std::ofstream Sings(NameFileWithSings,std::ios::app);
    std::string buffer;

    std::cout << "Название песни:" << std::endl;
    getline(std::cin, buffer);
    Sings <<"Название: " << buffer << "\n";

    std::cout << "Автор песни:" << std::endl;
    getline(std::cin, buffer);
    Sings << "Автор: " << buffer << "\n";

    size_t year;
    std::cout << "Год выпуска песни:" << std::endl;
    std::cin >> year;   
    Sings << "Год выпуска: " << year << "\n";

    size_t key;
    do
    {
        std::cout << "1 - Ввести текст с клавиатуры" << std::endl
                << "2 - Ввести текст из файла" << std::endl;
        std::cin >> key;
        Sings << "Текст ";
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
                Sings << buffer << "\n";
            } 
        }
        else if (key == 2)
        {
            std::string pathToFile = "voidText.txt";
            std::cout << "Введите путь до файла:";
            std::cin.ignore(20,'\n');
            getline(std::cin, pathToFile);
            std::cout << pathToFile;
            std::ifstream in(pathToFile);
            while (getline(in, buffer))
            {
                std::cout << 1;
                Sings << buffer << "\n";
            }
            in.close();
        }
    } while (key != 1 && key != 2);
    Sings.close();
}
void DeleteTextSing(std::string NameFileWithSings, std::string NameSing, std::string AuthorSing)
{
    std::string buffer;
    std::ifstream in(NameFileWithSings);
    std::ofstream temp("temp.txt");
    std::string NameSingForSearch = "Название: " + NameSing;
    std::string AuthorSingForSearch = "Автор: " + AuthorSing;
    bool condition = false;
    while (getline(in, buffer))
    {
        if (!condition)
        {
            temp << buffer <<"\n";
        }
        else if (condition && buffer.find("Название: "))
        {
            condition = false;
        }
        if (buffer.find(NameSingForSearch))
        {
            getline(in, buffer);
            temp << buffer << "\n";
            if (buffer.find(AuthorSingForSearch))
            {
                condition = true;
            }
        }
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string NameFileWithSings = "Sings.txt";
    AddSing(NameFileWithSings);
    DeleteTextSing(NameFileWithSings, "123", "123");
}

