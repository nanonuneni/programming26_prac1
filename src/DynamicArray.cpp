#include "DynamicArray.h"
#include <iostream>

using namespace std;

// === Вспомогательные методы ===
bool DynamicArray::isIndexValid(size_t index) const {
    return index < size;
}

bool DynamicArray::isValueValid(int value) const {
    return value >= -100 && value <= 100;
}

// === Задание 1 ===
DynamicArray::DynamicArray(size_t sz) : size(sz) {
    data = new int[size](); 
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::print() const {
    cout << "[ ";
    for (size_t i = 0; i < size; ++i) {
        cout << data[i] << (i + 1 < size ? ", " : "");
    }
    cout << " ] (size: " << size << ")\n";
}

void DynamicArray::set(size_t index, int value) {
    if (!isIndexValid(index)) {
        cerr << "set error: index is out of bounds.\n";
        return;
    }
    if (!isValueValid(value)) {
        cerr << "set error: value must be in range [-100, 100].\n";
        return;
    }
    data[index] = value;
}

int DynamicArray::get(size_t index) const {
    if (!isIndexValid(index)) {
        cerr << "get error: index is out of bounds.\n";
        return 0;
    }
    return data[index];
}

// === Задание 2 ===
DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size) {
    data = new int[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// === Задание 3 ===
void DynamicArray::add(int value) {
    if (!isValueValid(value)) {
        cerr << "add(int) error: value must be in [-100, 100].\n";
        return;
    }
    
    int* newData = new int[size + 1];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    size++;
}

// === Задание 4 ===
void DynamicArray::add(const DynamicArray& other) {
    for (size_t i = 0; i < size; ++i) {
        if (i < other.size) {
            data[i] += other.data[i];
        }
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (size_t i = 0; i < size; ++i) {
        if (i < other.size) {
            data[i] -= other.data[i];
        }
    }
}

size_t DynamicArray::getSize() const {
    return size;
}