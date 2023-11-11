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
=============================================
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printArrayHelper(const T& arr, size_t currentIndex) {
	if (currentIndex >= arr.size()) {
		return;
	}

	std::cout << arr[currentIndex] << " ";
	printArrayHelper(arr, currentIndex + 1);
}

template <typename T>
void printArray(const T& arr) {
	printArrayHelper(arr, 0);
}

int main() {
	std::vector<int> myArray = { 1, 2, 3, 4, 5 };
	printArray(myArray);
	return 0;
}
//1 2 3 4 5
==============================================
#include <iostream>
#include <utility>

template <std::size_t... Indices> //size_t hold any data types
void printIndices() {
    // Print the indices
    (std::cout << ... << Indices) << "hi" << '\n'; //((std::cout << Indices << "   "),...);
}

int main() {
    // Calling the function with indices
    printIndices<0, 1, 2, 3>();

    return 0;
}
0123 hi // we cannot add spaces between thenumber hence we prefer the second
============================
// Define a function template with a parameter pack
template <typename... Types>
void printIndices(Types... indices) {
    // Print the indices
    ((std::cout << indices << " "), ...); // Using fold expression
    std::cout << '\n';
}

int main() {
    // Calling the function with indices
    printIndices<std::size_t>(0, 1, 2, 3); //size_t is not must

    return 0;
}
=====================================
//how to remove the warning of unsed variable
//(,) 2 expression  inside the ()
//int dummy[] = {(std::cout << Indices << "   ")...};  will not work since we cannot convert output to int

#include <iostream>

template <int... Indices> //int can be replaced with size_t
struct PrintIndicesHelper {
    static void print() {
        // Print the indices 
        int dummy[] = {(std::cout << Indices << "   ", 0)...}; // 0 will be stored in the dummy for each elemet expansion
        static_cast<void>(dummy); // Prevents unused variable warning
    }
};

template <int... Indices>
void printIndices() {
    PrintIndicesHelper<Indices...>::print(); //class :: static function
}

int main() {
    // Calling the function with indices
    printIndices<0, 1, 2, 3>();

    return 0;
}

================================================
// tuple with auto 
#include <iostream>
#include <tuple>

int main() {
    auto myTuple = std::make_tuple(42, "Hello", 3.14);
	//or auto myTuple = std::make_tuple<int,std::string,double>(42, "Hello", 3.14);

    // Access elements of the tuple
    std::cout << std::get<0>(myTuple) << std::endl; // 42
    std::cout << std::get<1>(myTuple) << std::endl; // "Hello"
    std::cout << std::get<2>(myTuple) << std::endl; // 3.14

    return 0;
}
====================
How to extract the number from the string and number without using regex?
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
======================================
regex to extract the number and add to the vector?
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
	std::string input = "The number is 42 we 42";
	std::vector<int> numbers;  // Store extracted numbers
	int number;

	std::regex pattern("\\b\\d+\\b");
	std::smatch match;

	while (std::regex_search(input, match, pattern)) {
		number = std::stoi(match[0]);
		numbers.push_back(number);  // Store the extracted number
		input = match.suffix().str();  // Update input to search for the next match
		std::cout << input; // we 42
	}

	for (int extractedNumber : numbers) {
		std::cout << "Extracted number: " << extractedNumber << std::endl;
	}

	return 0;
}

====================
find the number from hi(42)
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
string to print "viswa"

#include <iostream>
#include <iomanip> //setw, setfill or quoted
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
difference between the 2 array address?
#include <iostream>
#include <cstddef>

int main() {
	int array[] = { 10, 20, 30, 40, 50 };

	// Calculate the difference between two pointers
	ptrdiff_t pointerDifference = &array[2] - &array[0]; // 2 int also do the same job but 

	// Display the result
	std::cout << "The difference between array[2] and array[0] is: " << pointerDifference << " elements." << std::endl;

	return 0;
}
====================================================
#include <iostream>
#include <cstddef>
struct MyStruct {
	int value;
	char ch;
};
int main() {
	size_t offset = offsetof(MyStruct, ch);
	std::cout << offset;

	return 0;
}
=======================================================
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT)) //16

typedef struct PodTag
{
	int i;
	double d;
	char c;
} PodType;

int main()
{
	//cout << sizeof(int*);
	// cout << sizeof(double);
	cout << OFFSETOF(PodType, c);

	return 0;
}
=======================================================
custom memory management in c++
#include <iostream>
#include <cstddef>//sizeof

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
add the elements of the vector and update in new vector?
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> array1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> array2 = {10, 20, 30, 40, 50}; //you cannot use like std::vector<int> array2(10, 20, 30, 40, 50);
	//std::vector<int> array2{array1};
    std::vector<int> result(array1.size()); //vector should be small one size or equal size. greater than size is not working 

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
/* Note
yeild
fold requires the utility library
template argument can be from 
print<1,2,3,4,5>()//need,'t be in the argument list
==========================
Abstraction is the method of hiding the unwanted information.
We can implement abstraction using abstract class and interfaces.

encapsulation:
Whereas encapsulation is a method to hide the data in a single entity or unit along with a method to protect information from outside.
Whereas encapsulation can be implemented using by access modifier i.e. private, protected and public.
// Abstract class
class Animal {
public:
virtual void makeSound() = 0;

protected:
virtual void internalMakeSound() = 0;
};

// Concrete class
class Dog : public Animal {
public:
void makeSound() override {
cout << "Woof!" << endl;
}

protected:
void internalMakeSound() override {
cout << "Woof woof!" << endl;
}
};

// Concrete class
class Cat : public Animal {
public:
void makeSound() override {
cout << "Meow!" << endl;
}

protected:
void internalMakeSound() override {
cout << "Meow meow!" << endl;
}
};

int main() {
Dog* dog = new Dog();
dog->makeSound();

Cat* cat = new Cat();
cat->makeSound();
}
In this example, the Animal class is an abstract class that provides a common interface for all animals. 
The Dog and Cat classes are concrete classes that inherit from the Animal class. They both have a makeSound() method, but they implement it in different ways.
The makeSound() method is a public method, which means that it is accessible to all. The internalMakeSound() method is a protected method, which means 
that it is only accessible to the Animal class and its subclasses.
=====================================
myStack.size(); // to find the number of element in stack
stack1 == stack2: check the same element in same order
stack1 < stack2 : stack1 is subset of stack2?

paranthesis check in compiler:
#include <iostream>
#include <stack>
#include <string>
bool isMatchingPair(char opening, char closing);
bool areBracketsBalanced(const std::string& expression) {
std::stack<char> stack;

for (char ch : expression) {
if (ch == '(' || ch == '{' || ch == '[') {
stack.push(ch);
} else if (ch == ')' || ch == '}' || ch == ']') {
if (stack.empty() || !isMatchingPair(stack.top(), ch)) {
return false;  // Unbalanced brackets
} else {
stack.pop();
}
}
}

return stack.empty();  // True if all brackets are balanced
}

bool isMatchingPair(char opening, char closing) {
return (opening == '(' && closing == ')') ||
(opening == '{' && closing == '}') ||
(opening == '[' && closing == ']');
}

int main() {
std::string expression;

// Input an expression with brackets
std::cout << "Enter an expression with brackets: ";
std::cin >> expression;

if (areBracketsBalanced(expression)) {
std::cout << "Brackets are balanced." << std::endl;
} else {
std::cout << "Brackets are unbalanced." << std::endl;
}

return 0;
}
=====================================


uint8_t out_data[16] = { 0 };
uart_out["uart"]["data"] = std::string(reinterpret_cast<char*>(out_data)); //static cast will work only for same data ponter
#include <iostream>
#include <string>
#include <cstdint> //int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, and uint64_t

========================================================
// Convert the uint8_t array to a std::string
int main() {
uint8_t out_data[16] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0, 0, 0 };

std::string str(reinterpret_cast<char*>(out_data)); //reinterpret_cast is not must
//static_cast is converting the value. reinterpret_cast convert the pointer. if you cnage the reinterpret_cast to static it will give error.
// Print the resulting std::string
std::cout << "String: " << str << std::endl;

return 0;
}
===================================
allowed to const char * and string const
const char  * json_config_out = "{\"config\":{\"gpio\":[{\"id\":0,\"gpioindex\":0,\"direction\":\"out\"}]}}";
json_config_out = "{\"config\":{\"gpio\":[{\"id\":1,\"gpioindex\":1,\"direction\":\"out\"}]}}";
==========================
converting char to string? and check the @# and #@ are oresent?
#include <iostream>
#include <string>

int main() {
const char charArray[] = "This is a sample string containing #@ and @# substrings."; //const 
//const char charArray[] = {"This is a sample string containing #@ and @# substrings."};

// Create a std::string from the character array
std::string str(charArray); //string non const

// Check if the substrings #@ and @# are present
bool containsSubstring1 = (str.find("#@") != std::string::npos);
bool containsSubstring2 = (str.find("@#") != std::string::npos);

// Check and print the results
if (containsSubstring1 && containsSubstring2) {
std::cout << "Both substrings are present." << std::endl;
} else if (containsSubstring1) {
std::cout << "Substring #@ is present." << std::endl;
} else if (containsSubstring2) {
std::cout << "Substring @# is present." << std::endl;
} else {
std::cout << "Neither substring is present." << std::endl;
}

return 0;
}
===================================
//removet the first amd last 2 characters?
#include <iostream>
#include <string>

int main() {
std::string str = "Hello, World!";

// Check if the string is long enough to remove the first 2 and last 2 characters
if (str.length() >= 4) {
// Remove the first 2 characters
str.erase(0, 2);

// Remove the last 2 characters
str.erase(str.length() - 2);
} else {
// Handle the case where the string is too short to remove characters
std::cout << "String is too short to remove characters." << std::endl;
return 1;
}

std::cout << "Modified String: " << str << std::endl; // when we print the empty string it will be empty

return 0;
}
============================
read the content from the file:
#include <stdio.h>

int main() {
FILE* fp = fopen("example.txt", "r"); // Open a text file for reading

if (fp == NULL) {
perror("Error opening file");
return 1;
}

char line[256]; // Buffer to store each line (assuming no line is longer than 255 characters)

while (fgets(line, sizeof(line), fp) != NULL) {
printf("Line read: %s", line);
}

fclose(fp); // Close the file

return 0;
}
============================
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
std::vector<int> numbers = {12, 5, 8, 15, 7, 3, 10, 21, 4};

// Using min_element and max_element functions
auto minElement = std::min_element(numbers.begin(), numbers.end());
auto maxElement = std::max_element(numbers.begin(), numbers.end());

// Calculate positions using std::distance
int minPos = std::distance(numbers.begin(), minElement);
int maxPos = std::distance(numbers.begin(), maxElement);

// Output the results
std::cout << "Minimum Element: " << *minElement << " at position " << minPos << std::endl;
std::cout << "Maximum Element: " << *maxElement << " at position " << maxPos << std::endl;

return 0;
}
Minimum Element: 3 at position 5
Maximum Element: 21 at position 7
===============

if (maxElementIter != prices.end()) {
// Erase the maximum element
prices.erase(maxElementIter);
}
================================================
//vector empty()?
//remove requires only element value
//
#include <iostream>
#include <vector>
#include <algorithm>

void eraseAllMaxElements(std::vector<int>& prices) {
if (prices.empty()) {
std::cout << "Vector is empty." << std::endl;
return;
}

// Find the maximum element
auto maxElement = *std::max_element(prices.begin(), prices.end());

// Erase all occurrences of the maximum element
prices.erase(std::remove(prices.begin(), prices.end(), maxElement), prices.end());
}

int main() {
std::vector<int> sharePrices = {6,5, 3, 2, 5, 6,6,6,6, 5};

eraseAllMaxElements(sharePrices);

std::cout << "Updated Vector: ";
for (int price : sharePrices) {
std::cout << price << " ";
}
std::cout << std::endl;

return 0;
}
Updated Vector: 5 3 2 5 5
=============================================
//remove and find requires only the value:
#include <iostream>
#include <vector>
#include <algorithm>

void eraseOneMaxElement(std::vector<int>& prices) {
if (prices.empty()) {
std::cout << "Vector is empty." << std::endl;
return;
}

// Find the maximum element
auto maxElement = *std::max_element(prices.begin(), prices.end());

// Iterate over the vector and erase one occurrence of the maximum element at a time
auto iter = std::find(prices.begin(), prices.end(), maxElement);
if (iter != prices.end()) {
prices.erase(iter);
}
}

int main() {
std::vector<int> sharePrices = {5, 3, 2, 5, 6, 5};

while (true) {
// Erase one occurrence of the maximum element at a time
eraseOneMaxElement(sharePrices);

// Break the loop if there are no more occurrences of the maximum element
if (std::count(sharePrices.begin(), sharePrices.end(), *std::max_element(sharePrices.begin(), sharePrices.end())) == 0) {
break;
}
}

std::cout << "Updated Vector: ";
for (int price : sharePrices) {
std::cout << price << " ";
}
std::cout << std::endl;

return 0;
}
============================================
#include <iostream>
#include <unordered_map>
#include <map>

int main() {
// Example of HashMap (unordered_map)
std::unordered_map<int, std::string> hashMap = {{3, "Three"}, {1, "One"}, {2, "Two"}};

// Example of TreeMap (map)
std::map<int, std::string> treeMap = {{3, "Three"}, {1, "One"}, {2, "Two"}};

// Print HashMap
std::cout << "HashMap: ";
for (const auto& pair : hashMap) {
std::cout << "{" << pair.first << ": " << pair.second << "} ";
}
std::cout << std::endl;

// Print TreeMap
std::cout << "TreeMap: ";
for (const auto& pair : treeMap) {
std::cout << "{" << pair.first << ": " << pair.second << "} ";
}
std::cout << std::endl;

return 0;
}
========================================================
string function: //index starts from 0
str indexing?
append
reverse
rfind and find
compare
insert
empty or not?
clear the content of string
resize()?
substr
string not found?

string str;
str[0]: to access first character
str[str.len()-1]:to access the last character
string::npos?
str+="c++": appaend the string
reverse(str.begin(),str.end())

std::string original = "Hello, World!";
std::string substring = original.substr(7, 5);

std::string original = "Hello, World! Hello, Universe!";
size_t lastHelloIndex = original.rfind("Hello"); //14

std::string str1 = "apple";
std::string str2 = "banana";

int result = str1.compare(str2);//-1

std::string original = "Hello, Universe!";
std::string toInsert = " World";
size_t position = 6;

original.insert(position, toInsert); //Hello World, Universel 
str.empty()?
str="hello" //hello!!!!!!!!!!!(till 15)
str.resize(15,'!'); //if the str is less than 15 character it append !
str="hello"
str.resize(3);//trucate the str to 5 //Hel

myString.clear();
===============================
where cstddef is used?
==============================
template class:
template <typename t>
class sample
==================================
void printSymmetricPattern(int n) {
for (int i = 1; i <= n; ++i) {
for (int j = 1; j <= n; ++j) {
// Print numbers for the first half
if (j <= i)
std::cout << std::setw(2) << j;
else
std::cout << "  "; // Print spaces for the second half
}

for (int j = n - 1; j >= 1; --j) {
// Print numbers for the second half
if (j <= i)
std::cout << std::setw(2) << j;
else
std::cout << "  "; // Print spaces for the first half
}

std::cout << std::endl;
}
}

int main() {
int n = 5; // Change this value to adjust the pattern size

printSymmetricPattern(n);

return 0;
}
1 2 3 4 5 4 3 2 1
1 2 3 4   4 3 2 1
1 2 3       3 2 1
1 2           2 1
1               1
=========================
Binary search tree:
#include <iostream>

// Definition of a TreeNode
struct TreeNode {
int data;
TreeNode* left;
TreeNode* right;

// Constructor
TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
TreeNode* root;

// Helper function for inserting a value into the BST
TreeNode* insert(TreeNode* node, int value) {
if (node == nullptr) {
return new TreeNode(value);
}

if (value < node->data) {
node->left = insert(node->left, value);
} else if (value > node->data) {
node->right = insert(node->right, value);
}

return node;
}

// Helper function for finding the minimum value node in a BST
TreeNode* findMin(TreeNode* node) {
while (node->left != nullptr) {
node = node->left;
}
return node;
}

// Helper function for deleting a value from the BST
TreeNode* remove(TreeNode* node, int value) {
if (node == nullptr) {
return nullptr;
}

if (value < node->data) {
node->left = remove(node->left, value);
} else if (value > node->data) {
node->right = remove(node->right, value);
} else {
// Node to be deleted found

// Case 1: Node with only one child or no child
if (node->left == nullptr) {
TreeNode* temp = node->right;
delete node;
return temp;
} else if (node->right == nullptr) {
TreeNode* temp = node->left;
delete node;
return temp;
}

// Case 2: Node with two children
TreeNode* temp = findMin(node->right);
node->data = temp->data;
node->right = remove(node->right, temp->data);
}

return node;
}

// Helper function for inorder traversal
void inorderTraversal(TreeNode* node) {
if (node != nullptr) {
inorderTraversal(node->left);
std::cout << node->data << " ";
inorderTraversal(node->right);
}
}

public:
// Constructor
BinarySearchTree() : root(nullptr) {}

// Public function for inserting a value into the BST
void insert(int value) {
root = insert(root, value);
}

// Public function for deleting a value from the BST
void remove(int value) {
root = remove(root, value);
}

// Public function for checking if a value is present in the BST
bool search(int value) {
TreeNode* current = root;
while (current != nullptr) {
if (value == current->data) {
return true;
} else if (value < current->data) {
current = current->left;
} else {
current = current->right;
}
}
return false;
}

// Public function for inorder traversal
void inorderTraversal() {
inorderTraversal(root);
std::cout << std::endl;
}
};

int main() {
BinarySearchTree bst;

// Insert elements into the BST
bst.insert(50);
bst.insert(30);
bst.insert(70);
bst.insert(20);
bst.insert(40);
bst.insert(60);
bst.insert(80);

// Print inorder traversal of the BST
std::cout << "Inorder Traversal: ";
bst.inorderTraversal();

// Search for elements in the BST
std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
std::cout << "Search 90: " << (bst.search(90) ? "Found" : "Not Found") << std::endl;

// Remove elements from the BST
bst.remove(30);
bst.remove(80);

// Print inorder traversal of the modified BST
std::cout << "Inorder Traversal (After Deletion): ";
bst.inorderTraversal();

return 0;
}
=======================================================
1
/ \
2   3
/ \
4   5
The inorder traversal would be: 4 2 5 1 3
The preorder traversal would be: 1 2 4 5 3
The postorder traversal would be: 4 5 2 3 1
-========================================================
void preorderTraversal(TreeNode* node) {
if (node != nullptr) {
std::cout << node->data << " ";
preorderTraversal(node->left);
preorderTraversal(node->right);
}
}
===================================
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& array, int target) {
int left = 0;
int right = array.size() - 1;

while (left <= right) {
int mid = left + (right - left) / 2;

// Check if the target is present at the middle
if (array[mid] == target) {
return mid;
}

// If the target is greater, ignore the left half
if (array[mid] < target) {
left = mid + 1;
}
// If the target is smaller, ignore the right half
else {
right = mid - 1;
}
}

// If the target is not present in the array
return -1;
}

int main() {
std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int target = 7;
int result = binarySearch(sortedArray, target);

if (result != -1) {
std::cout << "Element " << target << " found at index " << result << std::endl;
} else {
std::cout << "Element " << target << " not found in the array" << std::endl;
}

return 0;
}
===========================
//if the string contain only one character it is polindrome.
palindrome
#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string& str) {
// Remove spaces and convert to lowercase for case-insensitive comparison
std::string cleanStr;
for (char c : str) {
if (!std::isspace((c))) {
cleanStr += std::tolower(c);
}
}

// Check if the cleaned string is a palindrome
int start = 0;
int end = cleanStr.length() - 1;

while (start < end) {
if (cleanStr[start] != cleanStr[end]) {
return false;
}
++start;
--end;
}

return true;
}

int main() {
std::string input;

std::cout << "Enter a string: ";
std::getline(std::cin, input);

if (isPalindrome(input)) {
std::cout << "The string is a palindrome." << std::endl;
} else {
std::cout << "The string is not a palindrome." << std::endl;
}

return 0;
}

===================================
regex:
regex_search return what
smatch match. match[i] will retuen the string
input = match.suffix().str() //matich.suffix() or match.str()
regex pattern("\\b\\d+\\b")
regex pattern(R"(\bfksdfkshdfkjhsd\b)")
=======================
while (fgets() != NULL)
=========================
make_index_sequence is in which header file?

size_t is used for for index passing ie f<0,1,2,3,45>() and index_sequence<>{}
folded can be applied on  when  size_t.... t but if the template <typname .... t> , then we can function t...t1) 
folded can be applied on t1 and not on t
/////
//string, vector.size(), offsetof find return size_t
stack.empty(); stack.size()
===================
cstddef:
offsetof
ptdiff_t
make_index_sequence<size>