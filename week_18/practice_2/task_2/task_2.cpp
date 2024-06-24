#include <iostream>


struct Point
{
    int x, y;
};

double DistanceBetweenPoints(Point point_1, Point point_2)
{
    double result;

    result = sqrt(pow(point_2.x - point_1.x, 2) + pow(point_2.y - point_1.y, 2));
    return result;
}

int main()
{
    Point A = { 10,34 };
    Point B = { 3,10 };

    std::cout << DistanceBetweenPoints(A, B);

    return 0;
}