#include <string>
#include <memory>
#include <iostream>


struct Employee {
    std::string name;

    virtual ~Employee() = default;
};


struct Developer: public Employee {
    std::string language = "C++";

    ~Developer() override = default;
};


struct Manager: public Employee {
    std::string region;

    ~Manager() override = default;
};


void print_developer(Employee* e) {
    Developer* devptr = dynamic_cast<Developer*>(e);
    if (devptr != nullptr) {
        std::cout << "Developer" << std::endl;
        std::cout << devptr->language << std::endl;
    } else {
        std::cout << "Not developer" << std::endl;
    }
}

int main() {
    std::unique_ptr<Employee> dev{new Developer()};
    std::unique_ptr<Employee> manager{new Manager()};

    print_developer(dev.get());
    print_developer(manager.get());
}
