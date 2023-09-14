/*
	Lesson1: Sample program for the C++14 features.
	Source Code Location: https://github.com/ViswanathanRamasamy/Cpp_Sample_Programs
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

#include <iostream>
#include <memory>
//array of shared pointer
using namespace std;
//program to create the array of shared_ptr
int main1()
{
    int size = 5;
    shared_ptr <int> content[size];
    
    int index = 0;
    
    for (index = 0; index < size; index++)
    {
        content[index] = make_shared<int> (index);
    }

    for (index = 0; index < size; index++)
    {
        cout << *content[index] << " "; //0 1 2 3 4
    }
    return 0;
}
//==========================================================
#create the dynamic array 
int main2()
{
    int sizeOfArray = 5;
    auto ptr = make_unique<int[]>(sizeOfArray); // create the array of unique_ptr //std::unique_ptr<int[]> ptr = make_unique<int[]>(sizeOfArray)
    int index = 0;
    for (index = 0; index < sizeOfArray; index++)
    {
        ptr[index] = index*index;
    }
    
    for (index = 0; index < sizeOfArray; index++)
    {
        cout << ptr[index] << " ";
    }
    return 0;
}
==============================================================
#Agregate member initialization
#when we access the unitialized member variable of the structire the behaviour is undefined.
#in c++ agergatore , we initialize to the default value
using namespace std;
struct Employee
{
    int id {12};
    int age {12};
    double wage {120};
};

int main3()
{
    Employee joe ={ 1, 32 }; //or Employee joe{ 1, 32 };
    cout << joe.id << "  " << joe.age << "  " <<joe.wage <<endl; //1 32 120
    joe = { .id = joe.id, .age = 33, .wage = 66000.0 }; // Joe had a birthday and got a raise
    cout << joe.id << "  " << joe.age << "  " <<joe.wage <<endl; // 1 33 6600
    joe = { .age = 33, .wage = 66000.0 }; // note you cannot change the order. 
    //how ever we can leave the default element
    joe = { .age{ 33}, .wage{66000.0} };
    Employee joe1;
    cout << joe1.id << "  " << joe1.age << "  " <<joe1.wage <<endl; //12 12 120
    Employee joe2;
    cout << joe2.id << "  " << joe2.age << "  " <<joe2.wage <<endl; //12 12 120 
    //Employee robert ( 3, 45, 62500.0 ); //c++20. else it will search for the constructor
    return 0;
}
=============================================================
#binary literal ob or oB
#include <iostream>

int main4() {
    // Binary literal with 0b prefix
    int binaryValue = 0b101010;

    std::cout << "Binary Value: " << binaryValue << std::endl;

    return 0;
}
Binary Value: 42
======================================
Generic lamda:
auto add = [](auto a, auto b) { return a + b; };
==================
Return TYpe Detection:
auto add(int a, int b) {
    return a + b; // Return type is deduced as int
}
=============================
Digital Seperator:
int billion = 1'000'000'000;
===============
Variable Template:
template <typename T>
constexpr T pi = T(3.1415926535897932385);
============================

extended constexpression:
#include <iostream>

// C++14: Extended constexpr function
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int n = 5;
    constexpr int result = factorial(n);

    std::cout << "Factorial of " << n << " is " << result << std::endl;

    return 0;
}

===================================
User defined literal:
#include <iostream>

// User-defined literal for converting degrees to radians
constexpr long double operator"" _deg(long double deg) {
    return deg * 3.141592 / 180.0;
}

int main() {
    // Using the user-defined literal to convert degrees to radians
    long double degrees = 45.0;
    constexpr long double radians = 45.0_deg; // Using the "_deg" literal in a constexpr context

    std::cout << degrees << " degrees is approximately " << radians << " radians." << std::endl;

    return 0;
}
============================================
How to pass the unique_ptr to a function?
Moving Ownership:
#include <iostream>
#include <memory>

void processUniquePtr(std::unique_ptr<int> ptr) {
    // Do something with the unique_ptr
    std::cout << *ptr << std::endl;
}

int main() {
    std::unique_ptr<int> myUniquePtr = std::make_unique<int>(42);

    processUniquePtr(std::move(myUniquePtr)); // Ownership is transferred

    // Attempting to use myUniquePtr here would result in a compilation error
    // as ownership has been moved to processUniquePtr.

    return 0;
}
Pass by reference:

#include <iostream>
#include <memory>

void processUniquePtr(const std::unique_ptr<int>& ptr) {
    // Do something with the object managed by the unique_ptr
    std::cout << *ptr << std::endl;
}

int main() {
    std::unique_ptr<int> myUniquePtr = std::make_unique<int>(42);

    processUniquePtr(myUniquePtr); // No ownership transfer

    // You can still use myUniquePtr here after passing it by reference

    return 0;
}
=================================================================
vector of unique_ptr?
#include <iostream>
#include <vector>
#include <memory>

class MyClass {
public:
    MyClass(int val) : value(val) {}
    void print() { std::cout << "Value: " << value << std::endl; }
private:
    int value;
};

int main() {
    // Create a vector of unique_ptrs
    std::vector<std::unique_ptr<MyClass>> vec;

    // Add elements to the vector
    vec.push_back(std::make_unique<MyClass>(1));
    vec.push_back(std::make_unique<MyClass>(2));
    vec.push_back(std::make_unique<MyClass>(3));

    // Access and use elements in the vector
    for (const auto& ptr : vec) {
        ptr->print();
    }

    // Removing an element (destroying the object and erasing the pointer)
    vec.pop_back();

    // Access and use the modified vector
    for (const auto& ptr : vec) {
        ptr->print();
    }

    // The unique_ptrs and the objects they point to are automatically cleaned up when the vector goes out of scope

    return 0;
}
==========================================
git rebase -i <commit id>

git merge:
checkout 2 branches
git merge <provide the first branch name>
========================
if constexpt in c++14
#include <iostream>
#include <type_traits>

template <typename T>
void printTypeInfo(T value) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Type is integral." << std::endl;
    } else if constexpr (std::is_floating_point<T>::value) {
        std::cout << "Type is floating-point." << std::endl;
    } else {
        std::cout << "Type is neither integral nor floating-point." << std::endl;
    }
}

int main() {
    int intValue = 42;
    float floatValue = 3.14;
    std::string stringValue = "Hello";

    printTypeInfo(intValue);
    printTypeInfo(floatValue);
    printTypeInfo(stringValue);

    return 0;
}

Type is integral.
Type is floating-point.
Type is neither integral nor floating-point.

=============================================
C++14:
#include <iostream>
#include <thread>

void task(int id) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Task " << id << " is running iteration " << i << std::endl;
        std::this_thread::yield(); // Yield to other threads
    }
}

int main() {
    std::thread t1(task, 1);
    std::thread t2(task, 2);

    t1.join();
    t2.join();

    return 0;
}

===================================
std::thread::hardware_concurrency() is a static member function of the std::thread class
 available in the C++ Standard Library. It provides an estimate of the number of hardware cores that are supported by the execution environment.
 ==============
Resource initialized only Once:

#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag;

void initializeResource() {
    // Simulate resource initialization
    std::cout << "Resource initialized by thread " << std::this_thread::get_id() << std::endl;
}

void threadFunction() {
    std::call_once(flag, initializeResource);

    // Other work performed by the thread
    std::cout << "Thread " << std::this_thread::get_id() << " is doing some work." << std::endl;
}

int main() {
    std::thread threads[5];

    for (int i = 0; i < 5; ++i) {
        threads[i] = std::thread(threadFunction);
    }

    for (int i = 0; i < 5; ++i) {
        threads[i].join();
    }

    return 0;
}
==========================================
sleep until: wait till the particular time has reached?
Header file required?

#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Start of program." << std::endl;

    // Calculate a point in time 5 seconds from now
    auto wakeupTime = std::chrono::steady_clock::now() + std::chrono::seconds(5);

    // Sleep until the specified time is reached
    std::this_thread::sleep_until(wakeupTime);

    std::cout << "End of program." << std::endl;

    return 0;
}
================================================



