#include <fstream>
#include <iostream>

#include "unique_ptr.h"


struct FileHolder {
    std::fstream f;

    FileHolder(const std::string& s)
        : f(s)
    {}

    ~FileHolder() = default;
    FileHolder(const FileHolder&) = delete;
    FileHolder& operator=(const FileHolder&) = delete;
    FileHolder(FileHolder&&) = default;
    FileHolder& operator=(FileHolder&&) = default;

    int readInt() {
        int x;
        f >> x;
        return x;
    }
};

struct A {
    FileHolder* fh;
};

struct B {
    FileHolder* fh;
};

unique_ptr<FileHolder> createFileHolder() {
    return unique_ptr<FileHolder>(new FileHolder("input.txt"));
}

void foo(unique_ptr<FileHolder>&& ptr) {
    std::cout << ptr.get()->readInt() << " " << ptr.get()->readInt() << std::endl;
}

int main() {
    auto fh = createFileHolder();
    foo(std::move(fh));
    std::cout << fh.get()->readInt() << std::endl;
}
