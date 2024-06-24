#include <iostream>

struct rectangle
{
    int x, y;
    size_t width, height;
};

void MoveRectangle(rectangle& rectangle, int newX, int newY)
{
    rectangle.x = newX;
    rectangle.y = newY;
}

void ResizeRectangle(rectangle& rectangle, size_t newWidth, size_t newHeight)
{
    rectangle.width = newWidth;
    rectangle.height = newHeight;
}

void PrintRectangle(rectangle& rectangle)
{
    std::cout << "Координаты левого верхнего угла: " << rectangle.x << " " << rectangle.y << std::endl;
    std::cout << "Ширина " << rectangle.width << std::endl;
    std::cout << "Высота " << rectangle.height << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    rectangle MyRectangle = {1,2,10,12};

    PrintRectangle(MyRectangle);

    ResizeRectangle(MyRectangle, 123, 123);

    MoveRectangle(MyRectangle, 100, 100);

    PrintRectangle(MyRectangle);

    return 0;
}
