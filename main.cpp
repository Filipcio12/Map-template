#include <iostream>
#include "Map.h"
#include "Book.h"

int main() {
    Map <std::string, Book> db;
    db.add("Pan Tadeusz", Book("Adam Mickiewicz", "epopeja", 434, true));
    db.add("Kordian", Book("Juliusz Słowacki", "dramat", 132, false));
    std::cout << db;
    return 0;
}