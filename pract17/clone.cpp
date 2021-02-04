#include <iostream>
#include <memory>

struct Employee {
private:
    std::string name_;

protected:
    Employee(const Employee&) {}

public:
    Employee(const std::string& name)
        : name_(name)
    {}

    const std::string& getName() const {
        return name_;
    }

    virtual ~Employee() = default;

    virtual std::unique_ptr<Employee> cloneEmployee() {
        return std::unique_ptr<Employee>{new Employee(name_)};
    }
};

struct Developer : public Employee {
    // еще поля

    Developer(const std::string& name)
        : Employee(name)
    {}

    ~Developer() override = default;

    virtual std::unique_ptr<Employee> cloneEmployee() override final {
        std::unique_ptr<Developer> clone = cloneDeveloper();
        Employee* ret = clone.release();
        return std::unique_ptr<Employee>{ret};
    }

    virtual std::unique_ptr<Developer> cloneDeveloper() {
        return std::unique_ptr<Developer>{new Developer(getName())};
    }
};

int main() {
    Developer d("vasya");
    auto c = d.cloneDeveloper();
}
