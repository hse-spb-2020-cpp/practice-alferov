#include <iostream>
#include <vector>

struct Vehicle {
    virtual ~Vehicle() {}
    virtual void startEngine() = 0;
};

struct Car : public Vehicle {
    virtual ~Car() override {}

    void startEngine() override {}
    void beep() {
        std::cout << "BEEP!" << std::endl;
    }
};

struct NuclearSubmarine : public Vehicle {
    virtual ~NuclearSubmarine() override {}

    void startEngine() override {}
    void fireNuclearMissiles() {
        std::cout << "10... 9... 8... 7..." << std::endl;
    }
};

// Является ли vector<Car> вектором Vehicle?
//    (нет, не является)
// Является ли Car[] массивом Vehicle?
//    (да, через указатель, и это очень плохо)
//    (пользуйтесь std::unique_ptr или std::array!)

void add(Vehicle *vehicles) {
    vehicles[0] = NuclearSubmarine();
}

int main() {
    Car cars[] = {Car()};
    add(cars);
    cars[0].beep();
}
