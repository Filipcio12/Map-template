#include <string>
#include <iostream>

class Employee {
    public:
        std::string name;
        std::string position;
        unsigned int age;
        
        Employee() {}

        Employee(std::string n, std::string pos, unsigned int a)
        {
            name = n;
            position = pos;
            age = a;
        }

        Employee& operator=(const Employee& e)
        {
            name = e.name;
            position = e.position;
            age = e.age;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Employee& e) {
            os << e.name << "\t" << e.position << "\t" << e.age;
            return os;
        }
};