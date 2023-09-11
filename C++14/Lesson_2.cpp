/*
	Lesson2: Sample program for the C++14 features.
	Source Code Location: https://github.com/ViswanathanRamasamy/Cpp_Sample_Programs
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

//Index sequence
#include <iostream>
#include <utility>

// Helper template to print elements of an array
template <typename T, std::size_t... Indices>
void printArray(const T& arr, std::index_sequence<Indices...> y)  //void printArray(const T& arr, std::index_sequence<Indices...>) since y is not used
{
    ((std::cout << arr[Indices] << ' '), ...); // C++17 fold expression
    std::cout << std::endl;
}

int main() {
    constexpr int size = 5;
    int myArray[size] = {10, 20, 30, 40, 50};

    // Generate an integer sequence from 0 to size-1
    using IndexSequence = std::make_index_sequence<size>;

    // Call the printArray function with the generated sequence
    printArray(myArray, IndexSequence{});

    return 0;
}

//=====================================
alternate way without using c++ fold of 20

#include <iostream>
#include <utility>

// Base case: when the index is 0, print the last element and stop the recursion
template <typename T>
void printArrayHelper(const T& arr, size_t index) {
    std::cout << arr[index] << std::endl;
}

// Recursive template function to print array elements
template <typename T, std::size_t... Indices>
void printArray(const T& arr, std::index_sequence<Indices...>) {
    // Call the printArrayHelper function with the last index in the sequence
    (printArrayHelper(arr, Indices), ...);
}

int main() {
    constexpr int size = 5;
    int myArray[size] = {10, 20, 30, 40, 50};

    // Generate an integer sequence from 0 to size-1
    using IndexSequence = std::make_index_sequence<size>;

    // Call the printArray function with the generated sequence
    printArray(myArray, IndexSequence{});

    return 0;
}
==============================================
#include <iostream>
#include <utility>

template <std::size_t... Indices> //size_t hold any data types
void printIndices() {
    // Print the indices
    (std::cout << ... << Indices) << '\n'; //((std::cout << Indices << "   "),...);
}

int main() {
    // Calling the function with indices
    printIndices<0, 1, 2, 3>();

    return 0;
}
0123
============================
//how to remove the warning of unsed variable
//(,) 2 expression  inside the ()
//int dummy[] = {(std::cout << Indices << "   ")...};  will not work since we cannot convert output to int

#include <iostream>

template <int... Indices>
struct PrintIndicesHelper {
    static void print() {
        // Print the indices
        int dummy[] = {(std::cout << Indices << "   ", 0)...}; // 0 will be stored in the dummy for each elemet expansion
        static_cast<void>(dummy); // Prevents unused variable warning
    }
};

template <int... Indices>
void printIndices() {
    PrintIndicesHelper<Indices...>::print();
}

int main() {
    // Calling the function with indices
    printIndices<0, 1, 2, 3>();

    return 0;
}

================================================
#include <iostream>
#include <tuple>

int main() {
    auto myTuple = std::make_tuple(42, "Hello", 3.14);

    // Access elements of the tuple
    std::cout << std::get<0>(myTuple) << std::endl; // 42
    std::cout << std::get<1>(myTuple) << std::endl; // "Hello"
    std::cout << std::get<2>(myTuple) << std::endl; // 3.14

    return 0;
}
====================
How to extract the number from the string and number?
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input = "The number is 42";
    int number;

    std::istringstream stream(input);
    while (!stream.eof()) {
        if (stream >> number) {
            std::cout << "Extracted number: " << number << std::endl;
            break;
        }
		//If the >> operator fails to extract a number (e.g., because the next characters in the 
		//stream are not a valid integer), you clear the error state of the stream with stream.clear() and ignore the next character in the stream with 
		//stream.ignore(1)
        stream.clear();
        stream.ignore(1);
    }

    return 0;
}

================================

#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string input = "The number is 42 we"; //space is expected or word boundary is expected  
    int number;

    std::regex pattern("\\b\\d+\\b"); // Matches one or more digits surrounded by word boundaries
    std::smatch match;

    if (std::regex_search(input, match, pattern)) {
        number = std::stoi(match[0]);
        std::cout << "Extracted number: " << number << std::endl;
    }

    return 0;
}
====================
#include <iostream>
#include <string>

int main() {
    std::string input = "The number is (42)";
    int number;

    size_t start = input.find_first_of('(');
    size_t end = input.find_first_of(')', start);

    if (start != std::string::npos && end != std::string::npos) {
        std::string numberStr = input.substr(start + 1, end - start - 1);
        number = std::stoi(numberStr);
        std::cout << "Extracted number: " << number << std::endl;
    }

    return 0;
}
==================================
//Extract the number without the space:

#include <iostream>
#include <string>

int main() {
    std::string input = "viswa43viswa";
    std::string numberStr = "";

    for (char c : input) {
        if (std::isdigit(c)) {
            numberStr += c;
        }
    }

    if (!numberStr.empty()) {
        int number = std::stoi(numberStr);
        std::cout << "Extracted number: " << number << std::endl;
    } else {
        std::cout << "No number found in the string." << std::endl;
    }

    return 0;
}
=======================
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string name = "John";
    std::string location = "New York";

    std::cout << "Name: " << std::quoted(name) << std::endl; //"John"
    std::cout << "Location: " << std::quoted(location) << std::endl; //"New York"

    return 0;
}
========================
#include <iostream>

// Abstract class representing a Shape
class Shape {
public:
    // Constructor
    Shape(int sides) : numSides(sides) {}

    // Abstract (pure virtual) function for calculating area
    virtual double getArea() const = 0;

    // Concrete function for printing the number of sides
    void printSides() const {
        std::cout << "This shape has " << numSides << " sides." << std::endl;
    }

private:
    int numSides;
};

// Derived class Circle
class Circle : public Shape {
public:
    // Constructor
    Circle(double radius) : Shape(0), radius(radius) {}

    // Implementing the abstract function
    double getArea() const override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

// Interface-like structure using an abstract class
class Drawable {
public:
    // Abstract (pure virtual) function for drawing
    virtual void draw() const = 0;
};

// Class Square implementing the Drawable interface
class Square : public Drawable {
public:
    // Implementing the abstract function
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Circle circle(5.0);
    Square square;

    circle.printSides();
    std::cout << "Circle area: " << circle.getArea() << std::endl;

    square.draw();

    return 0;
}
=====================================
custom memory management in c++
#include <iostream>
#include <cstddef>

class CustomMemoryAllocator {
private:
    static const size_t block_size = 64; // Size of each memory block
    struct Block {
        Block* next;
        char data[block_size];
    };

    Block* free_blocks; // List of free memory blocks
    size_t allocated_count; // Number of allocated blocks

public:
    CustomMemoryAllocator() : free_blocks(nullptr), allocated_count(0) {}

    // Custom memory allocation function
    void* allocate(size_t size) {
        if (size > block_size) {
            // Handle large allocations differently if needed
            return nullptr;
        }

        if (!free_blocks) {
            // Allocate a new block when the list is empty
            Block* new_block = new Block;
            new_block->next = nullptr;
            free_blocks = new_block;
            allocated_count++;
        }

        // Pop a block from the free list
        Block* block = free_blocks;
        free_blocks = block->next;

        return block->data;
    }

    // Custom memory deallocation function
    void deallocate(void* ptr) {
        if (!ptr) return; // Handle null pointers

        // Push the block back to the free list
        Block* block = reinterpret_cast<Block*>(ptr)-1;
        block->next = free_blocks;
        free_blocks = block;
    }

    // Function to get the number of allocated blocks
    size_t getAllocatedCount() const {
        return allocated_count;
    }

    // Destructor to release allocated memory
    ~CustomMemoryAllocator() {
        while (free_blocks) {
            Block* next_block = free_blocks->next;
            delete free_blocks;
            free_blocks = next_block;
        }
    }
};

int main() {
    CustomMemoryAllocator allocator;

    // Allocate and deallocate memory
    void* ptr1 = allocator.allocate(32);
    void* ptr2 = allocator.allocate(48);

    allocator.deallocate(ptr1);
    allocator.deallocate(ptr2);

    std::cout << "Number of allocated blocks: " << allocator.getAllocatedCount() << std::endl;

    return 0;
}
===========================
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> array1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> array2 = {10, 20, 30, 40, 50};
    std::vector<int> result(array1.size());

    // Use std::transform to add elements from array1 and array2 and store the result in 'result'
    std::transform(array1.begin(), array1.end(), array2.begin(), result.begin(), [](int a, int b) {
        return a + b;
    });

    // Print the result
    std::cout << "Result: ";
    for (const int& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
// 11 22 33 44 55 6
=====================================