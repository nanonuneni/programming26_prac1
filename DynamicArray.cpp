#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray(size_t sz) : size(sz) {
    data = new T[size];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : size(other.size) {
    data = new T[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
void DynamicArray<T>::print() const {
    std::cout << *this << "\n";
}

template <typename T>
T DynamicArray<T>::get(size_t index) const {
    if (index >= size) throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <typename T>
void DynamicArray<T>::set(size_t index, const T& value) {
    if (index >= size) throw std::out_of_range("Index out of bounds");
    if constexpr (std::is_integral_v<T>) {
        if (value < MIN || value > MAX) throw std::invalid_argument("Value must be in [-100, 100]");
    }
    data[index] = value;
}

template <typename T>
void DynamicArray<T>::add(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        if (value < MIN || value > MAX) throw std::invalid_argument("Value must be in [-100, 100]");
    }
    T* newData = new T[size + 1];
    for (size_t i = 0; i < size; ++i) newData[i] = data[i];
    newData[size] = value;
    delete[] data;
    data = newData;
    size++;
}

template <typename T>
void DynamicArray<T>::add(const DynamicArray& other) {
    if constexpr (std::is_arithmetic_v<T>) {
        size_t limit = size < other.size ? size : other.size;
        for (size_t i = 0; i < limit; ++i) data[i] += other.data[i];
    } else {
        throw std::bad_typeid();
    }
}

template <typename T>
void DynamicArray<T>::subtract(const DynamicArray& other) {
    if constexpr (std::is_arithmetic_v<T>) {
        size_t limit = size < other.size ? size : other.size;
        for (size_t i = 0; i < limit; ++i) data[i] -= other.data[i];
    } else {
        throw std::bad_typeid();
    }
}

template <typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
double DynamicArray<T>::distance(const DynamicArray& other) const {
    if (size != other.size) throw std::invalid_argument("Different sizes");
    if constexpr (!std::is_arithmetic_v<T>) {
        throw std::bad_typeid();
    } else {
        double sum = 0.0;
        for (size_t i = 0; i < size; ++i) {
            double d = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
            sum += d * d;
        }
        return std::sqrt(sum);
    }
}

template <typename T>
typename DynamicArray<T>::ElementProxy DynamicArray<T>::operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Index out of bounds");
    return ElementProxy(*this, index);
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if (index >= size) throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

template <typename T>
bool DynamicArray<T>::operator!=(const DynamicArray& other) const {
    return !(*this == other);
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator+=(const DynamicArray& other) {
    add(other);
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator-=(const DynamicArray& other) {
    subtract(other);
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator+=(const T& value) {
    if constexpr (std::is_arithmetic_v<T>) {
        for (size_t i = 0; i < size; ++i) {
            data[i] += value;
        }
    } else {
        throw std::bad_typeid();
    }
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator-=(const T& value) {
    if constexpr (std::is_arithmetic_v<T>) {
        for (size_t i = 0; i < size; ++i) {
            data[i] -= value;
        }
    } else {
        throw std::bad_typeid();
    }
    return *this;
}

template <typename T>
T* DynamicArray<T>::begin() {
    return data;
}

template <typename T>
T* DynamicArray<T>::end() {
    return data + size;
}

template <typename T>
const T* DynamicArray<T>::begin() const {
    return data;
}

template <typename T>
const T* DynamicArray<T>::end() const {
    return data + size;
}

template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<std::string>;