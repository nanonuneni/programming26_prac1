#pragma once

#include <cstddef>
#include <iostream>

class DynamicArray {
private:
    int* data;
    size_t size;

    // Вспомогательные методы для проверок
    bool isIndexValid(size_t index) const;
    bool isValueValid(int value) const;

public:
    // === Задание 1 ===
    // Конструктор, получающий на вход размер массива
    explicit DynamicArray(size_t sz);

    // Деструктор
    ~DynamicArray();

    void print() const;

    // Сеттер с проверками:
    // 1)Индекс не выходит за границы массива
    // 2)Значение принадлежит промежутку [-100, 100]
    void set(size_t index, int value);

    // Геттер, проверяющий выход за границы массива
    int get(size_t index) const;

    // === Задание 2 ===
    // Конструктор копирования
    DynamicArray(const DynamicArray& other);

    // === Задание 3 ===
    // Добавление значения в конец массива с расширением размера
    // Это значение проверяется на принадлежность [-100, 100]
    void add(int value);

    // === Задание 4 ===
    // Поэлементное сложение
    void add(const DynamicArray& other);

    // Поэлементное вычитание
    void subtract(const DynamicArray& other);

    // Геттер для получения размера
    size_t getSize() const;
};