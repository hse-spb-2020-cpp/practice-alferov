#include <cassert>
#include <iostream>
#include <stdexcept>

struct Shape {
    virtual double getWidth() const = 0;
    virtual double getHeight() const = 0;
};

struct SymmetricShape : public Shape {
    virtual void setSize(double newSize) = 0;
};

struct AsymmmetricShape : public Shape {
    virtual void setSize(double newWidth, double newHeight) = 0;
};

struct Ellipse : public AsymmmetricShape {
    Ellipse(double w, double h)
        : width_(w), height_(h)
    {}

    virtual ~Ellipse() = default;

    virtual void setSize(double newWidth, double newHeight) override {
        width_ = newWidth;
        height_ = newHeight;
    }

    double getWidth() const override {
        return width_;
    }

    double getHeight() const override {
        return height_;
    }

private:
    double width_;
    double height_;
};

struct Circle : public SymmetricShape {
    Circle(double radius)
        : radius_(radius)
    {}

    virtual ~Circle() = default;

    double getWidth() const override {
        return 2 * radius_;
    }

    double getHeight() const override {
        return 2 * radius_;
    }

    void setSize(double newSize) override {
        radius_ = newSize / 2;
    }

private:
    double radius_;
};

/**
 * Проблема кругов и эллипсов:
 * 1. Можно ослабить контракт базового класса.
 *    (может продолбаться старый код, написанный под старый контракт)
 *    (ослабление контрактов может вести к ошибкам)
 * 2. Не наследоваться.
 *    (теряется совместимость по ссылкам)
 * 3. Поменять местами круги и эллипсы.
 *    (очень осторожно с совместимостью по ссылкам)
 *    (скорее всего, выбор этого решения означает, что изначальная иерархия была не оч)
 *
 * Принцип подстановки Лисков: во все места, где работа ведëтся с базовым классом, должно быть
 * возможно безопасно подставить наследника.
 */

void setSizeAndPrint(AsymmmetricShape& e) {
    e.setSize(2, 3);
    std::cout << e.getWidth() << " " << e.getHeight() << std::endl;
}

int main() {
    Circle circle(1);
    Ellipse ellipse(7, 9);

    /* setSizeAndPrint(circle); */
    setSizeAndPrint(ellipse);

    return 0;
}
