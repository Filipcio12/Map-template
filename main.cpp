#include <iostream>
#include "Map.h"

int main() {
    Map <size_t, std::string> db;
    db.add(1, "Filip");
    db.add(2, "Amelka");
    db.add(3, "Jakub");
    return 0;
}