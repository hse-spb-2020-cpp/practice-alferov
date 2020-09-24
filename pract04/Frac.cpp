#include <iostream>
#include <cassert>

namespace Pract04 {

int gcd(int a, int b) {
    while (b != 0) {
        int k = a;
        a = b;
        b = k % b;
    }
    return a;
}

class Frac {
public:
    Frac() { }

    Frac(int num, int denom) {
        int g = gcd(num, denom);
        num_ = num / g;
        denom_ = denom / g;
    }

    Frac(int value) {
        num_ = value;
        denom_ = 1;
    }

    int getNum() const {
        return num_;
    }

    int getDenom() const {
        return denom_;
    }

    Frac& operator+=(const Frac& x) {
        int denom = denom_ * x.getDenom();
        int num = num_ * x.getDenom() + denom_ * x.getNum();
        int g = gcd(num, denom);
        denom /= g;
        num /= g;
        num_ = num;
        denom_ = denom;
        return *this;
    }

    Frac& operator++() {
        num_ += denom_;
        return *this;
    }

    Frac operator++(int) {
        Frac f = *this;
        ++(*this);
        return f;
    }

private:
    int num_, denom_;
};

bool operator<(const Frac& a, const Frac& b) {
    return a.getNum() * b.getDenom() < b.getNum() * a.getDenom();
}

bool operator>(const Frac& a, const Frac& b) {
    return a.getNum() * b.getDenom() > b.getNum() * a.getDenom();
}

bool operator<=(const Frac& a, const Frac& b) {
    return a.getNum() * b.getDenom() <= b.getNum() * a.getDenom();
}

bool operator>=(const Frac& a, const Frac& b) {
    return a.getNum() * b.getDenom() >= b.getNum() * a.getDenom();
}

bool operator==(const Frac& a, const Frac& b) {
    return a.getNum() * b.getDenom() == b.getNum() * a.getDenom();
}

bool operator!=(const Frac& a, const Frac& b) {
    return a.getNum() * b.getDenom() != b.getNum() * a.getDenom();
}

Frac operator+(Frac a, const Frac& b) {
    return a += b;
}

std::istream& operator>>(std::istream& is, Frac& f) {
    int n, d;
    char c;
    is >> n >> c >> d;
    f = Frac(n, d);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Frac& f) {
    os << f.getNum() << "/" << f.getDenom();
    return os;
}

}

#define TEST_CONSTRUCTOR
#define TEST_COMPARATOR
#define TEST_PLUS
// #define TEST_MINUS
#define TEST_INCREMENT
// #define TEST_DECREMENT
// #define TEST_ASSIGNMENT

// Тесты


#ifdef TEST_CONSTRUCTOR

void test_constructor() {
    Pract04::Frac(1,2);
    Pract04::Frac(1);
    std::cout << "TEST_CONSTRUCTOR passed" << std::endl;
}

#endif // TEST_CONSTRUCTOR

#ifdef TEST_COMPARATOR

void test_comparator() {
    assert(Pract04::Frac(1,2) < Pract04::Frac(1));
    assert(!(Pract04::Frac(1,2) > Pract04::Frac(1)));
    assert(!(Pract04::Frac(1,2) == Pract04::Frac(1)));
    assert(Pract04::Frac(1,2) != Pract04::Frac(1));
    assert(Pract04::Frac(1,2) <= Pract04::Frac(1));
    assert(!(Pract04::Frac(1,2) >= Pract04::Frac(1)));
    assert(4 == Pract04::Frac(4));
    std::cout << "TEST_COMPARATOR passed" << std::endl;
}

#endif // TEST_COMPARATOR

#ifdef TEST_PLUS

void test_plus() {
    Pract04::Frac x(1,2);
    x += Pract04::Frac(1,6);
    assert(x == Pract04::Frac(2,3));
    assert(Pract04::Frac(1,2) + Pract04::Frac(1,6) == Pract04::Frac(2,3));
    std::cout << "TEST_PLUS passed" << std::endl;
}

#endif // TEST_PLUS

#ifdef TEST_MINUS

void test_minus() {

    std::cout << "TEST_MINUS passed" << std::endl;
}

#endif // TEST_MINUS

#ifdef TEST_INCREMENT

void test_increment() {
    Pract04::Frac f(2, 4);
    assert((f++) == Pract04::Frac(1, 2));
    assert((++f) == Pract04::Frac(5, 2));
    assert(f == Pract04::Frac(5, 2));
    std::cout << "TEST_INCREMENT passed" << std::endl;
}

#endif // TEST_INCREMENT

#ifdef TEST_DECREMENT

void test_decrement() {

    std::cout << "TEST_DECREMENT passed" << std::endl;
}

#endif // TEST_DECREMENT

#ifdef TEST_ASSIGNMENT

void test_assignment() {

    std::cout << "TEST_ASSIGNMENT passed" << std::endl;
}

#endif // TEST_ASSIGNMENT

int main() {
#ifdef TEST_CONSTRUCTOR
    test_constructor();
#endif // TEST_CONSTRUCTOR

#ifdef TEST_COMPARATOR
    test_comparator();
#endif // TEST_COMPARATOR

#ifdef TEST_PLUS
    test_plus();
#endif // TEST_PLUS

#ifdef TEST_MINUS
    test_minus();
#endif // TEST_MINUS

#ifdef TEST_INCREMENT
    test_increment();
#endif // TEST_INCREMENT

#ifdef TEST_DECREMENT
    test_decrement();
#endif // TEST_DECREMENT

#ifdef TEST_ASSIGNMENT
    test_assignment();
#endif // TEST_ASSIGNMENT

    return 0;
}
