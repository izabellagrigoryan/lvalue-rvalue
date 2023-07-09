// lvalue, rvalue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class A {

public:
    A()
    {
        std::cout << "Constructor" << std::endl;
    }
    A(const A& obj)
    {
        std::cout << "Copy const Constructor" << std::endl;
    }
    A(A& obj)
    {
        std::cout << "Copy Constructor" << std::endl;
    }
    A& operator=(const A& obj) {
        std::cout << "This is operator assignment" << std::endl;
        return *this;
    }

    ~A() {}

    void print(A obj, std::string s) {
        std::cout << "This is lvalue" << std::endl;
    }
    void print(A& obj) {
        std::cout << "This is lvalue reference" << std::endl;
    }
    void print(const A& obj) const
    {
        std::cout << "This is const lvalue reference" << std::endl;
    }
    void print(A&& obj)
    {
        std::cout << "This is rvalue reference" << std::endl;
    }
    void print(const A&& obj) const
    {
        std::cout << "This is const rvalue reference" << std::endl;
    }
};

int main() {

    A obj1;
    obj1.print(obj1, "a");
    obj1.print(obj1);

    const A obj2;
    obj1.print(obj2);

    obj1.print(A());
    obj2.print(A());

    return 0;
}