#include <array>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>

// typename T, class T, int|char|std::size_t, и вроде бы всё
template<typename T, std::size_t n>
class array {
public:
    /* const T& getElement(std::size_t i) const { */
    /*     return data_[i]; */
    /* } */

    const T& operator[](std::size_t i) const {
        return data_[i];
    }

    /* T& getElement(std::size_t i) { */
    /*     return data_[i]; */
    /* } */

    T& operator[](std::size_t i) {
        return data_[i];
    }

private:
    T data_[n];
};

int main() {
    array<int, 10> a;

    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }

    std::cout << a[9] << std::endl;

    std::vector<int> v = {1,2,3,3,4,4,5};
    auto it = std::lower_bound(v.begin(), v.end(), 3);
    std::cout << std::distance(v.begin(), it) << std::endl;

    std::vector<int>::iterator jt = std::upper_bound(v.begin(), v.end(), 4);
    std::cout << *jt << std::endl;
    std::cout << jt - v.begin() << std::endl;
    /**
     * std::upper_bound
     * std::binary_search(v.begin(), v.end(), 3) // есть ли там 3
     * std::equal_range // std::make_pair(lower_bound, upper_bound)
     */

    return 0;
}
