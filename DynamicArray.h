#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <cmath>
#include <string>

template <typename T>
class DynamicArray {
public:
    class ElementProxy {
    private:
        DynamicArray& arr;
        size_t idx;
    public:
        ElementProxy(DynamicArray& array, size_t index) : arr(array), idx(index) {}
        
        ElementProxy& operator=(const T& value) {
            arr.set(idx, value);
            return *this;
        }

        ElementProxy& operator=(const ElementProxy& other) {
            arr.set(idx, static_cast<T>(other));
            return *this;
        }

        operator T() const {
            return arr.get(idx);
        }
    };

private:
    T* data;
    size_t size;
    static constexpr int MIN = -100;
    static constexpr int MAX = 100;

public:
    explicit DynamicArray(size_t sz);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    
    void print() const;
    T get(size_t index) const;
    void set(size_t index, const T& value);
    void add(const T& value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
    size_t getSize() const;
    double distance(const DynamicArray& other) const;

    ElementProxy operator[](size_t index);
    const T& operator[](size_t index) const;

    bool operator==(const DynamicArray& other) const;
    bool operator!=(const DynamicArray& other) const;

    DynamicArray& operator+=(const DynamicArray& other);
    DynamicArray& operator-=(const DynamicArray& other);
    DynamicArray& operator+=(const T& value);
    DynamicArray& operator-=(const T& value);

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& arr);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
    os << "[ ";
    for (size_t i = 0; i < arr.size; ++i) {
        os << arr.data[i] << (i + 1 < arr.size ? ", " : "");
    }
    return os << " ] (size: " << arr.size << ")";
}