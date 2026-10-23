#include <iostream>
#include <stdexcept>
#include <string>
#include "DynamicArray.h"

using namespace std;

int main() {
    cout << "--- Task 1 ---\n";
    DynamicArray<int> arr1(3);
    arr1.set(0, 10);
    arr1.set(1, -50);
    arr1.set(2, 100);
    arr1.print();

    try { arr1.set(5, 10); } catch (const out_of_range& e) { cout << e.what() << "\n"; }
    try { arr1.set(0, 150); } catch (const invalid_argument& e) { cout << e.what() << "\n"; }
    try { arr1.get(10); } catch (const out_of_range& e) { cout << e.what() << "\n"; }

    cout << "\n";

    cout << "--- Task 2 ---\n";
    DynamicArray<int> arr2(arr1);
    arr1.set(0, 99);
    cout << "arr1: "; arr1.print();
    cout << "arr2: "; arr2.print();

    cout << "\n";

    cout << "--- Task 3 ---\n";
    arr2.add(42);
    arr2.print();
    try { arr2.add(-200); } catch (const invalid_argument& e) { cout << e.what() << "\n"; }

    cout << "\n";

    cout << "--- Task 4 ---\n";
    DynamicArray<int> a(4), b(2), c(5);
    a.set(0, 10); a.set(1, 20); a.set(2, 30); a.set(3, 40);
    b.set(0, 5); b.set(1, 10);
    c.set(0, 2); c.set(1, 2); c.set(2, 2); c.set(3, 2); c.set(4, 99);

    cout << "a: "; a.print();
    cout << "b: "; b.print();
    cout << "c: "; c.print();

    a.add(b);
    cout << "a + b: "; a.print();

    a.subtract(c);
    cout << "a - c: "; a.print();

    cout << "\n=== Demonstrating all three exception types ===\n";

    cout << "\n1. Testing std::out_of_range:\n";
    try {
        DynamicArray<int> arr(3);
        arr.set(0, 10);
        arr.get(5);
    } catch (const out_of_range& e) {
        cout << "Caught out_of_range: " << e.what() << "\n";
    }

    cout << "\n2. Testing std::invalid_argument:\n";
    try {
        DynamicArray<int> arr(3);
        arr.set(0, 200);
    } catch (const invalid_argument& e) {
        cout << "Caught invalid_argument: " << e.what() << "\n";
    }

    cout << "\n3. Testing std::bad_alloc:\n";
    try {
        DynamicArray<int> huge(1000000000000000ULL); 
    } catch (const bad_alloc& e) {
        cout << "Caught bad_alloc: " << e.what() << "\n";
    }

    cout << "\n\n=== PART 3: TEMPLATES ===\n";

    cout << "\n1. Template class and data validation:\n";
    DynamicArray<int> intArr(3);
    intArr.set(0, 10);
    intArr.set(1, -50);
    intArr.set(2, 100);
    cout << "intArr: " << intArr << "\n";

    try {
        intArr.set(0, 150);
    } catch (const std::invalid_argument& e) {
        cout << "Caught expected exception for int: " << e.what() << "\n";
    }

    DynamicArray<double> doubleArr(2);
    doubleArr.set(0, 150.5);
    cout << "Double array: " << doubleArr << "\n";

    DynamicArray<string> strArr(2);
    strArr.set(0, "Hello"); 
    strArr.add("World");
    cout << "String array: " << strArr << "\n";

    cout << "\n2. Output operator <<:\n";
    cout << "Testing operator<< for int: " << intArr << "\n";

    cout << "\n3. Distance between arrays (Euclidean metric):\n";
    DynamicArray<double> arrA(3), arrB(3);
    arrA.set(0, 1.0); arrA.set(1, 2.0); arrA.set(2, 2.0);
    arrB.set(0, 4.0); arrB.set(1, 6.0); arrB.set(2, 5.0);
    
    cout << "arrA: " << arrA << "\n";
    cout << "arrB: " << arrB << "\n";
    cout << "Distance(arrA, arrB): " << arrA.distance(arrB) << "\n";

    try {
        DynamicArray<double> arrC(2);
        arrA.distance(arrC);
    } catch (const invalid_argument& e) {
        cout << "Caught invalid_argument: " << e.what() << "\n";
    }

    try {
        strArr.distance(strArr);
    } catch (const bad_typeid&) {
        cout << "Caught bad_typeid for string array\n";
    }

    cout << "\n\n=== PART 4: OPERATORS ===\n";

    cout << "\n1. Operator[]:\n";
    DynamicArray<int> arr_op(3);
    arr_op[0] = 10;
    arr_op[1] = 20;
    arr_op[2] = 30;
    cout << "arr_op: " << arr_op << "\n";
    
    try {
        arr_op[5] = 10;
    } catch (const out_of_range& e) {
        cout << "Caught out_of_range for index: " << e.what() << "\n";
    }

    try {
        arr_op[0] = 150;
    } catch (const invalid_argument& e) {
        cout << "Caught invalid_argument for value: " << e.what() << "\n";
    }

    cout << "\n2. Comparison operators:\n";
    DynamicArray<int> arr_op2(3);
    arr_op2[0] = 10; arr_op2[1] = 20; arr_op2[2] = 30;
    
    if (arr_op == arr_op2) cout << "arr_op == arr_op2\n";
    else cout << "arr_op != arr_op2\n";

    arr_op2[2] = 31;
    if (arr_op != arr_op2) cout << "arr_op != arr_op2 (after modification)\n";

    cout << "\n3. Compound arithmetic operators:\n";
    DynamicArray<double> arr_a(3), arr_b(3);
    arr_a[0] = 1.5; arr_a[1] = 2.5; arr_a[2] = 3.5;
    arr_b[0] = 0.5; arr_b[1] = 1.0; arr_b[2] = 1.5;

    arr_a += arr_b;
    cout << "arr_a += arr_b: " << arr_a << "\n";

    arr_a -= arr_b;
    cout << "arr_a -= arr_b: " << arr_a << "\n";

    arr_a += 2.0;
    cout << "arr_a += 2.0: " << arr_a << "\n";

    arr_a -= 1.0;
    cout << "arr_a -= 1.0: " << arr_a << "\n";

    cout << "\n4. Iterators (range-based for):\n";
    DynamicArray<int> arr_iter(5);
    for (int i = 0; i < 5; ++i) arr_iter[i] = (i + 1) * 10;
    
    cout << "arr_iter: ";
    for (const auto& x : arr_iter) {
        cout << x << " ";
    }
    cout << "\n";

    for (auto& x : arr_iter) {
        x += 1;
    }
    cout << "arr_iter after increment: " << arr_iter << "\n";

    return 0;
}
