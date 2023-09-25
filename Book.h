#include <string>
#include <iostream>

class Book {
    public:
        std::string author;
        std::string category;
        unsigned int numOfPages;
        bool onBookshelf;
        
        Book() {}

        Book(std::string a, std::string c, unsigned int num, bool status)
        {
            author = a;
            category = c;
            numOfPages = num;
            onBookshelf = status;
        }

        Book& operator=(const Book& b)
        {
            author = b.author;
            category = b.category;
            numOfPages = b.numOfPages;
            onBookshelf = b.onBookshelf;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Book& b) {
            std::string status = (b.onBookshelf) ? "on bookshelf" : "borrowed";
            os << b.author << "\t" << b.category << "\t" << b.numOfPages << "\t" << status;
            return os;
        }
};