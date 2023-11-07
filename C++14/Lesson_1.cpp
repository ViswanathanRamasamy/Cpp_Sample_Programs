/*
	Lesson1: Sample program for the C++14 features.
	Source Code Location: https://github.com/ViswanathanRamasamy/_Sample_Programs
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
//create the dynamic array and assigned to uniqueue pointer
// this program will not work for shared pointer if you change make_unique to make_shared.

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
        cout << ptr[index] << " "; //n *
    }
    return 0;
}
=============================================================
//shared pointer to an array
//[](int* p) lamda function that take pointer to intger
#include <iostream>
#include <memory>
using namespace std;

int main()
{
	// Create a shared pointer to an array and provide a custom deleter
	std::shared_ptr<int> ptr(new int[10], [](int* p) {
		delete[] p;
	});

	ptr.get()[6] = 10;
	std::cout << ptr.get()[6];

	return 0;
}

==============================================================
//#Agregate member initialization
//.age= 12, .age{12}
//#when we access the unitialized member variable of the structire the behaviour is undefined.
//#in c++ agergatore , we initialize to the default value
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
    //Employee robert ( 3, 45, 62500.0 ); //c++20. else it will search for the constructor. it is needed to give all threee element
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

#include <iostream>

template <typename T>
constexpr T pi = T(3.1415926535897932385);

int main() {
	double pi_double = pi<double>; // Use pi with double type
	float pi_float = pi<float>;    // Use pi with float type

	std::cout << "pi (double): " << pi_double << std::endl;
	std::cout << "pi (float): " << pi_float << std::endl;

	return 0;
}

============================

extended constexpression:
#include <iostream>

// C++14: relaxed constexpr function
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
User defined literal: //if the constexpr is not there it will not generated in compile time
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
constexpr int operator""_myliteral(unsigned long long value) {
	return static_cast<int>(value * 2);
}

int main() {
	int result = 42_myliteral; // The user-defined literal is evaluated at compile-time.
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
// the constexpr keyword is used to indicate that an expression or function can be evaluated at compile-time.
//constexpr int constantValue = 42;
===
constexpr int square(int x) {
	return x * x;
}
constexpr int result = square(7);  // Computed at compile-time

=====
#include <iostream>
#include <type_traits>

template <typename T>
void printTypeInfo(T value1) {
    if constexpr (std::is_integral<T>::value) { // not must to have constexpr if you want to evaluate in compile time put constexpr
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
==========================================================
#include <iostream>
#include <type_traits>
#include <string>

int main() {
	using T = std::string;
	bool isString = std::is_same<T, std::string>::value;

	if (isString) {
		std::cout << "T is a std::string" << std::endl;
	}
	else {
		std::cout << "T is not a std::string" << std::endl;
	}

	return 0;
}
=======================================
#include <iostream>
#include <type_traits> //type_traits
#include <string>

int main() {
	std::string t = "hi";
	bool isString = std::is_same<decltype(t), std::string>::value;

	if (isString) {
		std::cout << "t is a std::string" << std::endl;
	}
	else {
		std::cout << "t is not a std::string" << std::endl;
	}

	return 0;
}

==========================================
//string find return size_t

#include <iostream>
#include <string>

int main() {
	std::string text = "This is a sample sentence with the word sample.";

	// Find the word to replace
	std::string wordToFind = "sample";

	// Replacement word
	std::string replacement = "replacement";

	size_t pos = text.find(wordToFind);

	while (pos != std::string::npos) {
		text.replace(pos, wordToFind.length(), replacement);
		pos = text.find(wordToFind, pos + replacement.length());
	}

	std::cout << "Modified text: " << text << std::endl;

	return 0;
}


=============================================
C++14:
//std::this_thread::yield() is a C++ standard library function that hints to the operating system's scheduler that the current thread is 
//willing to yield the CPU and give up its time slice.
//It's a way for a thread to voluntarily yield the processor to other threads of equal or higher priority that are ready to run.
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

 ==================================================================
Resource initialized only Once:
this_threat::get_id()
this_thread::sleep_until()
this_thread::yield()

#include <iostream>
#include <thread>
#include <mutex> // once_flag

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
==============================================
//call_once return the value in lamda
//In C++, the std::call_once function is typically used with a callable object, which can be a function, function pointer, function object (like a lambda), or a functor.
#include <iostream>
#include <thread>
#include <mutex>

int getResource() {
	std::cout << "Initializing resource..." << std::endl;
	return 42;
}

int main() {
	std::once_flag flag;
	int resource = 0;

	std::call_once(flag, [&resource](){ resource = getResource(); });

	std::cout << "Resource: " << resource << std::endl;

	return 0;
}

==========================================
//sleep until: wait till the particular time has reached?
//Header file required?
//steady_clock and not as  steady_clock()

#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Start of program." << std::endl;

    // Calculate a point in time 5 seconds from now
	//auto std::chrono::time_point<std::chrono::steady_clock>
    auto wakeupTime = std::chrono::steady_clock::now() + std::chrono::seconds(5); //seconds

    // Sleep until the specified time is reached
    std::this_thread::sleep_until(wakeupTime);

    std::cout << "End of program." << std::endl;

    return 0;
}
================================================
//vector.size and string find wull size data tyoe
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

int main() {
	// Input: an array of integers
	std::vector<int> buffer = { 15, 127, 255, 1024, 4096 };

	// Create a stringstream to format the integers as hexadecimal strings
	std::stringstream strStream;
	std::stringstream strStream1;
	std::cout << buffer.size();//5

	for (size_t i = 0; i < buffer.size(); ++i) {
		// Format the integer as a hexadecimal string with leading zeros
		strStream << std::setfill('0') << std::setw(2) << std::hex << static_cast<unsigned int>(buffer[i]);
		strStream1 << "0x" << std::hex << static_cast<unsigned int>(buffer[i]);

		// Add a space or newline if not the last element
		if (i < buffer.size() - 1) {
			strStream << ' ';
		}
		else {
			strStream << '\n';
		}
	}

	// Output the formatted strings
	std::cout << "Formatted Hexadecimal Strings:\n" << strStream.str();
	std::cout << "Formatted Hexadecimal Strings:\n" << strStream1.str();

	return 0;
}

0f 7f ff 400 1000
Formatted Hexadecimal Strings :
0xf0x7f0xff0x4000x1000
====================================
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
	std::vector<int> arr = { 1, 2, 3, 4, 2, 5, 1, 6, 7, 4 };

	std::unordered_map<int, int> elementCount;

	for (int &num : arr) {
		elementCount[num]++;
	}

	std::cout << "Duplicate elements in the array: ";
	for (const auto& pair : elementCount) {
		if (pair.second > 1) {
			std::cout << pair.first << " ";
		}
	}

	std::cout << std::endl;

	return 0;
}

space and time complexity is 0(N). Input elemt space should not be consider for calculating the space.

=====================================================
shared_ptr can also be passed as reference:
#include <iostream>
#include <memory>

class MyClass {
public:
	MyClass(int val) : data(val) {}

	void printData() {
		std::cout << "Data: " << data << std::endl;
	}

private:
	int data;
};

void functionUsingSharedPtr(std::shared_ptr<MyClass> ptr) { //reference count is incrmented
	if (ptr) {
		ptr->printData();
	}
	else {
		std::cout << "shared_ptr is null." << std::endl;
	}
}

int main() {
	// Create a shared_ptr
	std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(42);

	// Pass the shared_ptr to a function
	functionUsingSharedPtr(sharedPtr);

	return 0;
}

======================================================
segmentation fault:
class MyClass {
public:
	MyClass(int val) : data(val) {}

	void printData() {
		std::cout << "Data: " << data << std::endl;
	}

private:
	int data;
};

void functionUsingSharedPtr(std::shared_ptr<MyClass> ptr) {

	// Assign a new value to the passed shared_ptr (copy)
	ptr = std::make_shared<MyClass>(99);
	ptr->printData(); // This will print the new value 99

}

int main() {
	// Create a shared_ptr
	std::shared_ptr<MyClass> sharedPtr;

	// Pass the shared_ptr to a function
	functionUsingSharedPtr(sharedPtr);

	// Original shared_ptr in main is not affected
	sharedPtr->printData(); //segmentation fault

	return 0;
}
//////////////////////////
std::map(Red - Black Tree) : insertion, deletion, search o(log N)
std::unordered_map(Hash Table) :
Insertion : Average case -O(1), Worst case -O(N)
//////////////////////////////////////
single list reversal:
#include <iostream>

// Define a structure for a singly linked list node
struct Node {
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a singly linked list with proper list formation
Node* reverseLinkedList(Node* head) {
	Node* prev = nullptr;
	Node* current = head;
	Node* nextNode = nullptr;

	while (current != nullptr) {
		nextNode = current->next; // Store the next node
		current->next = prev;     // Reverse the pointer direction

		// Move to the next node
		prev = current;
		current = nextNode;
	}

	return prev; // The new head of the reversed list
}

// Function to create and append a new node to the linked list
void appendNode(Node*& head, int data) {
	Node* newNode = new Node(data);
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
}

// Function to print a singly linked list
void printLinkedList(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		std::cout << current->data << " -> ";
		current = current->next;
	}
	std::cout << "nullptr" << std::endl;
}

int main() {
	// Create an empty singly linked list
	Node* head = nullptr;

	// Append elements to the linked list
	appendNode(head, 1);
	appendNode(head, 2);
	appendNode(head, 3);
	appendNode(head, 4);
	appendNode(head, 5);

	std::cout << "Original Linked List: ";
	printLinkedList(head);

	// Reverse the linked list
	head = reverseLinkedList(head);

	std::cout << "Reversed Linked List: ";
	printLinkedList(head);

	return 0;
}


Original Linked List : 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
Reversed Linked List : 5 -> 4 -> 3 -> 2 -> 1 -> nullptr

//////////////////////////////////////////////
doubly link list reversal:

#include <iostream>

// Define a structure for a doubly linked list node
struct Node {
	int data;
	Node* next;
	Node* prev;
	Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to reverse a doubly linked list with proper list formation
Node* reverseDoublyLinkedList(Node* head) {
	Node* current = head;
	Node* temp = nullptr;

	while (current != nullptr) {
		temp = current->next; // Store the next node

		// Swap next and prev pointers of the current node
		current->next = current->prev;
		current->prev = temp;

		if (temp == nullptr) {
			head = current; // Update the new head of the reversed list
		}

		// Move to the next node
		current = temp;
	}

	return head; // The new head of the reversed list
}

// Function to create and append a new node to the doubly linked list
void appendNode(Node*& head, int data) {
	Node* newNode = new Node(data);
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}

// Function to print a doubly linked list forward
void printDoublyLinkedListForward(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		std::cout << current->data << " <-> ";
		current = current->next;
	}
	std::cout << "nullptr" << std::endl;
}

int main() {
	// Create an empty doubly linked list
	Node* head = nullptr;

	// Append elements to the doubly linked list
	appendNode(head, 1);
	appendNode(head, 2);
	appendNode(head, 3);
	appendNode(head, 4);
	appendNode(head, 5);

	std::cout << "Original Doubly Linked List: ";
	printDoublyLinkedListForward(head);

	// Reverse the doubly linked list
	head = reverseDoublyLinkedList(head);

	std::cout << "Reversed Doubly Linked List: ";
	printDoublyLinkedListForward(head);

	return 0;
}

#include <iostream>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to reverse a doubly linked list with proper list formation
Node* reverseDoublyLinkedList(Node* head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->next; // Store the next node

        // Swap next and prev pointers of the current node
        current->next = current->prev;
        current->prev = temp;

        if (temp == nullptr) {
            head = current; // Update the new head of the reversed list
        }

        // Move to the next node
        current = temp;
    }

    return head; // The new head of the reversed list
}

// Function to create and append a new node to the doubly linked list
void appendNode(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print a doubly linked list forward
void printDoublyLinkedListForward(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create an empty doubly linked list
    Node* head = nullptr;

    // Append elements to the doubly linked list
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);

    std::cout << "Original Doubly Linked List: ";
    printDoublyLinkedListForward(head);

    // Reverse the doubly linked list
    head = reverseDoublyLinkedList(head);

    std::cout << "Reversed Doubly Linked List: ";
    printDoublyLinkedListForward(head);

    return 0;
}
Original Doubly Linked List : 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> nullptr
Reversed Doubly Linked List : 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> nullptr
===========================
circular loop in linklist:
#include <iostream>

struct Node {
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return false; // No loop if the list is empty or has only one node
	}

	Node* tortoise = head;
	Node* hare = head;

	while (hare != nullptr && hare->next != nullptr) {
		tortoise = tortoise->next;       // Move the tortoise one step
		hare = hare->next->next;         // Move the hare two steps

		if (tortoise == hare) {
			return true; // The tortoise and hare meet, indicating a loop
		}
	}

	return false; // No loop found
}

int main() {
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = head; // Create a circular loop

	if (hasCycle(head)) {
		std::cout << "The linked list has a cycle." << std::endl;
	}
	else {
		std::cout << "The linked list does not have a cycle." << std::endl;
	}

	return 0;
}

=============================================================
// It's primarily used as a tool to work with and manipulate sequences of integers at compile time. 
//integer_sequence?
include <iostream>
#include <utility> 
using namespace std;

template <typename T, T... Is>
void print_sequence(integer_sequence<T, Is...>)
{
	cout << "The sequence is: ";
	((cout << Is << ' '),
		...); // fold expression to print sequence 
}

int main()
{
	print_sequence(integer_sequence<int, 1, 2, 3, 4>{});
	return 0;
}
The sequence is : 1 2 3 4
stod: string to double
stof: string to float
  stold: string to long double

======================
#include <string> 
#include <iostream> 

int main(void)

{
	std::string str = "y=4.4786754x+5.6";

	double y, x, a, b;
	y = 0;
	x = 0;

	// offset will be set to the length of  
	// characters of the "value" - 1. 
	std::size_t offset = 0;

	a = std::stod(&str[2], &offset); // if you change the number to [1] crash
	std::cout << a << " " << offset << "\n";
	b = std::stod(&str[offset + 3]);


	std::cout << b;
	return 0;
}
====
4.47868 9
5.6
===========================
merge sort for the sorted array set:
#include <iostream>
#include <vector>

// Merge two sorted arrays into a single sorted list
std::vector<int> mergeSortedArrays(const std::vector<int>& array1, const std::vector<int>& array2) {
	std::vector<int> mergedList;
	size_t i = 0, j = 0;

	while (i < array1.size() && j < array2.size()) {
		if (array1[i] < array2[j]) {
			mergedList.push_back(array1[i]);
			i++;
		}
		else {
			mergedList.push_back(array2[j]);
			j++;
		}
	}

	// If there are remaining elements in either array, add them to the merged list
	while (i < array1.size()) {
		mergedList.push_back(array1[i]);
		i++;
	}

	while (j < array2.size()) {
		mergedList.push_back(array2[j]);
		j++;
	}

	return mergedList;
}

int main() {
	std::vector<int> array1 = { 1, 3, 5, 7, 9 };
	std::vector<int> array2 = { 2, 4, 6, 8, 10 };

	std::vector<int> mergedList = mergeSortedArrays(array1, array2);

	std::cout << "Merged and sorted list: ";
	for (int num : mergedList) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}
===================================================
#include <iostream>
#include <vector>
#include <algorithm> // no a

// Merge two sets of arrays into a single sorted array
std::vector<int> mergeSortedArrays(const std::vector<int>& array1, const std::vector<int>& array2) {
	std::vector<int> mergedList;

	// Copy the contents of both arrays into the merged list
	mergedList.insert(mergedList.end(), array1.begin(), array1.end());
	mergedList.insert(mergedList.end(), array2.begin(), array2.end());

	// Sort the merged list in ascending order
	std::sort(mergedList.begin(), mergedList.end());

	return mergedList;
}

int main() {
	// Define two sets of arrays with random order
	std::vector<int> array1 = { 3, 1, 5, 2, 4 };
	std::vector<int> array2 = { 8, 6, 10, 7, 9 };

	// Merge and sort the arrays
	std::vector<int> mergedList = mergeSortedArrays(array1, array2);

	std::cout << "Merged and sorted list: ";
	for (int num : mergedList) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}

======================================================
//unordered_set
//unordered_map
#include <iostream>
#include <vector>
#include <unordered_set>

// Merge two arrays and remove duplicates
std::vector<int> mergeAndRemoveDuplicates(const std::vector<int>& array1, const std::vector<int>& array2) {
	std::vector<int> mergedList;
	std::unordered_set<int> seenElements;

	// Merge the first array into the result
	for (int num : array1) {
		mergedList.push_back(num);
		seenElements.insert(num);
	}

	// Merge the second array into the result, checking for duplicates
	for (int num : array2) {
		if (seenElements.find(num) == seenElements.end()) {
			mergedList.push_back(num);
			seenElements.insert(num);
		}
	}

	return mergedList;
}

int main() {
	std::vector<int> array1 = { 1, 3, 5, 7, 9 };
	std::vector<int> array2 = { 2, 4, 6, 8, 10, 3, 7 };

	std::vector<int> mergedList = mergeAndRemoveDuplicates(array1, array2);

	std::cout << "Merged list without duplicates: ";
	for (int num : mergedList) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}
Merged list without duplicates : 1 3 5 7 9 2 4 6 8 10
=========================
#include <iostream>
#include <string>
using namespace std;
// Function to convert a number to its word representation
std::string numberToWords(long long number) {
	if (number == 0) {
		return "zero";
	}

	const char* ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	const char* teens[] = { "", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const char* tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	std::string result;

	// Handling billions
	if (number >= 1000000000) {
		result += std::string(ones[number / 1000000000]) + " billion ";
		number %= 1000000000;
	}

	// Handling millions
	if (number >= 1000000) {
		result += numberToWords(number / 1000000) + " million ";
		number %= 1000000;
	}

	// Handling thousands
	if (number >= 1000) {
		result += numberToWords(number / 1000) + " thousand ";
		number %= 1000;
	}

	// Handling hundreds
	if (number >= 100) {
		result += std::string(ones[number / 100]) + " hundred ";
		number %= 100;
	}

	// Handling tens and ones
	if (number >= 20) {
		result += std::string(tens[number / 10]) + " ";
		number %= 10;
	}
	else if (number >= 11) {
		result += std::string(teens[number - 10]) + " ";
		number = 0;
	}

	if (number > 0) {
		result += std::string(ones[number]) + " ";
	}

	return result;
}


int main()
{
	cout << numberToWords(100210);
	return 0;
}
================================
//header file required for sqrt
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>

std::pair<double, double> findRoots(double a, double b, double c) {
	std::pair<double, double> p;

	double discriminant = b * b - 4 * a * c;

	if (discriminant < 0) {
		throw std::logic_error("No real roots");
	}

	p.first = (-b + sqrt(discriminant)) / (2 * a);
	p.second = (-b - sqrt(discriminant)) / (2 * a);

	return p;
}

int main() {
	try {
		std::pair<double, double> roots = findRoots(2, 10, 8);
		std::cout << "Roots: " << std::to_string(roots.first) << ", " << std::to_string(roots.second) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

==============================
#include <tuple>
#include <stdexcept>
#include <iostream>
#include <cmath>

std::tuple<double, double> findRoots(double a, double b, double c) {
	double discriminant = b * b - 4 * a * c;

	if (discriminant < 0) {
		throw std::logic_error("No real roots");
	}

	double root1 = (-b + sqrt(discriminant)) / (2 * a);
	double root2 = (-b - sqrt(discriminant)) / (2 * a);

	return std::make_tuple(root1, root2);
}

#ifndef RunTests
int main() {
	try {
		std::tuple<double, double> roots = findRoots(2, 10, 8);
		double root1, root2;
		std::tie(root1, root2) = roots;

		std::cout << "Roots: " << root1 << ", " << root2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
#endif
===========================
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2) {
	// Merge the two vectors into one
	std::vector<std::string> mergedNames(names1);
	mergedNames.insert(mergedNames.end(), names2.begin(), names2.end());

	// Sort the merged names
	std::sort(mergedNames.begin(), mergedNames.end());

	// Use std::unique to remove duplicates
	auto last = std::unique(mergedNames.begin(), mergedNames.end());
	mergedNames.erase(last, mergedNames.end());

	return mergedNames;
}

#ifndef RunTests
int main() {
	std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
	std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };

	std::vector<std::string> result = unique_names(names1, names2);
	for (auto element : result) {
		std::cout << element << ' ';
	}
	std::cout << std::endl; // should print Ava Emma Olivia Sophia
}
#endif
=================================
insert all the element of the vector to zero
std::vector<int> result = simulate({ 1, 2, 0, 5, 0, 2, 4, 3, 3, 3 });
std::vector<int> simulate(const std::vector<int> &entries) //non const l value error if no const
{
	std::vector<int> result(entries.size(), 0);
}

std::vector<int> simEntries = entries;
//std::vector<int> result(entries); // Using constructor syntax
//std::vector<int> result{ entries }; // Using initializer list syntax
//std::vector<int> result=(entries); // Using constructor syntax
//std::vector<int> result={ entries }; // Using initializer list syntax
for (auto itX = simEntries.begin(); itX != simEntries.end(); ++itX) {
	std::vector<int>::iterator leftT = itX; // Iterator of left T position

	// Check if itX is within 3 positions from the beginning
	if (std::distance(simEntries.begin(), itX) <= 2) {
		continue; // If itX is close to the beginning, skip to the next iteration
	}
=================================================
#include <iostream>
#include <map>

int main() {
	// Create a map of integers to integers
	std::map<int, int> myMap;

	// Create a pair
	std::pair<int, int> p(1, 42);

	// Insert the pair into the map
	myMap.insert(p);

	// Print the contents of the map
	for (const auto& pair : myMap) {
		std::cout << pair.first << " -> " << pair.second << std::endl;
	}

	return 0;
}
=======================================
#include <iostream>
#include <string>

class Base {
public:
	virtual void processInput(const std::string& input) = 0;
};

class Derived : public Base {
public:
	void processInput(const std::string& input) override {
		for (char ch : input) {
			if (std::isdigit(ch)) {
				std::cout << ch << " ";
			}
		}
	}
};

int main() {
	Derived derived;
	derived.processInput("1");
	derived.processInput("a");
	derived.processInput("0");
	derived.processInput("b");
	derived.processInput("123");

	return 0;
}
==========================================
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
	std::unordered_map<int, int> numIndexMap;

	for (int i = 0; i < nums.size(); i++) {
		int complement = target - nums[i];

		// Check if the complement exists in the map
		if (numIndexMap.find(complement) != numIndexMap.end()) {
			return{ numIndexMap[complement], i };
		}

		// Store the current number and its index in the map
		numIndexMap[nums[i]] = i;
	}

	// No solution found, return an empty vector
	return{};
}

int main() {
	std::vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;

	std::vector<int> result = twoSum(nums, target);

	if (!result.empty()) {
		std::cout << "Indices of the two numbers that add up to the target: " << result[0] << " and " << result[1] << std::endl;
		std::cout << "Values of the two numbers: " << nums[result[0]] << " and " << nums[result[1]] << std::endl;
	}
	else {
		std::cout << "No solution found." << std::endl;
	}

	return 0;
}
Indices of the two numbers that add up to the target : 0 and 1
Values of the two numbers : 2 and 7
== == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
=================
Friend Function Cannot Be const and virtual:

A friend function cannot be declared as const or virtual.Friend functions are not members of the class, so they don't have the this pointer and can't access the member variables directly.They work with the object through their parameters.



class A {
private:
	int x;

public:
	A(int val) : x(val) {}

	friend void ShowValue(const A& obj); 
};

void ShowValue(const A& obj) {
	std::cout << obj.x << std::endl;
}

int main() {
	A a(42);
	ShowValue(a);
	return 0;
}
=========================================================
friend function cannot be static:
Friend functions are meant to be associated with instances of a class, and they are not tied to the class itself as static member functions are.
class MyClass {
private:
	int value;

public:
	MyClass(int val) : value(val) {}

	// A friend function
	friend void FriendFunction(const MyClass& obj);

	static void StaticMemberFunction() {
		// This is a static member function of the class
		// It can access static members
		std::cout << "Static member function" << std::endl;
	}
};

// Definition of the friend function
void FriendFunction(const MyClass& obj) {
	std::cout << "Value accessed by the friend function: " << obj.value << std::endl;
}

int main() {
	MyClass myObject(42);

	FriendFunction(myObject); // Calling the friend function
	MyClass::StaticMemberFunction(); // Calling the static member function

	return 0;
}
Value accessed by the friend function: 42
Static member function
=================================================
==========================
Non - Member Function Cannot Be const:

Non - member functions don't have the concept of being const because they are not part of a class. They can still work with const objects as arguments.
=======================
riend Function Cannot Be Accessed in the Derived Class Object :

A friend function is not a member of the class, so it cannot be accessed using a derived class object.

class B
class A {
private:
	int x;
public:
	A(int val) : x(val) {}
	friend void ShowValue(const A& obj) { //cann access only the private dat of the class A and not the class b provate
		//friend void ShowValue(const B& obj) //cannot access the private member of the class A from B
		cout << "viswa" << obj.x;
		//cout << obj.y; //error
	};
};

class B : public A { //if there is no : public A it will give error
	int y;
public:
	B(int val) : A(val) {
		ShowValue(*this);
	}
};

int main() {
	B b(42); //viswa 42
	ShowValue(b);  // viswa 42
	return 0;
}
===================================

class A {
private:
	int x;

public:
	A(int val) : x(val) {}

	friend void ModifyValue(A& obj, int newValue);  // Friend function to modify x
};

void ModifyValue(A& obj, int newValue) {
	obj.x = newValue;  // allowed
}
========================================
Friend Function in Derived Class :

If a friend function is used in a derived class, it's specific to the derived class and cannot access the base class's private variables.


class A {
private:
	int x;

public:
	A(int val) : x(val) {}

	friend void ShowValueInBase(const A& obj);
};

void ShowValueInBase(const A& obj) {
	std::cout << obj.x << std::endl;
}

class B : public A {
private:
	int y;

public:
	B(int val1, int val2) : A(val1), y(val2) {}

	friend void ShowValueInDerived(const B& obj);
};

void ShowValueInDerived(const B& obj) {
	std::cout << obj.x << " " << obj.y << std::endl;  // Error: Can't access private member x of the base class
}

int main() {
	B b(42, 100);
	ShowValueInBase(b);     // Can access the base class's private member
	ShowValueInDerived(b);  // Error: Can't access the base class's private member
	return 0;
}
===============================
A and B are independednt class. To access the private member of other class?

class B;

class A {
private:
	int xx;
public:
	void showB(B&);


};

class B {
private:
	int b;

	friend void A::showB(B& x);

public:
	B() { b = 0; }


};
void A::showB(B& x)
{
	// Since showB() is friend of B, it can
	// access private members of B
	std::cout << "B::b = " << x.b << xx; //0 0
}



int main()
{
	A a;
	B x;
	a.showB(x);
	return 0;
}
== == == == == == == == == == == == == == == == ==
A and B are independednt class.To access the private member of other class ?
#include <iostream>

class B;  // Forward declaration of class B

class A {
private:
	int privateDataA;

public:
	A(int val) : privateDataA(val) {}

	friend class B;  // Class B is a friend of class A
};

class B {
public:
	void AccessPrivateDataA(const A& obj) {
		// Class B, as a friend, can access private members of class A
		std::cout << "Value from Class B: " << obj.privateDataA << std::endl;
	}
};

int main() {
	A a(42);
	B b;

	b.AccessPrivateDataA(a);  // Class B accesses private data of class A through a friend relationship

	return 0;
}

===================================
#include <stdio.h>

int main() {
	int day = 15;
	double temperature = 23.4567;

	char formattedStr[50];
	sprintf(formattedStr, "Day %02d: Temperature = %.2f°C", day, temperature);
	printf("%s\n", formattedStr);

	return 0;
}

==================================
#include <stdio.h>

int main() {
	char inputStr[20];
	int number;

	printf("Enter an integer: ");
	scanf("%s", inputStr);

	if (sscanf(inputStr, "%d", &number) == 1) {
		printf("Parsed Integer: %d\n", number);
	}
	else {
		printf("Invalid input.\n");
	}

	return 0;
}
============================
#include <stdio.h>

int main() {
	char dataStr[] = "John 30    5000.50"; //spaces can be any number of spaces
	char name[20];
	int age;
	float salary;

	sscanf(dataStr, "%s%d%f", name, &age, &salary); // there can be also psaces between the %s  %d  %f

	printf("Name: %s\nAge: %d\nSalary: %.2f\n", name, age, salary);

	return 0;
}
==============================
//read the character from the buffer and the number of character read
#include <stdio.h>

int main() {
	char input[] = "12345  6789";  // Sample input// space is used for the argument seperation

	char buffer[6];  // Buffer for numeric data (size-limited)
	int charactersRead = 0;
	int d;
	int charactersRead1 = 0;
	// Use sscanf with field width limitation (%5s) and %n
	if (sscanf(input, "%5s%n%d%n", buffer, &charactersRead, &d, &charactersRead1) == 2) {
		printf("Scanned data: %s\n", buffer);
		printf("Total characters scanned: %d %d %d\n", charactersRead, d, charactersRead1);
	}
	else {
		printf("Parsing failed.\n");
	}

	return 0;
}
=====
Scanned data : 12345
Total characters scanned : 5 6789 11
=======================
// snprintf to handle the error cases for the buffer size
#include <stdio.h>
#include <string.h>

int main() {
	char buffer[50];

	int num = 42;
	double price = 99.99;

	// Check if the buffer is large enough to hold the formatted string
	if (sizeof(buffer) < snprintf(NULL, 0, "Number: %d, Price: %.2f", num, price) + 1) {
		printf("Error: Buffer is too small for the formatted string.\n");
		return 1;
	}

	// Use snprintf to safely format the data
	int result = snprintf(buffer, sizeof(buffer), "Number: %d, Price: %.2f", num, price);

	if (result >= 0 && result < sizeof(buffer)) {
		printf("Formatted String: %s\n", buffer);
	}
	else {
		printf("Error: Failed to format the string.\n");
	}

	return 0;
}

================================
//sprintf return the number of character written to the buffer

int main() {
	char buffer[50];

	int num = 42;
	double price = 99.99;

	// Use sprintf to format the data
	int length1 = sprintf(buffer, "Number: %d, Price: %.2f", num, price);

	// Calculate the total characters (including null-terminator) using strlen
	int length = strlen(buffer);

	printf("Formatted String: %s\n", buffer);
	printf("Total Characters (including null-terminator): %d\n", length1); //24 number of character 1 to 24 but buffer nedded is 24+1

	return 0;
}
==================================
#include <cctye>
char ch = '5';
if (isdigit(ch)) {
	std::cout << "The character is a digit." << std::endl;

	char ch = 'A';
	if (isalpha(ch)) {
====================================
Abstract Class : you cannot create the instance of the abstract class.

An abstract class is a class that is specially designed to be used as a base class.Abstract class must have at least one pure virtual function.It may have variables and normal functions.
The derived classes of an abstract class must implement all the pure virtual functions of their base class or else they too become abstract.
#include <iostream>

using namespace std;

// Base class
class Shape {
public:
	// pure virtual function providing interface framework.
	virtual int getArea() = 0;
	void setWidth(int w) {
		width = w;
	}

	void setHeight(int h) {
		height = h;
	}

protected:
	int width;
	int height;
};

// Derived classes
class Rectangle : public Shape {
public:
	int getArea() {
		return (width * height);
	}
};

class Triangle : public Shape {
public:
	int getArea() {
		return (width * height) / 2;
	}
};

int main(void) {
	Rectangle Rect;
	Triangle  Tri;

	Rect.setWidth(5);
	Rect.setHeight(7);

	// Print the area of the object.
	cout << "Total Rectangle area: " << Rect.getArea() << endl;

	Tri.setWidth(5);
	Tri.setHeight(7);

	// Print the area of the object.
	cout << "Total Triangle area: " << Tri.getArea() << endl;

	return 0;
}
===========================================================================
Interface(Pure Virtual Class) or pure abstract class:

Interfaces are nothing but a way to describe the behavior of a class without committing to the implementation of the class.
In C++ programming there is no built - in concept of interfaces.In order to create an interface, we need to create an abstract class which is having only pure virtual methods.In C++, Interfaces are also called pure abstract classes.
#include <iostream>
#include <iostream>

// Abstract base class acting as an interface
class Drawable {
public:
	virtual void draw() const = 0;  // Pure virtual function
};

// Another abstract base class
class Shape {
public:
	virtual double area() const = 0;  // Pure virtual function
};

// Derived class implementing both interfaces
class Circle : public Shape, public Drawable {
private:
	double radius;

public:
	Circle(double r) : radius(r) {}

	// Implement the pure virtual functions
	virtual double area() const override { //virtual keyword is not must
		return 3.1415 * radius * radius;
	}

	void draw() const override {
		std::cout << "Drawing a circle" << std::endl;
	}
};

int main() {
	// You cannot create an instance of an abstract class
	// Drawable drawable; // This will result in a compilation error

	// Create an instance of the derived class
	Circle circle(5.0);

	// Call member functions
	std::cout << "Area: " << circle.area() << std::endl;
	circle.draw();

	// Polymorphism: Use a base class pointer to call derived class functions
	const Drawable* drawablePtr = &circle;
	const Shape* shapePtr = &circle;
	drawablePtr->draw();
	std::cout << "Area: " << shapePtr->area() << std::endl;

	return 0;
}
/ tmp / BCOCst7A1S.o
Area : 78.5375
	   Drawing a circle
	   Drawing a circle
   Area : 78.5375
		  == == == == == == == == == == == == == =
<iomanip> = > setfill and setw
cctype required isalpha and ischar
sniprintf and sscanf needs stdio.h
snpritf total size + 1 > buffer size
sscanf needs & and it can be used to convert from string to integer
userliter only the overloading operator can be constexpr
user liter long l = 43_degree; //no ()
better to use using namespace std; const &
exception: stdexcept
abstract class: protected variable and public function in base class good to have.

