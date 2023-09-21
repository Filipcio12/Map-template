#include <iostream>
#include "Map.h"

int main() {
    Map <size_t, std::string> db;
    db.add(1, "Filip");
    db.add(2, "Amelka");
    std::cout << db.find(2);
    return 0;
}