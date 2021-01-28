#include <string>
#include <memory>
#include <iostream>

struct EmployeeVisitor;

struct Employee {
    std::string name;

    virtual ~Employee() = default;

    virtual void accept(EmployeeVisitor* visitor) = 0;
};

struct Developer;
struct Manager;

struct EmployeeVisitor {
    virtual ~EmployeeVisitor() = default;

    virtual void visitDeveloper(Developer* dev) = 0;
    virtual void visitManager(Manager* man) = 0;
};

struct Developer: public Employee {
    std::string language = "C++";

    ~Developer() override = default;

    void accept(EmployeeVisitor* visitor) override {
        visitor->visitDeveloper(this);
    }
};

struct Manager: public Employee {
    std::string region;

    ~Manager() override = default;

    void accept(EmployeeVisitor* visitor) override {
        visitor->visitManager(this);
    }
};

struct PrintingEmployeeVisitor: public EmployeeVisitor {
    ~PrintingEmployeeVisitor() override = default;

    void visitDeveloper(Developer* dev) override {
        std::cout << "Developer " << dev->language << std::endl;
    }

    void visitManager(Manager* man) override {
        std::cout << "Manager " << std::endl;
    }
};

int main() {
    std::unique_ptr<Employee> dev{new Developer()};
    std::unique_ptr<Employee> manager{new Manager()};

    PrintingEmployeeVisitor visitor;
    dev->accept(&visitor);
    manager->accept(&visitor);
}
