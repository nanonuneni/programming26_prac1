#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"

using namespace std;

int main() {
    // === TASK 1 ===
    cout << "--- Task 1 ---\n";
    DynamicArray arr1(3);
    arr1.set(0, 10);
    arr1.set(1, -50);
    arr1.set(2, 100);
    arr1.print();

    // Ошибки (обёрнуты в try-catch, чтобы программа не упала)
    try { arr1.set(5, 10); } catch (const out_of_range& e) { cout << e.what() << "\n"; }
    try { arr1.set(0, 150); } catch (const invalid_argument& e) { cout << e.what() << "\n"; }
    try { arr1.get(10); } catch (const out_of_range& e) { cout << e.what() << "\n"; }
    cout << "\n";

    // === TASK 2 ===
    cout << "--- Task 2 ---\n";
    DynamicArray arr2(arr1);
    arr1.set(0, 99);
    cout << "arr1: "; arr1.print();
    cout << "arr2: "; arr2.print();
    cout << "\n";

    // === TASK 3 ===
    cout << "--- Task 3 ---\n";
    arr2.add(42);
    arr2.print();
    try { arr2.add(-200); } catch (const invalid_argument& e) { cout << e.what() << "\n"; } // ошибка
    cout << "\n";

    // === TASK 4 ===
    cout << "--- Task 4 ---\n";
    DynamicArray a(4), b(2), c(5);
    a.set(0, 10); a.set(1, 20); a.set(2, 30); a.set(3, 40);
    b.set(0, 5);  b.set(1, 10);
    c.set(0, 2);  c.set(1, 2);  c.set(2, 2);  c.set(3, 2);  c.set(4, 99);

    cout << "a: "; a.print();
    cout << "b: "; b.print();
    cout << "c: "; c.print();

    a.add(b);
    cout << "a + b: "; a.print();

    a.subtract(c);
    cout << "a - c: "; a.print();

    // === ЗАДАНИЕ 2: Демонстрация всех трёх типов исключений ===
    cout << "\n=== Demonstrating all three exception types ===\n";

    // 1. std::out_of_range
    cout << "\n1. Testing std::out_of_range:\n";
    try {
        DynamicArray arr(3);
        arr.set(0, 10);
        arr.get(5); // Выход за границы
    } catch (const out_of_range& e) {
        cout << "Caught out_of_range: " << e.what() << "\n";
    }

    // 2. std::invalid_argument
    cout << "\n2. Testing std::invalid_argument:\n";
    try {
        DynamicArray arr(3);
        arr.set(0, 200); // Значение вне диапазона
    } catch (const invalid_argument& e) {
        cout << "Caught invalid_argument: " << e.what() << "\n";
    }

    // 3. std::bad_alloc
    cout << "\n3. Testing std::bad_alloc:\n";
    try {
        DynamicArray huge(1000000000000000ULL); // Нереально большой размер
    } catch (const bad_alloc& e) {
        cout << "Caught bad_alloc: " << e.what() << "\n";
    }

    return 0;
}
