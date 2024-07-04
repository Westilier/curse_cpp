#include <iostream>
#include <fstream>
#include <string>
#include "Windows.h"


void PrintAllEmployees(const char NameFile[])
{
    std::fstream employees(NameFile,std::ios::in);
    std::string employee;
    while (getline(employees, employee))
    {
        std::cout << employee << std::endl;
    }
    employees.close();
}

void EditDataEmployee(const char NameFile[], std::string& Surname, int& Age)
{

    std::string SurnameForSearch = "Фамилия: " + Surname;
    std::string AgeForSearch = "Возраст: " + std::to_string(Age);
    bool work = false;
    bool condition = false;
    const char tempFile[] = "temp.txt";
    std::fstream temp;
    temp.open(tempFile, std::ios::out);
    std::fstream employees(NameFile);
    std::string employee;
    while (getline(employees, employee))
    {
        if ((employee.find(SurnameForSearch) != std::string::npos) &&
            (employee.find(AgeForSearch) != std::string::npos))
        {
            std::cout << "Новая фамилия: " << std::endl;
            std::string Surname;
            std::cin.ignore(20, '\n');
            getline(std::cin, Surname);
            std::cout << "Новый возраст: " << std::endl;
            size_t Age;
            std::cin >> Age;
            std::cout << "О сотруднике: " << std::endl;
            std::string About;
            std::cin >> About;
            temp << "Фамилия: " << Surname << " Возраст: " << Age << std::endl
                    << "О сотруднике: " << About << std::endl;
            getline(employees, employee);
            work = true;
        }
        else 
        {
            temp << employee << std::endl;
        }
    }
    employees.close();
    temp.close();
    if (!work)
    {
        std::cout << "Данные не найдены" << std::endl;
        remove(tempFile);
    }
    else
    {
        remove(NameFile);
        rename(tempFile, NameFile);
        std::cout << "Данные успешно отредактированы" << std::endl;
    }
}
void DeleteDataEmployee(const char NameFile[], std::string& Surname, int& Age)
{
    std::string SurnameForSearch = "Фамилия: " + Surname;
    std::string AgeForSearch = "Возраст: " + std::to_string(Age);
    bool condition = false;
    bool work = false;
    const char tempFile[] = "temp.txt";
    std::fstream temp;
    temp.open(tempFile, std::ios::out);
    std::fstream employees(NameFile, std::ios::in);
    std::string employee;
    while (getline(employees, employee))
    {
        if (((employee.find(SurnameForSearch) != std::string::npos)&&
            (employee.find(AgeForSearch) != std::string::npos)) 
            || condition)
        {
            if (!condition)
            {
                condition = true;
            }
            else
            {
                condition = false;
            }
            work = true;
        }
        else
        {
            temp << employee << std::endl;
        }

    }
    employees.close();
    temp.close();
    if (!work)
    {
        std::cout << "Данные не найдены" << std::endl;
        remove(tempFile);
    } 
    else
    {
        remove(NameFile);
        rename(tempFile,NameFile);
        std::cout << "Данные успешно удалены" << std::endl;
    }
}

void InputNewDataEmployee(const char NameFile[])
{
    std::fstream employees(NameFile,std::ios::app);
    std::string Surname;
    std::cin.ignore(20, '\n');
    std::cout << "Фамилия: " << std::endl;
    getline(std::cin, Surname);
    size_t Age;
    std::cout << "Возраст: " << std::endl;
    std::cin >> Age;
    std::string About;
    std::cout << "О сотруднике: " << std::endl;
    std::cin >> About;
    employees << "Фамилия: " << Surname << " Возраст: " << Age << std::endl
            << "О сотруднике: " << About << std::endl;
    employees.close();
}

void PrintAllEmployeesByFirstSurnameLetter(const char NameFile[], std::string FirstSurnameLetter, bool SaveToFile = false, std::string  FileToSave = "")
{
    std::string FirstSurnameLetterForSearch = "Фамилия: " + FirstSurnameLetter;
    std::cout << FirstSurnameLetterForSearch;
    bool condition = false;
    std::fstream Save(FileToSave, std::ios::app);
    std::fstream employees(NameFile, std::ios::in);
    std::string employee;
    while (getline(employees, employee))
    {
        if ((employee.find("Фамилия: а") != std::string::npos) || condition)
        {
            std::cout << employee <<std::endl;
            if (SaveToFile)
            {
                Save << employee << std::endl;
            }
            if (!condition)
            {
                condition = true;
            }
            else
            {
                condition = false;
            }
        }
    }
    Save.close();
    employees.close();
}

void PrintAllEmployeesByAge(const char NameFile[], int& Age, bool SaveToFile = false, std::string  FileToSave = "")
{
    std::string AgeForSearch = "Возраст: " + std::to_string(Age);
    std::cout << AgeForSearch;
    bool condition = false;
    std::fstream Save(FileToSave, std::ios::app);
    std::fstream employees(NameFile, std::ios::in);
    std::string employee;
    while (getline(employees, employee))
    {
        if ((employee.find(AgeForSearch) != std::string::npos) || condition)
        {
            std::cout << employee << std::endl;
            if (SaveToFile)
            {
                Save << employee << std::endl;
            }
            if (!condition)
            {
                condition = true;
            }
            else
            {
                condition = false;
            }
        }
       
    }
    Save.close();
    employees.close();
}

void Menu()
{
    const char NameFile[] = "data.txt";
    bool SaveToFile;
    std::string FileToSave;
    int key;
    while (true)
    {
        std::cout << "Cохранять полученые данные в файл" << std::endl
            << "1 - да" << std::endl
            << "2 - нет" << std::endl;
        std::cin >> key;
        if (key == 1)
        {
            SaveToFile = true;
            std::cout << "Введите имя файла" << std::endl;
            std::cin.ignore(20, '\n');
            getline(std::cin, FileToSave);
            break;
        }
        else if (key == 2)
        {
            SaveToFile = false;
            break;
        }
    }
    while (true)
    {
        std::cout << "Выберите: " << std::endl
            << "1 - Ввод новых данных" << std::endl
            << "2 - Поиск сотрудников по первой букве фамилии" << std::endl
            << "3 - Поиск сотрудников по возрасту" << std::endl
            << "4 - Удаление данных сотрудника" << std::endl
            << "5 - Вывод всех сотрудников" << std::endl
            << "6 - Редактирование данных сотрудника" << std::endl
            << "0 - Выход" << std::endl;
        std::cin.ignore(20, '\n');
        std::cin >> key;
        if (key == 1)
        {
            InputNewDataEmployee(NameFile);
        }
        else if (key == 2)
        {
            std::cout << "Введите первую букву фамилии" << std::endl;
            std::string FirstSurnameLetter;
            std::cin.ignore(20, '\n');
            getline(std::cin, FirstSurnameLetter);
            if (SaveToFile)
            {
                PrintAllEmployeesByFirstSurnameLetter(NameFile, FirstSurnameLetter, SaveToFile, FileToSave);
            }
            else
            {
                PrintAllEmployeesByFirstSurnameLetter(NameFile, FirstSurnameLetter);
            }

        }
        else if (key == 3)
        {
            std::cout << "Введите возраст" << std::endl;
            int Age;
            std::cin >> Age;
            if (SaveToFile)
            {
                PrintAllEmployeesByAge(NameFile, Age, SaveToFile, FileToSave);
            }
            else
            {
                PrintAllEmployeesByAge(NameFile, Age);
            }
        }
        else if (key == 4)
        {
            std::cout << "Введите фамилию" << std::endl;
            std::cin.ignore(20, '\n');
            std::string Surname;
            getline(std::cin, Surname);
            std::cout << "Введите возраст" << std::endl;
            int Age;
            std::cin >> Age;
            DeleteDataEmployee(NameFile, Surname, Age);
        }
        else if (key == 5)
        {
            PrintAllEmployees(NameFile);
        }
        else if (key == 6)
        {
            std::cout << "Введите фамилию" << std::endl;
            std::cin.ignore(20, '\n');
            std::string Surname;
            getline(std::cin, Surname);
            std::cout << "Введите возраст" << std::endl;
            int Age;
            std::cin >> Age;
            EditDataEmployee(NameFile, Surname, Age);
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