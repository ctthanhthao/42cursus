#include <iostream>
#include <string>
#include "iter.hpp"

//
// ==========================
// PRINT FUNCTIONS
// ==========================

void printA(const class A &a); // forward declaration (used later)

//
// ==========================
// MODIFY FUNCTIONS
// ==========================
//

void increment(int &x)
{
    x++;
}

void addExcl(std::string &s)
{
    s += "!";
}

void doubleValue(class A &a);

//
// ==========================
// CUSTOM CLASS
// ==========================
//

class A
{
public:
    int value;
    A(int v) : value(v) {}
};

void printA(const A &a)
{
    std::cout << a.value << " ";
}

void doubleValue(A &a)
{
    a.value *= 2;
}

//
// ==========================
// MAIN TESTS
// ==========================
//

int main()
{
    std::cout << "===== INT TEST (print) =====" << std::endl;
    int arr1[] = {1, 2, 3, 4};
    iter(arr1, 4, print<int>);
    std::cout << std::endl;

    std::cout << "===== INT TEST (modify) =====" << std::endl;
    iter(arr1, 4, increment);
    iter(arr1, 4, print<int>);
    std::cout << std::endl;

    std::cout << "===== STRING TEST =====" << std::endl;
    std::string arr2[] = {"hello", "world", "42"};
    iter(arr2, 3, print<std::string>);
    std::cout << std::endl;

    std::cout << "===== STRING MODIFY TEST =====" << std::endl;
    iter(arr2, 3, addExcl);
    iter(arr2, 3, print<std::string>);
    std::cout << std::endl;

    std::cout << "===== CONST ARRAY TEST =====" << std::endl;
    const int arr3[] = {10, 20, 30};
    iter(arr3, 3, print<int>);
    std::cout << std::endl;

    std::cout << "===== TEMPLATE FUNCTION TEST =====" << std::endl;
    iter(arr1, 4, print<int>); // works with normal function
    std::cout << std::endl;

    std::cout << "===== CUSTOM CLASS TEST =====" << std::endl;
    A arr4[] = {A(1), A(2), A(3)};
    iter(arr4, 3, printA);
    std::cout << std::endl;

    std::cout << "===== CUSTOM CLASS MODIFY TEST =====" << std::endl;
    iter(arr4, 3, doubleValue);
    iter(arr4, 3, printA);
    std::cout << std::endl;

    std::cout << "===== EMPTY LENGTH TEST =====" << std::endl;
    iter(arr1, 0, print<int>);
    std::cout << std::endl;

    return 0;
}