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
                << ", Автор: " << book.author
                << ", Издательство: " << book.publishingHouse
                << ", Жанр: " << book.genre<<std::endl;
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

std::vector<book> GetBooksByName(std::vector<book> const& books, std::string const& name)
{
    std::vector<book> result;

    for (auto const& book : books)
    {
        if (name == book.name)
        {
            result.push_back(book);
        }
    }
    return result;
}

void SortByName(std::vector<book>& books)
{
    size_t count = books.size();

    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count - 1; j++) {
            if (books[j].name > books[j+1].name) {
                std::swap(books[j], books[j+1]);
            }
        }
    }
}

void SortByAuthor(std::vector<book>& books)
{
    size_t count = books.size();

    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count - 1; j++) {
            if (books[j].author > books[j + 1].author) {
                std::swap(books[j], books[j + 1]);
            }
        }
    }
}

void SortByPublishingHouse(std::vector<book>& books)
{
    size_t count = books.size();

    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < count - 1; j++) {
            if (books[j].publishingHouse > books[j + 1].publishingHouse) {
                std::swap(books[j], books[j + 1]);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    std::vector<book> books;

    books.push_back({ "Книга 1", "Автор 1"," Издательство 1", "Комедия"});
    books.push_back({ "Книга 2", "Автор 2"," Издательство 2", "Комедия" });
    books.push_back({ "Книга 3", "Автор 3"," Издательство 3", "Комедия"});
    books.push_back({ "Книга 4", "Автор 4"," Издательство 4", "Боевик" });
    books.push_back({ "Книга 5", "Автор 10"," Издательство 5", "Комедия"});
    books.push_back({ "Книга 6", "Автор 6"," Издательство 6", "Боевик" });
    books.push_back({ "Книга 7", "Автор 7"," Издательство 7", "Комедия"});
    books.push_back({ "Книга 8", "Автор 8"," Издательство 10", "Боевик" });
    books.push_back({ "Книга 9", "Автор 9"," Издательство 9", "Комедия"});
    books.push_back({ "Книга 10", "Автор 5"," Издательство 8", "Боевик"});

    ShowBooks(books);
    
    ShowBooks(GetBooksByAuthor(books, "Автор 10"));

    ShowBooks(GetBooksByName(books, "Книга 1"));

    SortByName(books);
    ShowBooks(books);

    SortByAuthor(books);
    ShowBooks(books);

    SortByPublishingHouse(books);
    ShowBooks(books);

    return 0;
}

