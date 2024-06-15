#include <iostream>
#include <string>
#include <vector>

struct car {
    std::string length;
    std::string clearance;
    std::string engineCapacity;
    std::string powerEngine;
    std::string wheelDiameter;
    std::string color;
    std::string gearboxType;
};

void initialization(car& car)
{
    std::cout << "Введите длину автомобиля ";
    getline(std::cin, car.length);
    std::cout << "Введите клиренс автомобиля ";
    getline(std::cin, car.clearance);
    std::cout << "Введите объём двигателя автомобиля ";
    getline(std::cin, car.engineCapacity);
    std::cout << "Введите мощность двигателя автомобиля ";
    getline(std::cin, car.powerEngine);
    std::cout << "Введите диаметр колес автомобиля ";
    getline(std::cin, car.wheelDiameter);
    std::cout << "Введите цвет автомобиля (в И.п) ";
    getline(std::cin, car.color);
    std::cout << "Введите тип коробки передач автомобиля (первые 3 буквы) ";
    getline(std::cin, car.gearboxType);
}

void OutputCar(car car)
{
    std::cout << "Длину автомобиля " << car.length << std::endl;
    std::cout << "Клиренс автомобиля" << car.clearance << std::endl;
    std::cout << "Объём двигателя автомобиля " << car.engineCapacity << std::endl;
    std::cout << "Мощность двигателя автомобиля " << car.powerEngine << std::endl;
    std::cout << "Диаметр колес автомобиля " << car.wheelDiameter << std::endl;
    std::cout << "Цвет автомобиля " << car.color << std::endl;
    std::cout << "Тип коробки передач автомобиля " << car.gearboxType << std::endl;
}

int SearchByValue(std::vector<car> cars, std::string value)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (cars[i].length == value)
        {
            return i;
        }
        else if (cars[i].clearance == value)
        {
            return i;
        }
        else if (cars[i].engineCapacity == value)
        {
            return i;
        }
        else if (cars[i].powerEngine == value)
        {
            return i;
        }
        else if (cars[i].wheelDiameter == value)
        {
            return i;
        }
        else if (cars[i].color == value)
        {
            return i;
        }
        else if (cars[i].gearboxType == value)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    setlocale(LC_ALL, "rus");

}
