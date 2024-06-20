#include <iostream>
#include <vector>
#include <string>
#include <windows.h>


union charact
{
    bool artiodactyl;
    int iq;
    double flightSpeed;
};

struct LivingEntity
{
    std::string type;
    charact charact;
    std::string color;
    double speed;
};

void Initialization(LivingEntity& entity)
{
    std::cout << "Введите тип(птица, скот, человек) ";
    std::cin >> entity.type;
    if (entity.type == "птица")
    {
        std::cout << "Введите скорость полёта ";
        std::cin >> entity.charact.flightSpeed;
    }
    else if (entity.type == "скот")
    {
        std::cout << "Оно парнокопытное? (Y/N) ";
        char answer;
        std::cin >> answer;
        if (answer == 'n' || answer == 'N')
        {
            entity.charact.artiodactyl = false;
        }
        if (answer == 'y' || answer == 'Y')
        {
            entity.charact.artiodactyl = true;
        }
    }
    else if (entity.type == "человек")
    {
        std::cout << "Введите IQ ";
        std::cin >> entity.charact.iq;
    }
    std::cout << "Введите скорость передвижения ";
    std::cin >> entity.speed;
    std::cout << "Введите цвет ";
    std::cin >> entity.color;
}

void OutputEntity(LivingEntity const& entity)
{
    if (entity.type == "птица")
    {
        std::cout << "Cкорость полёта " << entity.charact.flightSpeed << std::endl;
    }
    else if (entity.type == "скот")
    {
        std::cout << "Оно парнокопытное (Y/N) ";
        if (entity.charact.artiodactyl)
        {
            std::cout << "Оно парнокопытное" << std::endl;
        }
        else
        {
            std::cout << "Оно не парнокопытное" << std::endl;;
        }
    }
    else if (entity.type == "человек")
    {
        std::cout << "IQ " << entity.charact.iq << std::endl;
    }
    std::cout << "Cкорость передвижения " << entity.speed << std::endl;
    std::cout << "Цвет " << entity.color << std::endl;
};

void OutputAllEntity(std::vector<LivingEntity> const& entities)
{
    for (size_t i = 0; i < size(entities); ++i)
    {
        OutputEntity(entities[i]);
    }
}

void EditEntity(LivingEntity & entity)
{
    std::cout << "Введите новый тип(птица, скот, человек) ";
    std::cin >> entity.type;
    if (entity.type == "птица")
    {
        std::cout << "Введите новую скорость полёта ";
        std::cin >> entity.charact.flightSpeed;
    }
    else if (entity.type == "скот")
    {
        std::cout << "Оно парнокопытное? (Y/N) ";
        char answer;
        std::cin >> answer;
        if (answer == 'n' || answer == 'N')
        {
            entity.charact.artiodactyl = false;
        }
        if (answer == 'y' || answer == 'Y')
        {
            entity.charact.artiodactyl = true;
        }
    }
    else if (entity.type == "человек")
    {
        std::cout << "Введите новый IQ ";
        std::cin >> entity.charact.iq;
    }
    std::cout << "Введите новую скорость передвижения ";
    std::cin >> entity.speed;
    std::cout << "Введите новый цвет ";
    std::cin >> entity.color;
}

int SearchByCharact(std::vector<LivingEntity> entities, charact charact)
{
    for (size_t i = 0; i < entities.size(); ++i)
    {
        if ((entities[i].charact.iq == charact.iq)
            ||(entities[i].charact.flightSpeed == charact.flightSpeed)
            ||(entities[i].charact.artiodactyl == charact.artiodactyl))
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
}