#include <iostream>
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

    // Ошибки
    arr1.set(5, 10);
    arr1.set(0, 150);
    arr1.get(10);
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
    arr2.add(-200); // ошибка
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

    return 0;
}