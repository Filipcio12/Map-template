class Employee {
    public:
        std::string name;
        std::string position;
        unsigned int age;
        
        Employee(std::string n, std::string pos, unsigned int a)
        {
            name = n;
            position = pos;
            age = a;
        }

        friend std::ostream& operator<<(std::ostream& os, Employee& e) {
            os << e.name << "\t" << e.position << "\t" << e.age;
            return os;
        }
};