#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <variant>


struct car {
    std::string color;
    std::string model;
    std::variant<std::string, int> number;
};

bool IsNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void Initialization(car& car)
{
    std::cout << "Введите цвет автомобиля (в И.п) ";
    getline(std::cin, car.color);

    std::cout << "Введите модель автомобиля (в И.п) ";
    getline(std::cin, car.model);

    std::cout << "Введите номер автомобиля ";
    getline(std::cin, std::get<std::string>(car.number));

    if (IsNumber(std::get<std::string>(car.number)))
    {
        car.number = std::stoi(std::get<std::string>(car.number));
    }
}

void OutputCar(car const& car)
{
    std::cout << "Цвет автомобиля " << car.color << std::endl
            << "Модель автомобиля " << car.model << std::endl;
    if (car.number.index() == 0) 
    {   
        std::cout << "Номер автомобиля " << std::get<std::string>(car.number) << std::endl;
    }
    else
    {
        std::cout << "Номер автомобиля " << std::get<int>(car.number) << std::endl;
    }

    std::cout << std::endl;
}

void EditCar(car& car)
{
    std::cout << "Введите новый цвет автомобиля " << std::endl;
    getline(std::cin, car.color);

    std::cout << "Введите новую модель автомобиля " << std::endl;
    getline(std::cin, car.model);

    std::cout << "Введите новый номер автомобиля " << std::endl;
    getline(std::cin, std::get<std::string>(car.number));

    if (IsNumber(std::get<std::string>(car.number)))
    {
        car.number = std::stoi(std::get<std::string>(car.number));
    }
}

void OutputAllCar(std::vector<car> const& cars)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        OutputCar(cars[i]);
    }
}

int SearchByNumber(std::vector<car> cars, std::variant<std::string, int> number)
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

    std::vector<car> cars;
    cars.push_back({ "красный","1","hud" });
    cars.push_back({ "красный","278","dhfiog" });
    cars.push_back({ "красный","1",324 });
    cars.push_back({ "красный","2","ert" });
    cars.push_back({ "красный","3","rty" });
    cars.push_back({ "красный","1",421 });
    cars.push_back({ "красный","5","et" });
    cars.push_back({ "красный","1123",213 });
    cars.push_back({ "красный","1123","et" });
    cars.push_back({ "красный","1123",123 });

    OutputAllCar(cars);

    std::cout << SearchByNumber(cars, 123);

    return 0;
}
