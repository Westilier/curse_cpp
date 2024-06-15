#include <iostream>
#include <string>
#include <vector>


struct book
{
    std::string name;
    std::string author;
    std::string publishingHouse;
    std::string genre;
};

void ShowBooks(std::vector<book> const& books)
{
    for (auto const& book : books)
    {
        std::cout << "Название книги: " << book.name
            << ", Режиссер: " << book.author
            << ", Издательство: " << book.publishingHouse
            << ", Жанр: " << book.genre << std::endl;
    }
    std::cout << std::endl;
}

void EditBook(book& book)
{
    std::cout << "Введите новое имя книги" << std::endl;
    getline(std::cin, book.name);
    std::cout << "Введите нового автора книги" << std::endl;
    getline(std::cin, book.author);
    std::cout << "Введите новое издательство книги" << std::endl;
    getline(std::cin, book.publishingHouse);
    std::cout << "Введите новый жанр книги" << std::endl;
    getline(std::cin, book.genre);
}

std::vector<book> GetBooksByAuthor(std::vector<book> const& books, std::string const& author)
{
    std::vector<book> result;

    for (auto const& book : books)
    {
        if (author == book.author)
        {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<book> GetBooksByAuthor(std::vector<book> const& books, std::string const& name)
{
    std::vector<book> result;

    for (auto const& book : books)
    {
        if (name == book.author)
        {
            result.push_back(book);
        }
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");

    std::vector<book> books;

    books.push_back({ "Фильм 1", "Режиссер 1"," Издательство 1", "Комедия" });
    books.push_back({ "Фильм 2", "Режиссер 2"," Издательство 2", "Боевик" });
    books.push_back({ "Фильм 3", "Режиссер 3"," Издательство 3", "Комедия" });
    books.push_back({ "Фильм 4", "Режиссер 4"," Издательство 4", "Боевик" });
    books.push_back({ "Фильм 5", "Режиссер 5"," Издательство 5", "Комедия" });
    books.push_back({ "Фильм 6", "Режиссер 6"," Издательство 6", "Боевик" });
    books.push_back({ "Фильм 7", "Режиссер 7"," Издательство 7", "Комедия" });
    books.push_back({ "Фильм 8", "Режиссер 8"," Издательство 8", "Боевик" });
    books.push_back({ "Фильм 9", "Режиссер 9"," Издательство 9", "Комедия" });
    books.push_back({ "Фильм 10", "Режиссер 10"," Издательство 10", "Боевик" });

    ShowBooks(books);
}