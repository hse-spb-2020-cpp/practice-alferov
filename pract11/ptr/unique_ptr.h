#pragma once

template<class T>
class unique_ptr {
public:
    unique_ptr(T* hold)
        : ptr(hold)
    {}

    ~unique_ptr() {
        delete ptr;
    }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
    unique_ptr(unique_ptr&&) = default;
    unique_ptr& operator=(unique_ptr&&) = default;

    T* get() {
        return ptr;
    }

    const T* get() const {
        return ptr;
    }

private:
    T* ptr;
};
