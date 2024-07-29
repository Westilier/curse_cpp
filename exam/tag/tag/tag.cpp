#include <iostream>
#include <vector>
#include <conio.h>
#include <queue>
#include "windows.h"
#include <string>

#include <map>
#include <ctime>

using Matrix = std::vector<std::vector<size_t>>;
using Hash = std::string;

struct StateNode
{
    Matrix Map;
    size_t Zero_x;
    size_t Zero_y;
    size_t Depth;
    std::string StrRepresentation;
    double Value;
    std::vector<Matrix> WayToState;
};

void PrintMap(Matrix& map)
{
    size_t size = map.size();
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (map[i][j] < 10)
            {
                std::cout << "0" << map[i][j] << " ";
            }
            else
            {
                std::cout << map[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

size_t CounterMisplacedTiles(StateNode& node)
{
    size_t misplacedTiles = 0;
    size_t size = node.Map.size();
    size_t x = 1;
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (x == (size * size))
            {
                continue;
            }
            else if (!(node.Map[i][j] == x++))
            {
                misplacedTiles++;
            }
        }
    }
    return misplacedTiles;
}

Matrix CreateCorrectMap(size_t size)
{
    Matrix map(size, std::vector<size_t>(size));
    size_t x = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (x == (size * size))
            {
                map[i][j] = 0;
            }
            else
            {
                map[i][j] = x++;
            }
        }
    }
    return map;
}

bool IsMapSolved(StateNode& node)
{
    if (CounterMisplacedTiles(node) == 0)
    {
        return true;
    }
    return false;
}

std::string MatrixToString(Matrix& map)
{
    std::string strRepresentation;
    for (size_t i = 0; i < map.size(); ++i)
    {
        for (size_t j = 0; j < map.size(); ++j)
        {
            strRepresentation += std::to_string(map[i][j]);
        }
    }
    return strRepresentation;
}

double Heuristic(StateNode& node)
{
    //ManhattanDistance
    double  result = 0;
    int size = node.Map.size();
    Matrix goal = CreateCorrectMap(size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int elem = node.Map[i][j];
            if (elem == 0)
            {
                continue;
            }
            bool found = false;
            for (int h = 0; h < size; h++)
            {
                for (int k = 0; k < size; k++)
                {
                    if (goal[h][k] == (elem))
                    {
                        result += abs(h - i) + abs(j - k);
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    break;
                }
            }
        }
    }
    
    node.Value = result;
    return node.Value;
}

bool ValuesComparator(const StateNode& lhs, const StateNode& rhs)
{
    return lhs.Value > rhs.Value;
}

std::vector<StateNode> min_priority_queue;

void PrintWayToSolve(std::vector<Matrix>& way)
{
    size_t size = way.size();
    size_t i=0;
    while(i<size)
    {
        Sleep(1000);
        PrintMap(way[i]);
        std::cout << std::endl;
        i++;
    }
}

void ExpandNodes(StateNode& node,Hash& hash)
{
    size_t size = node.Map.size();
    size_t Depth = node.Depth;
    size_t zeroCol = node.Zero_x;
    size_t zeroRow = node.Zero_y;

    //Left
    if (zeroCol > 0)
    {
        Matrix newMap = node.Map;
        size_t temp = newMap[zeroRow][zeroCol - 1];
        newMap[zeroRow][zeroCol - 1] = newMap[zeroRow][zeroCol];
        newMap[zeroRow][zeroCol] = temp;
        StateNode newNode = { newMap , zeroCol - 1 , zeroRow , Depth + 1 , MatrixToString(newMap) };
        if (hash.find(newNode.StrRepresentation) == std::string::npos)
        {
            newNode.Value = Heuristic(node) + node.Depth;
            newNode.WayToState = node.WayToState;
            newNode.WayToState.push_back(node.Map);
            min_priority_queue.push_back(newNode);
            hash += newNode.StrRepresentation + ' ';
        }
    }

    // Right
    if (zeroCol < size - 1)
    {
        Matrix newMap = node.Map;
        size_t temp = newMap[zeroRow][zeroCol + 1];
        newMap[zeroRow][zeroCol + 1] = newMap[zeroRow][zeroCol];
        newMap[zeroRow][zeroCol] = temp;
        StateNode newNode = { newMap , zeroCol + 1 , zeroRow , Depth + 1 , MatrixToString(newMap) };
        if (hash.find(newNode.StrRepresentation) == std::string::npos)
        {
            newNode.Value = Heuristic(node) + node.Depth;
            newNode.WayToState = node.WayToState;
            newNode.WayToState.push_back(node.Map);
            min_priority_queue.push_back(newNode);
            hash+=newNode.StrRepresentation+' ';
        }
    }

    // Up
    if (zeroRow > 0)
    {
        Matrix newMap = node.Map;
        size_t temp = newMap[zeroRow - 1][zeroCol];
        newMap[zeroRow - 1][zeroCol] = newMap[zeroRow][zeroCol];
        newMap[zeroRow][zeroCol] = temp;
        StateNode newNode = { newMap , zeroCol , zeroRow - 1 , Depth + 1 , MatrixToString(newMap) };
        if (hash.find(newNode.StrRepresentation) == std::string::npos)
        {
            newNode.Value = Heuristic(node) + node.Depth;
            newNode.WayToState = node.WayToState;
            newNode.WayToState.push_back(node.Map);
            min_priority_queue.push_back(newNode);
            hash += newNode.StrRepresentation + ' ';
        }
    }

    // Down
    if (zeroRow < size - 1)
    {

        Matrix newMap = node.Map;
        size_t temp = newMap[zeroRow + 1][zeroCol];
        newMap[zeroRow + 1][zeroCol] = newMap[zeroRow][zeroCol];
        newMap[zeroRow][zeroCol] = temp;
        StateNode newNode = { newMap , zeroCol , zeroRow + 1, Depth + 1 , MatrixToString(newMap) };
        if (hash.find(newNode.StrRepresentation) == std::string::npos)
        {
            newNode.Value = Heuristic(node) + node.Depth;
            newNode.WayToState = node.WayToState;
            newNode.WayToState.push_back(node.Map);
            min_priority_queue.push_back(newNode);
            hash += newNode.StrRepresentation + ' ';
        }
    }
}

int ComputerColect(StateNode& node)
{
    Hash hash;
    min_priority_queue.push_back(node);
    node.StrRepresentation = MatrixToString(node.Map);
    hash += node.StrRepresentation + ' ';
    size_t count = 0;
    while (!min_priority_queue.empty())
    {
        count++;
        std::sort(begin(min_priority_queue), end(min_priority_queue), ValuesComparator);
        StateNode current = min_priority_queue.back();
        min_priority_queue.pop_back();
        if (IsMapSolved(current))
        {
            current.WayToState.push_back(current.Map);
            PrintWayToSolve(current.WayToState);
            return current.Depth;
        }
        else if (current.Depth < 40)
        {
            ExpandNodes(current, hash);
        }

    }

    return -1;
}

std::size_t CountInversions(Matrix& map)
{
    size_t inversions = 0;
    size_t size = map.size();
    std::string StrMap = MatrixToString(map);
    for (size_t i = 0; i < size; ++i)
    {
        int n = StrMap[i];
        for (size_t j = i + 1; j < size; ++j)
        {
            int m = StrMap[j];
            if (m > 0 && n > m)
            {
                inversions++;
            }
        }
    }
    return inversions;
}

void FindingZero(StateNode& node)
{
    size_t size = node.Map.size();
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (node.Map[i][j] == 0)
            {
                node.Zero_y = i;
                node.Zero_x = j;
                return;
            }
        }
    }
}

bool IsPossibleMap(StateNode& node)
{
    size_t size = node.Map.size();
    size_t inversions = CountInversions(node.Map);
    FindingZero(node);
    if ((inversions + size + node.Zero_y) % 2 == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void UpMove(StateNode& node) // ход вверх 
{
    if (node.Zero_y < node.Map.size() - 1)
    {
        size_t temp = node.Map[node.Zero_y + 1][node.Zero_x];
        node.Map[node.Zero_y + 1][node.Zero_x] = node.Map[node.Zero_y][node.Zero_x];
        node.Map[node.Zero_y][node.Zero_x] = temp;
    }
}

void DownMove(StateNode& node) // ход вниз 
{
    if (node.Zero_y > 0)
    {
        size_t temp = node.Map[node.Zero_y - 1][node.Zero_x];
        node.Map[node.Zero_y - 1][node.Zero_x] = node.Map[node.Zero_y][node.Zero_x];
        node.Map[node.Zero_y][node.Zero_x] = temp;
    }
}

void RightMove(StateNode& node) // ход вправо 
{
    if (node.Zero_x > 0)
    {
        size_t temp = node.Map[node.Zero_y][node.Zero_x - 1];
        node.Map[node.Zero_y][node.Zero_x - 1] = node.Map[node.Zero_y][node.Zero_x];
        node.Map[node.Zero_y][node.Zero_x] = temp;

    }
}

void LeftMove(StateNode& node) // ход влево 
{
    if (node.Zero_x < node.Map.size() - 1)
    {
        size_t temp = node.Map[node.Zero_y][node.Zero_x + 1];
        node.Map[node.Zero_y][node.Zero_x + 1] = node.Map[node.Zero_y][node.Zero_x];
        node.Map[node.Zero_y][node.Zero_x] = temp;
    }
}

bool GetDirection(StateNode& node)
{
    int move = static_cast<int> (_getch());
    if(move == 48)
    {
        return false;
    }
    move = static_cast<int> (_getch()); 

    switch (move)
    {
        case 72:
        {
            DownMove(node);
            break;
        }
        case 80:
        {
            UpMove(node);
            break;
        }
        case 77:
        {
            LeftMove(node);
            break;
        }
        case 75:
        {
            RightMove(node);
            break;
        }
        case 48:
        {
            return false;
        }
    }
    return true;
}

std::size_t HumanColect(StateNode& currentState)
{
    std::cout << "Если хотите закончить сборку введите 0" << std::endl;
    bool isGetDirection = false;
    size_t count = 0;
    do
    {
        count++;
        PrintMap(currentState.Map);
        isGetDirection = GetDirection(currentState);
    }
    while (!IsMapSolved(currentState) && isGetDirection);

    return count;
}

StateNode HumanMixMap(size_t& size)
{
    std::cout << "Если хотите закончить размешивание введите 0" << std::endl;
    StateNode node = { CreateCorrectMap(size) };
    bool isGetDirection = true;
    do
    {
        std::cout << std::endl;
        FindingZero(node);
        PrintMap(node.Map);
        isGetDirection = GetDirection(node);
    }
    while (isGetDirection);

    return node;
}

StateNode ComputerMixMap(size_t& size)
{
    srand(time(NULL));
    Matrix map(size, std::vector<size_t>(size));
    StateNode node = { map };
    do
    {
        size_t limit = size * size;
        std::vector<size_t> listNumbers;
        for (size_t i = 0; i < limit; ++i)
        {
            listNumbers.push_back(i);
        }
        size_t x;
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                x = rand() % limit--;
                node.Map[i][j] = listNumbers[x];
                listNumbers.erase(listNumbers.begin() + x);
            }
        }
    } while (!IsPossibleMap(node));
    return node;
}

void Menu()
{
    std::cout << "Выберите режим" << std::endl //size map
            << "1 - 3 на 3" << std::endl
            << "2 - 4 на 4" << std::endl
            << "3 - Выход" << std::endl;
    size_t key;
    std::cin >> key;
    size_t size;
    if (key == 1)
    {
        size = 3;
    }
    else if (key == 2)
    {
        size = 4;
    }
    else if (key == 3)
    {
        return ;
    }

    std::cout << "Выберите режим" << std::endl //mixxing
        << "1 - Ручное размешивание" << std::endl
        << "2 - Компьютерное размешивание" << std::endl
        << "3 - Выход" << std::endl;

    std::cin >> key;
    StateNode currentState;
    if (key == 1)
    {
        currentState = HumanMixMap(size);
    }
    else if (key == 2)
    {
        currentState = ComputerMixMap(size);
    }
    else if (key == 3)
    {
        return ;
    }

    if (size == 3)//Collecting
    {
        std::cout << "Выберите режим" << std::endl
            << "1 - Человек собирает" << std::endl
            << "2 - Компьютер собирает" << std::endl
            << "3 - Выход" << std::endl;

        std::cin >> key;
        if (key == 1)
        {
            size_t startTime = clock();
            size_t count = HumanColect(currentState);
            size_t EndTime = clock();
            std::cout << "Время: " << EndTime - startTime << " миллисекунд (1с = 1000млс)" << std::endl
                    << "Перестановки: " << count << std::endl;
        }
        else if (key == 2)
        {
            size_t startTime = clock();
            size_t count = ComputerColect(currentState);
            size_t EndTime = clock();
            std::cout << "Время: " << EndTime - startTime << " миллисекунд (1с = 1000млс)" << std::endl
                    << "Перестановки: " << count << std::endl;
        }
        else if (key == 3)
        {
            return ;
        }
    }
    else
    {
        std::cout << "Выберите режим" << std::endl
            << "1 - Человек собирает" << std::endl
            << "2 - Выход" << std::endl;

        std::cin >> key;
        if (key == 1)
        {
            size_t startTime = clock();
            size_t count = HumanColect(currentState);
            size_t EndTime = clock();
            std::cout << "Время: " << EndTime - startTime << " миллисекунд (1с = 1000млс)" << std::endl
                    << "Перестановки: " << count << std::endl;
        }
        else if (key == 3)
        {
            return ;
        }
    }
}




int main()
{
    setlocale(LC_ALL, "rus");
    Menu();
    return 0;
}