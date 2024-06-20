#include <iostream>
#include <string>
#include <vector>
#include <windows.h>


struct car {
    std::string color;
    std::string model;
    std::string number;
};

void Initialization(car& car)
{
    std::cout << "Введите цвет автомобиля (в И.п) ";
    getline(std::cin, car.color);
    std::cout << "Введите модель автомобиля (в И.п) ";
    getline(std::cin, car.model);
    std::cout << "Введите номер автомобиля ";
    getline(std::cin, car.number);
}

void OutputCar(car const& car)
{
    std::cout << "Цвет автомобиля " << car.color << std::endl
            << "Модель автомобиля " << car.model << std::endl
            << "Номер автомобиля" << car.number << std::endl;
}

void EditCar(car& car)
{
    std::cout << "Введите новый цвет автомобиля" << std::endl;
    getline(std::cin, car.color);
    std::cout << "Введите новую модель автомобиля" << std::endl;
    getline(std::cin, car.model);
    std::cout << "Введите новый номер автомобиля" << std::endl;
    getline(std::cin, car.number);
}

void OutputAllCar(std::vector<car> const& cars)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        OutputCar(cars[i]);
    }
}

int SearchByNumber(std::vector<car> cars, std::string number)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (cars[i].number == number)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    return 0;
}
