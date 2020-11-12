#include <cstddef>
#include <typeinfo>
#include <iostream>

template<class T, std::size_t N>
struct circular_buffer {
    circular_buffer() {}

    void push_back(const T&) & {}
    void pop_back() & {}
};

int main() {
    circular_buffer<int, 5> c;
    c.push_back(1);
    c.pop_back();

    circular_buffer<int, 5>().push_back(1);

/*     circular_buffer<int, 5>&& d = circular_buffer<int, 5>(); */
/*     d.push_back(1); */
}
