https://www.geeksforgeeks.org/c-operator-overloading-question-8/
#include<stdlib.h> 
#include<stdio.h> 
#include<iostream> 
using namespace std;

class Test {
    int x;
public:
    void* operator new(size_t size);
    void operator delete(void*);
    // when we call new, the new operator is called first to allocate memory to the object itself
    // then the constructor is called to create the object and its potential members' memory allocation 
    // and initialization
    Test(int i) {
        x = i;
        cout << "Constructor called \n";
    }
    // when we delete, the destructor is first called to deallocate memory allocated to its members 
    // then the delete operator is called to deallocate the memory of the object itself 
    ~Test() { cout << "Destructor called \n"; }
};

// overload the new operator on the Test class
// all it does is allocal a block of memory big enough to store the object pointed to 
// that is then after going to be created by the constructor
void* Test::operator new(size_t size)
{
    void* storage = malloc(size);
    cout << "new called \n";
    return storage;
}

// overload the delete operator on the Test class
// all it does is to free the memory that was allocated to the object pointed to
// after the destructor has been called 
void Test::operator delete(void* p)
{
    cout << "delete called \n";
    free(p);
}

int main()
{
    Test* m = new Test(5);
    delete m;
    return 0;
}

// Execution:
// new called
// Constructor called
// Destructor called
// delete called