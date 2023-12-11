/*
	Below is the sample program for the C++ features.
	Source Code Location: https://github.com/ViswanathanRamasamy/Cpp_Sample_Programs
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/
===
//To remove the duplicate from the vector without doing sort?

How to check whether the insert into the map is passed or not ?

if (uniquemap.insert({*it, 10}).second) //true

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map <int,int> m = {{1,2},{2,2}};
	
	typedef map <int,int> ::iterator it;
	pair <it,bool> result = m.insert({2,2});
	
	if (result.second == false)
	{
		cout << "map insertion failed";
	}
	
	return 0;
}
====
output  map insertion failed.

same logic can be used for the set insertion check also. since the set and map avaoid the duplication element insertion.
====================
without using pair and iterator , how to find whether the element is inserted into the map?

removing the pair and checking the insertion:
int main()
{
	map <int,int> m = {{1,2},{2,2}};

	if (m.insert({2,2}).second == false)
	{
		cout << "map insertion failed";
	}
	
	return 0;
}
=====================================
Erase the duplicate element from the vector without changing the order of the vector?
header file required for array?
unerdered_set?

#include <iostream>
#include <unordered_set>
#include <vector>

void removeDuplicates(std::vector<int>& array) {
    std::unordered_set<int> uniqueSet;
    auto it = array.begin();

    while (it != array.end()) {
        if (uniqueSet.insert(*it).second) {
            // Element was inserted (not a duplicate)
            ++it;
        } else {
            // Element is a duplicate, erase it
            it = array.erase(it);
        }
    }
}

int main() {
    std::vector<int> numbers = {10, 2, 2, 3, 3, 10, 3, 4, 5, 5};

    // Remove duplicates from the vector while maintaining order
    removeDuplicates(numbers);

    // Print the modified vector
    for (const auto &num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}

===========================================
height of the binary tree?
a. What is the size of the empty node tree?
b. what is the header file required for the max?

#include <iostream>
#include <algorithm> // for std::max

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root) {
    if (root == nullptr) {
        return -1; // Height of an empty tree
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

int main() {
    // Example binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int treeHeight = height(root);

    std::cout << "Height of the binary tree: " << treeHeight << std::endl;

    // Don't forget to free memory allocated for the tree (not done in this simple example)
    
    return 0;
}
========================
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root) {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}
======================================
static class member variable is not considered in finding the sizeof the object.
frien function is not considered as the member function of the class.

#include<iostream> 

using namespace std; 
class Base1 { 
public: 
	Base1() 
	{ cout << " Base1's constructor called" << endl; } 
}; 

class Base2 { 
public: 
	Base2() 
	{ cout << "Base2's constructor called" << endl; } 
}; 

class Derived: public Base1, public Base2 { 
public: 
	Derived() 
	{ cout << "Derived's constructor called\n\n" << endl; 
	    
	} 
	
	Base2 obj2;
	Base1 obj1;
}; 

class Derived2 { 
public: 
	Derived2() 
	{ cout << "Derived2's constructor called" << endl; 
	    
	} 
	
	Base2 obj2;
	Base1 obj1;
}; 

int main() 
{ 
Derived d; 
Derived2 d2;
return 0; 
} 

Base1's constructor called
Base2's constructor called

Base2's constructor called
Base1's constructor called
Derived's constructor called


Base2's constructor called
 Base1's constructor called
Derived2's constructor called

=======================================================
i = (printf("Hello"), printf(" All Geeks ")); //11 (number of characters)
#define fun(x) (x)*10 //there should not be any space between the fun (x)
static int y = x;  //static variable can be initialized with const
==========
different ways to call the copy constructor using the object pointer?
t1 = new Point(10, 15);  // Normal constructor call 
t2 = new Point(*t1);   // Copy constructor call  
Point t3 = *t1;  // Copy Constructor call 
===============
how to write the definition of the function outside the class?

class Test {
    int value;
public:
    Test(int v = 0);
};
 
Test::Test(int v) {
    value = v;
}
==================
function returning the reference and stored as the reference and modiying it and calling back?

#include<iostream>
using namespace std;
int &fun() {
static int a = 10;
return a;
}

int main() {
int &y = fun();
y = y +30;
cout<<fun();//40
return 0;
}
========================
conversion operator betwen the class Bto A object: 
#include<iostream> 
using namespace std; 

class A { 
public: 
	A(int ii = 0) : i(ii) {} 
	void show() { cout << "i = " << i << endl;} 
private: 
	int i; 
}; 

class B { 
public: 
	B(int xx) : x(xx) {} 
	operator A() const { return A(x); } 
private: 
	int x; 
}; 

void g(A a) 
{ a.show(); } 

int main() { 
B b(10); 
g(b); 
g(20); 
getchar(); 
return 0; 
} 

//10
//20
=====================================
convesrion from the object to double?

#include <iostream>

class Inches {
private:
    double lengthInInches;

public:
    Inches(double length) : lengthInInches(length) {}

    // Conversion operator to double
    operator double() const {
        return lengthInInches;
    }
};

int main() {
    Inches myLength(12.5);

    // Implicit conversion using the conversion operator
    double lengthInDouble = myLength;

    std::cout << "Length in Inches: " << myLength << std::endl;
    std::cout << "Length in Double: " << lengthInDouble << std::endl;

    return 0;
}
=====================================
friend function:
cannot be inheritated.
can we declare the object inside the friend function?

#include <iostream>
using namespace std;
class A
{
protected:
    int x;
public:
    A() {x = 0;}
    friend void show();
};
 
class B: public A
{
public:
    B() : y (0) {}
private:
    int y;
};
 
void show()
{
    A a;
    B b;
    cout << "The default value of A::x = " << a.x << " ";
    cout << "The default value of B::y = " << b.y; //error 
}

==============================
public member function of the class A become the friend of class Base1
does the friend function is the member of the class?

friend function is not the member of the class.
#include <iostream>
using namespace std;
 
class B;
class A {
    int a;
public:
    A():a(0) { }
    void show(A& x, B& y);
};
 
class B {
private:
    int b;
public:
    B():b(0) { }
    friend void A::show(A& x, B& y);
};
 
void A::show(A& x, B& y) {
    x.a = 10;
    cout << "A::a=" << x.a << " B::b=" << y.b; //10 0
}
 
int main() {
    A a;
    B b;
    a.show(a,b);
    return 0;
}
===========================
friend class:
#include <iostream>

// Forward declaration of the FriendClass
class FriendClass;

class MyClass {
private:
    int privateMember;

public:
    MyClass() : privateMember(42) {}

    // Friend declaration for a class
    friend class FriendClass;
};

// Definition of the FriendClass
class FriendClass {
public:
    void accessPrivateMember(MyClass obj) {
        // FriendClass has access to the private member of MyClass
        std::cout << "Accessing private member from FriendClass: " << obj.privateMember << std::endl;
    }
};

int main() {
    MyClass obj;
    FriendClass friendObj;

    // FriendClass can access the private member of MyClass
    friendObj.accessPrivateMember(obj);

    // Accessing private member directly from main would result in a compilation error
    // std::cout << obj.privateMember << std::endl;  // Error: privateMember is private

    return 0;
}
======================================
where should be the location of catch(....)

catch (...)// this catch block should be always the last catch statement
    {
        cout << "default exceptionn";
    }
    catch (int param)
    {
        cout << "int exceptionn";
    }
=======================
when the destructor will called in exception after reaching catch or before ?

try {
    Test t1;
    throw 10; //destructor will be called before reaching the catch block
  } catch(int i) {
    cout << "Caught " << i << endl;
  }
  ==============
  
    try
    {
        fun();
    }
    catch (int ) //needn't have the variable if we are not using it.
    {
        cout << "Caught";
    }
=============================
In C++, the access specifiers (public, private, and protected) determine the visibility of class or struct members. By default, members of a 
class are private, while members of a struct are public. Additionally, when deriving a struct from a class or struct, 
the default access specifier is public. On the other hand, when deriving a class, the default access specifier is private.
#include <iostream>

// Base class with private members (default access specifier for class)
class MyBaseClass {
    int privateMemberBase;

};

// Derived struct with public members (default access specifier for struct)
struct MyDerivedStruct : MyBaseClass {
    int publicMemberDerived;

};

// Derived class with private members (default access specifier for class)
class MyDerivedClass : MyBaseClass {
    int privateMemberDerived;
};
===================================
class Test
{
    static int x;
    int *ptr;
    int y;
};
 
int main()
{
    Test t;
    cout << sizeof(t) << " ";//8
    cout << sizeof(Test *);// 4
}
===================================
can i have the global and local object with same name?
how to call the global object function?
which is inheritated from the bASS class?

data members is in inheritated from the base class

#include <iostream>
class Test
{
public:
	int i;
	void get();
};
void Test::get()
{
	std::cout << "Enter the value of i: ";
	std::cin >> i;
}
Test t; // Global object
int main()
{
	Test t; // local object
	t.get();
	std::cout << "value of i in local t: "<<t.i<<'n';
	::t.get(); 
	std::cout << "value of i in global t: "<<::t.i<<'n';
	return 0;
}

=========================================
2
2n
3
3n

===================
why we need the nested class?

The nested class is considered a member of the enclosing class and has access to its private and protected members. 
#include <iostream>

class OuterClass {
private:
    int outerPrivateData;

public:
    OuterClass(int data) : outerPrivateData(data) {}

    // Nested class declaration
    class InnerClass {
    public:
        void displayOuterData(const OuterClass& outerObj) {
            // The nested class can access private members of the outer class
            std::cout << "Outer private data accessed from InnerClass: " << outerObj.outerPrivateData << std::endl;
        }
    };
};

int main() {
    // Create an instance of the outer class
    OuterClass outerObj(42);

    // Create an instance of the nested class
    OuterClass::InnerClass innerObj;

    // Access the private data of the outer class through the nested class
    innerObj.displayOuterData(outerObj);  //42

    return 0;
}
================================
struct Base {
public:
    int x;
};
 
// is equivalent to
// struct Derived : public Base {}
struct Derived : Base {
===================================
enum class eyecolor:char{
    blue,green,brown
}eye;
sizeof(eye)//1
=================
enum rainbow{
    violet,
    indigo,
    blue,
    green,yellow,orange,red
}colors;
//sizeof(colors) 4

two enum cannot have the same vlue name but enum class have it.
enum class Color { Red,
                       Green,
                       Blue };
    enum class Color2 { Red,
                        Black,
                        White };
Color x = Color::Green;
==============================
assiging the values to the tuple in different ways
iterate the elements of the tuple?

// C++ program to iterate over the
// elements of an std::tuple
// using std:get()
#include <iostream>
#include <string>
#include <tuple>

// Driver Code
int main()
{
	// Declare a tuple and initialize
	// it using its constructor
	std::tuple<std::string, std::string,
			std::string>
		tup("Geeks", "for", "Geeks");
	std::cout << "Values of tuple: ";

	// std::get is used to access
	// the value of tuple.
	std::cout << std::get<0>(tup)
			<< " " << std::get<1>(tup)
			<< " " << std::get<2>(tup)
			<< std::endl;

	// Make the tuple using
	// std::make_tuple function
	tup = std::make_tuple("Hey", "Welcome to",
						"Geeksforgeeks");

	// Print tuple
	std::cout << "Values of tuple(Modified): ";
	std::cout << std::get<0>(tup) << " "
			<< std::get<1>(tup) << " "
			<< std::get<2>(tup)
			<< std::endl;

	return 0;
}
==================================================
How to return the value from the macro?
#include <iostream>

// Macro to perform some computation and return a value
#define COMPUTE_X \
    ({ \
        int x = 0; \
        for (int i = 0; i < 10; i++) { \
            if (i % 2 == 0) { \
                x += i; \
            } \
        } \
        x; \
    })

int main() {
    // Using the macro in an expression
    int result = COMPUTE_X;

    // Display the result
    std::cout << "Result from the macro: " << result << std::endl; //20

    return 0;
}
==========================================
what is the return type of the strchr and strtok?
what is th header file required for the strtok and strchr?
what is the position the strchr will point to if it matches?

#include <iostream>
#include <cstring>

int main() {
    const char* str = "Hello, World!";
    char searchChar = 'o';

    // Using strchr to find the first occurrence of 'o'
    const char* result = strchr(str, searchChar);

    if (result != nullptr) {
        // Character found, printing the rest of the string
        std::cout << "Substring after first occurrence of '" << searchChar << "': " << result + 1 << std::endl;
    } else {
        std::cout << "Character '" << searchChar << "' not found in the string." << std::endl;
    }

    return 0;
}
, World!
=========================================
what is the header file required strtok?

#include <iostream>
#include <cstring>

int main() {
    const char* ipAddress = "192.168.12.10";
    char ipCopy[std::strlen(ipAddress) + 1];
    std::strcpy(ipCopy, ipAddress);

    const char* delimiter = ".";

    // Use strtok to tokenize the IP address
    char* token = std::strtok(ipCopy, delimiter);

    while (token != nullptr) {
        // Print each part of the IP address
        std::cout << token << " ";
        
        // Get the next token
        token = std::strtok(nullptr, delimiter);
    }

    return 0;
}
192
168
12
10
====================================================
virtul base class
#include <iostream>

class Empty {
};

class Derived4 : virtual public Empty { //8
    int x; //4
};

int main() {
    std::cout << "Size of Derived4: " << sizeof(Derived4) << std::endl;

    return 0;
}

16
================================
local class :
A Local class cannot contain static data members. It may contain static functions though.
local class can contain the static method
local class function can be defined only inside the class
Member methods of the local class can only access static, const and enum variables of the enclosing function. 
Non-static variables (local variable) of the enclosing function are not accessible inside local classes.
local class access the global variable but can access the global static data.

// C++ program without any compilation error to demonstrate 
// that member methods of local class can only access static 
// and enum variables of the enclosing function 
#include <iostream> 
using namespace std; 

void fun() 
{ 
	static int x; 
	enum { i = 1, j = 2 }; 

	// Local class 
	class Test { 
	public: 
		void method() 
		{ 
		 //can also access the global variable
			cout << "x = " << x 
				<< endl; // fine as x is static 
			cout << "i = " << i 
				<< endl; // fine as i is enum 
		} 
	}; 

	Test t; 
	t.method(); 
} 

int main() 
{ 
	fun(); 
	return 0; 
}
========================================
whether the destructor will be called after return statement or before return statement?

int i;
  
class A
{
public:
    ~A()
    {
        i=10;
    }
};
  
int foo()
{
    i=3;
    A ob;
    return i;
}
  
int main()
{
    cout << foo() << endl; //3
    return 0;
}
============================================
Which of the following operators cannot be overloaded?

. (Member Access or Dot operator)
?: (Ternary or Conditional Operator )
:: (Scope Resolution Operator)
.* (Pointer-to-member Operator )
==========
pointer to member operator?
class MyClass {
public:
    int myVariable;

    MyClass(int value) : myVariable(value) {}
};

int main() {
    MyClass obj(42);

    // Pointer to member
    int MyClass::*ptrToMember = &MyClass::myVariable;

    // Accessing the member through the pointer
    int value = obj.*ptrToMember;

    std::cout << "Value: " << value << std::endl;

    return 0;
}

==============================================
#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;
public:
    Complex(int r = 0, int i =0)
    {
        real = r;
        imag = i;
    }
    friend ostream & operator << (ostream &out, const Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imag;
    return out;
}

int main()
{
    Complex c1(10, 15);
    cout << c1;
    return 0;
}
===================================================
which one called first new or constructor?

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
 
using namespace std;
 
class Test {
    int x;
public:
    void* operator new(size_t size);
    void operator delete(void*);
    Test(int i) {
        x = i;
        cout << "Constructor called n";
    }
    ~Test() { cout << "Destructor called n"; }
};
 
 
void* Test::operator new(size_t size)
{
    void *storage = malloc(size);
    cout << "new called n";
    return storage;
}
 
void Test::operator delete(void *p )
{
    cout<<"delete called n";
    free(p);
}
 
int main()
{
    Test *m = new Test(5);
    delete m;
    return 0;
}

new called
Constructor called
Destructor called
delete called
======================================
functor()

#include<iostream>
using namespace std;
 
class Point {
private:
  int x, y;
public:
  Point() : x(0), y(0) { }
  Point& operator()(int dx, int dy);
  void show() {cout << "x = " << x << ", y = " << y; }
};
 
Point& Point::operator()(int dx, int dy)
{
    x = dx;
    y = dy;
    return *this;
}
 
int main()
{
  Point pt;
  pt(3, 2);
  pt.show();
  return 0;
}
//3 2
======================================
 Template is an example of compile time polymorphism.
 what happens if we dont specify the template parameter in function calling?
 
 
 #include <iostream>
using namespace std;
 
template <typename T>
T max(T x, T y)
{
    return (x > y)? x : y;
}
int main()
{
    cout << max(3, 7) << std::endl;
    cout << max(3.0, 7.0) << std::endl;
    cout << max(3, 7.0) << std::endl; //error since both are different data type
    return 0;
}
===================================

In the context of class templates in C++, specifying the type during instantiation (MyClass<int>) is necessary because it tells the compiler 
what concrete type to substitute for the template parameter T. Unlike function templates where type deduction can often be performed by the compiler,
class templates require explicit type information during instantiation.

template <class T>
class MyClass {
    T myVariable;
public:
    MyClass(T value) : myVariable(value) {}
    T getValue() { return myVariable; }
};

int main() {
    MyClass<int> myObject(42);
    std::cout << myObject.getValue() << std::endl; // Output: 42

    MyClass<std::string> anotherObject("Hello");
    std::cout << anotherObject.getValue() << std::endl; // Output: Hello

    return 0;
}
=========================================================================================================
deriving the class from the template class with specified type in the derived class?
if the derived class is not of template type , then base class constructor need not be called with type. it will automatically call the base class constructor
based on the type of the argument it takes. here it is string.
MyDerivedClass(const std::string& value) : MyClass<string>(value)//string is not must

can we access the base variable in the derived class?

#include <iostream>
#include <string>

// Template class definition
template <class T>
class MyClass {
public:
    T myVariable;

    MyClass(T value) : myVariable(value) {}

    void printValue() {
        std::cout << "Value: " << myVariable << std::endl;
    }
};

// Derived class from the template class
class MyDerivedClass : public MyClass<std::string> {
public:
    MyDerivedClass(const std::string& value) : MyClass(value) {}

    void printDerivedValue() {
        std::cout << "Derived Value: " << myVariable << std::endl;
    }
};

int main() {
    // Instantiating the derived class
    MyDerivedClass derivedObject("Hello, Derived!");

    // Accessing members from the base class
    derivedObject.printValue();

    // Accessing members from the derived class
    derivedObject.printDerivedValue();

    return 0;
}

=========================================================
deriving the class from the template class with variable specified type?
if the derived class is of template type , then base class constructor needs to be called with type. it is must
#include <iostream>
#include <string>

// Template class definition
template <class T>
class MyClass {
public:
    T myVariable;

    MyClass(T value) : myVariable(value) {}

    void printValue() {
        std::cout << "Value: " << myVariable << std::endl;
    }
};

// Derived class from the template class
template <class T>
class MyDerivedClass : public MyClass<T> {
public:
    MyDerivedClass(T value) : MyClass<T>(value) {} //

    void printDerivedValue() {
        std::cout << "Derived Value: " << this->myVariable << std::endl;
    }
};

int main() {
    // Instantiating the derived class with int as the template parameter
    MyDerivedClass<int> derivedObject(42);

    // Accessing members from the base class
    derivedObject.printValue();

    // Accessing members from the derived class
    derivedObject.printDerivedValue();

    return 0;
}

=========================================================
template class with static variable and defi ing the static variable outside the class?
defining the template class instance with same tyrp int , int and double?

template <class T>
class Test
{
private:
    T val;
public:
    static int count;
    Test()  {   count++;   }
};
 
template<class T>
int Test<T>::count = 0;
 
int main()
{
    Test<int> a;
    Test<int> b;
    Test<double> c;
    cout << Test<int>::count   << endl;
    cout << Test<double>::count << endl;
    return 0;
}
//2
//1
============================================
template with default data type?

template<class T, class U, class V=double>
class A  {
    T x;
    U y;
    V z;
    static int count;
};
 
int main()
{
   A<int, int> a;
   A<double, double> b;
   cout << sizeof(a) << endl; //16
   cout << sizeof(b) << endl; //24
   return 0;
}
=================================================
find the minimum of the given element using the template?

template <class T, int max>
int arrMin(T arr[], int n)
{
   int m = max;
   for (int i = 0; i < n; i++)
      if (arr[i] < m)
         m = arr[i];
 
   return m;
}
 
int main()
{
   int arr1[]  = {10, 20, 15, 12};
   int n1 = sizeof(arr1)/sizeof(arr1[0]);
 
   char arr2[] = {1, 2, 3};
   int n2 = sizeof(arr2)/sizeof(arr2[0]);
 
   cout << arrMin<int, 10000>(arr1, n1) << endl;
   cout << arrMin<char, 256>(arr2, n2);
   return 0;
}
10
1
=====================================
can we modify the non parameter type argument?

template <int i>
void fun()
{
   i = 20; //cannot modify the non type parameter
   cout << i;
}
 
int main()
{
   fun<10>();
   return 0;
}
============================
calling the empty argument  template function:
different way of calling

template <> 
int max (int &a, int &b)

template <> 
int max <int>(int &a, int &b)

template <class T>
T max (T &a, T &b)
{
    return (a > b)? a : b;
}
 
template <>
int max <int> (int &a, int &b)
{
    cout << "Called ";
    return (a > b)? a : b;
}
 
int main ()
{
    int a = 10, b = 20;
    cout << max <int> (a, b);
}
called 20


==============================================
template specialization?
what the data type should be and why?

using namespace std;
  
template<int n>
 struct funStruct
{
    static const int val = 2*funStruct<n-1>::val;
};
  
template<> 
struct funStruct<0>
{
    static const int val = 1 ;
};
  
int main()
{
    cout << funStruct<10>::val << endl;
    return 0;
}

//1024
==========================================
base pointer to the derived class 
base object reference to the derived class object?

#include<iostream>
using namespace std;
 
class Base
{
public:
    virtual void show() { cout<<" In Base n"; }
};
 
class Derived: public Base
{
public:
    void show() { cout<<"In Derived n"; }
};
 
int main(void)
{
    Base *bp = new Derived;
    bp->show();
 
    Base &br = *bp;
    br.show();
 
    return 0;
}
===============================
using scope resolution in the base pointer:
class Base
{
public:
    virtual void show() { cout<<" In Base n"; }
};
 
class Derived: public Base
{
public:
    void show() { cout<<"In Derived n"; }
};
 
int main(void)
{
    Base *bp = new Derived;
    bp->Base::show();  // Note the use of scope resolution here
    return 0;
}
======================================
2d dyamic and 1d dynamic array?
can we delete the pointer twice?
can we delete the null pointer

int **arr = new int *[10];
int main()
{
    int *ptr = new int;
    delete ptr;
    delete ptr; //behaviour is undefined
    return 0;
}

can we delete the null pointer: yes no issues
===========================
int *ptr = NULL;
delete ptr; //allowed ... no effect

  int main()
{
    const char* p = "12345";
    const char **q = &p;
    *q = "abcde";
    const char *s = ++p;
    p = "XYZWVU";
    cout << *++s; //c
    cout <<*p <<endl; //x
    cout <<*q; //XYZWVU
    return 0;
}
============================
const reference 

#include <iostream>

int main() {
    // Declare a const integer
    int constValue = 42;

    // Reference to a const integer
    const int& constReference = constValue;

    // Output the value through the reference
    std::cout << "Value through constReference: " << constReference << std::endl;

    return 0;
}
//reference cannot be incremented.
=====================================
sizeof the derived class for the virtual and non virtual base class?

#include<iostream> 
using namespace std; 

class base { 
int arr[10];	 
}; 

class b1: virtual public base { }; 

class b2: virtual public base { }; 

class derived: public b1, public b2 {}; 

int main(void) 
{ 
cout<<sizeof(derived); //48 
getchar(); 
return 0; 
} 

//if the virtual keyword is not there then the size will be 80.

====================
local class?
advantage:
Temporary and Helper Classes
Encapsulation and Modularity:
Information Hiding:

int main()  
{  
   class student {  
       public:
      int rno = 10; 
   } v; 
    
   cout<<v.rno; 
}
//allpwed 10
==========================
cin is object of istream class.
namespace first 
    { 
        int var = 5; 
    } 
    namespace second 
    { 
        double var = 3.1416; 
    } 
    int main () 
    { 
        int a; 
        a = first::var + second::var; 
        cout << a; 
        return 0; 
   } 
  ======================
  int a = 32, *ptr = &a; 
  
  int main() 
{ 
    int a = 35; 
    int b = 12; 
    printf("%d ", ~a); 
    printf("%d ", ~ - b); 
    return 0; 
} 
a) -36 11
===========================
int main() 
{ 
    int a = 12; 
    int b = 25; 
    int c = 1; 
    printf("%d", a ^ b && c); //1
    return 0; 
}
====
represent of 
2's complement
1's complement

how the - number is represented in computer ?

int main() 
{ 
    unsigned char a = -8; //2s complement 11111000
    unsigned char b = a >> 1; 
    printf("%d\n", b); 
} 

To find the 2's complement of a decimal number, you generally follow these steps:

Represent the number in binary.
Invert all the bits (change 0s to 1s and vice versa).
Add 1 to the result.
=========================
ones compliement number:
Represent -8 in binary: -8 is represented as 1000 in 8-bit binary.
Invert all the bits: Inverting 1000 gives 0111.
So, the one's complement of -8 in 8-bit binary is 0111.
=====================================
how to create the address of the global variable as the argument to the function?
how to pass the global variable as the argument using scope resolution operator?

#include <iostream> 
using namespace std; 
int a = 90; 

int fun(int x, int *y = &a) 
{ 
	*y = x + *y; 
	return x + *y; 
} 

int main() 
{ 
	int a = 5, b = 10; 

	a = fun(a); 
	cout << a << " " << b << endl; 

	b = fun(::a,&a); 
	cout << a << " " << b << endl; 

	return 0; 
} 

100   10
195   290
======================================
how to create the reference for the global variable?

int &x = ::a; 
  
    ::a += fun(&x); 
======
pointer increment for the array?

array+1 is a pointer to the second element in the array.
&array+1 is a pointer to the memory location after the end of the array.
&(array+1) is a pointer to the second element in the array.
=====================
#include <iostream> 
using namespace std; 

int main() 
{ 
	char *A[] = { "abcx", "dbba", "cccc"}; 
	char var = *(A+1) - *A+1; //gives the difference ebtween the number of character difference 5+1
	cout << (*A + var); //bba
} 
=====================================
can the union have the function and construictor?
struct can have the constructor and destructor in c++?
yes
union A {
  int a;
  unsigned int b;
  A() { a = 10; }
  unsigned int getb() {return b;}
};
 
int main()
{
    A obj;
    cout << obj.getb();
    return 0;
}
Like struct and class, union can have methods. Like struct and unlike class, members of union are public by default. Since data members 
of union share memory, the value of b becomes same as a.
==============================================
How can we prevent the object creation using new?
// Make the new operator private
a. private:
    // Make both the operator new functions private
    static void* operator new(std::size_t size);
    static void* operator new[](std::size_t size);
	
=========================================
creating the class object by overloading the new operator?
CustomNewObject* obj = new CustomNewObject; //will call the class new operator
syntax to overload the new operator and array of the new operator?

#include <iostream>

class CustomNewObject {
public:
    // Custom operator new functions
    static void* operator new(std::size_t size) {
        std::cout << "Custom operator new called for single object." << std::endl;
        // Implement your custom memory allocation logic here
        return ::operator new(size);
    }

    static void* operator new[](std::size_t size) {
        std::cout << "Custom operator new called for array." << std::endl;
        // Implement your custom memory allocation logic here
        return ::operator new[](size);
    }

public:
    // Public constructor and other member functions
    CustomNewObject() {
        std::cout << "Creating an object." << std::endl;
    }

    // Public destructor
    ~CustomNewObject() {
        std::cout << "Destroying an object." << std::endl;
    }

    // Public static member function to create an object using new
    static CustomNewObject* createObject() {
        return new CustomNewObject;
    }

    // Public static member function to create an array of objects using new
    static CustomNewObject* createArray(std::size_t count) {
        return new CustomNewObject[count];
    }
};

int main() {
    // Creating a single object using new
    CustomNewObject* obj = CustomNewObject::createObject();

    // Creating an array of objects using new
    CustomNewObject* objArray = CustomNewObject::createArray(3);

    // Use the objects

    // Delete the single object
    delete obj;

    // Delete the array of objects
    delete[] objArray;

    return 0;
}

==========================================
How can we make a C++ class such that objects of it can only be created using new operator? If user tries to create an object directly, the program 
produces compiler error.
By making destructor private
// Objects of test can only be created using new
class Test
{
private:
    ~Test() {}
friend void destructTest(Test* ); // no need for the argumnet name at the declaration
};
 
// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
    delete ptr;
}
 
int main()
{
    // create an object
    Test *ptr = new Test;
 
    // destruct the object
    destructTest (ptr);
 
    return 0;
}
===============================================
vector pointer for the class pointer and class?
does v1.clear will delete the object memory of a;

class a 
{ 
public : 
    ~a() 
    { 
        cout << "destroy"; 
    } 
}; 
int main() 
{ 
   vector <a*> *v1  = new vector<a*>; 
   vector <a> *v2  = new vector<a>; 
   
   // Clear the vector (remove the pointers)
    v1->clear(); //v1.clear will not delete the object memory of a;

    // Delete the vector itself
    delete v1;
   return 0; 
}
no the destructor is not called
============================================
Function overloading declarations not allowed

    int fun(int x, int y);
         void fun(int x, int y); 
2) Functions that differ only by static keyword in return type

    int fun(int x, int y);
         static int fun(int x, int y); 
int fun(int *ptr, int n);
int fun(int ptr[], int n); 
4) Two parameter declarations that differ only in their default arguments

int fun( int x, int y); 
int fun( int x, int y = 10); 
=================
what is the default value of the global array?

int x[100]; 
int main() 
{ 
    cout << x[99] << endl; //00
} 		 
================
class having the const and non const function . function getting called by the const object and non const object
#include <iostream>

using namespace std;
#include <iostream>
using namespace std;

class Test {
protected:
	int x;

public:
	Test(int i)
		: x(i)
	{
	}
	void fun() const
	{
		cout << "fun() const called " << endl;
	}
	void fun() { cout << "fun() called " << endl; }
};

int main()
{
	Test t1(10);
	const Test t2(20);
	t1.fun(); //will call non const function. if there is no function it will call const function
	t2.fun(); //will call const 
	return 0;
}
================================
overloading reference and const reference?

void fun(const int &i) 
{ 
    cout << "fun(const int &) called "; 
} 
void fun(int &i) 
{ 
    cout << "fun(int &) called " ; 
} 
int main() 
{ 
    const int i = 10; 
    fun(i); 
    return 0; 
} 

fun(const int &) called 
=============================================
const pointer to integer?
int *const is a constant pointer to integer This means that the variable being declared is a constant pointer pointing to an integer.
#include <stdio.h>
 
int main(){
    int q = 5;
    int *const p = &q;
 
    //Valid
    *p = 7; 
 
    const int q2 = 7;
 
    //Compilation error
    p = &q2; 
 
    return 0;
}
===================================
pointer to constant?
int const* is pointer to constant integer 
int main(){
    const int q = 5;
    int const* p = &q;
 
    //Compilation error
    *p = 7;
 
    const int q2 = 7;
 
    //Valid
    p = &q2; 
     
    return 0;
}
============================
=====================================
passing the tuple as the parameter pack?
find the sizeof the parameter pack
find the sizeof the tuple
iterate throgh the elements of the tuple using apply and lamda?
can the we apply the tuple_size in the parameter 
decltype will work on the object or type?


std::size_t length = std::tuple_size<decltype(tup)>::value; why there is no typename here since we not using the Ts here?
std::size_t length = std::tuple_size<decltype(ts)>::value; //error

// C++ program to iterated thorough
// all values. I equals number
// of values in tuple
#include <iostream>
#include <string>
#include <tuple>

template <typename... Ts> //This declares a template with a parameter pack Ts, which represents the types of the elements in the tuple.
void printTuple(std::tuple<Ts...> tup)
{

	// Getting size of tuple
	std::size_t length = sizeof...(Ts); //This is a compile-time operator that evaluates to the number of types in the parameter pack Ts

	// Using std::apply to print elements
	std::apply(

		// A lambda function
		[length](auto const&... ps) { //parameter pack ps //[length](const Ts&... ps) {
			std::cout << "[ ";
			int k = 0;

			// Variadic expansion used.
			((std::cout << ps
						<< (++k == length ? "" : "; ")),
			...);

			std::cout << " ]";
		},
		tup);
}

// Driver Code
int main()
{
	// Initialize the tuple
	std::tuple<std::string,
			std::string, std::string>
		tup("Geeks", "for", "geeks");

	// Function call
	printTuple(tup); //or use make_tuple
	// printTuple(42, 3.14, "Hello"); will give the error in the case print function tuple
	return 0;
}

[ Geeks; for; geeks ]
======================================
what is other ways to pass the tuple to the template ie index as the non parameter type and tuple data type as the parameter type?

#include <iostream>
#include <tuple>
#include <typeinfo>

template <std::size_t Index, typename Tuple>
void printElement(const Tuple tuple1) {
    using ElementType = std::tuple_element<Index, decltype(tuple1)>::type;
    std::cout << "Element at index " << Index << ": " << std::get<Index>(tuple1)
              << " (Type: " << typeid(ElementType).name() << ")\n";
}

int main() {
    std::tuple<int, double, std::string> myTuple(42, 3.14, "Hello");
    printElement<0>(myTuple);
    printElement<1>(myTuple);
    printElement<2>(myTuple);

    return 0;
}
========================================================
what is tuple?
what is tuple_element?
what is tuple_size vs sizof of tuple?

A tuple is an object that can hold a number of elements. The elements can be different data types. The elements of tuples are initialized as
 arguments in the order in which they will be accessed.

how to find the size of the tuple?

std::tuple<std::string, std::string, std::string> tup;
std::size_t tupleSize = sizeof(tup); /3*32; sizeof the string class is 32 bytes
=====
declare a vairable which is defined of another type:
// Declare a tuple
std::tuple<int, double, char, std::string> myTuple(1, 3.14, 'a', "Hello");

// Use decltype to declare another variable with the same type as myTuple
decltype(myTuple) anotherTuple;
----------------------------------
How to find the number of elements in the tuple?
what is need in 
tuple_size 
tuple_element ?

how to get the type and value from the above?
how to find the size of the array?



#include <iostream>
#include <tuple>

int main() {
    // Create a tuple
    std::tuple<int, double, char, std::string> myTuple(1, 3.14, 'a', "Hello");

    // Find the number of elements in the tuple
    constexpr size_t tupleSize = std::tuple_size<decltype(myTuple)>::value;

    // Display the number of elements in the tuple
    std::cout << "The number of elements in the tuple is: " << tupleSize << std::endl;

    return 0;
}
===============
tuple can also find the size of the array
// Array of size 6 
    array<int, 6> a; 
  
    // Find size using tuple_size 
    cout << tuple_size<decltype(a)>::value; //or a.size()
=================
tuple_size and tuple_element needs the object or data type?
tuple_size to find the sizeof the array and tuple?
how to compare the sizeof the tuple comparision in compile time?
how to get the return type of the tuple_size and tuple_emenet?

std::tuple_element is a template class provided by the C++ Standard Library that allows you to access the type of an element in a tuple or an
 array at a specified index. You would typically use std::tuple_element.

std::tuple<int, double, std::string> myTuple;
using ElementType = std::tuple_element<1, std::tuple<int, double, std::string>>::type;
//using ElementType = std::tuple_element<1, decltype(myTuple)>::type;
ElementType myElement;  // Now 'myElement' has the type double.

std::array<float, 5> myArray;
using ElementType = std::tuple_element<2, decltype(myArray)>::type;
ElementType myElement;  // Now 'myElement' has the type float.

 
===================================
checking the compilation condition check for the tuple size?

constexpr std::size_t tupleSize = std::tuple_size<decltype(myTuple)>::value;

// Ensure that Index is within the bounds of the tuple
static_assert(0 < tupleSize, "Index should be greater than or equal to 0");
static_assert(2 < tupleSize, "Index should be less than the tuple size");

=========================================
a. passing the index and tuple data type as the non parameter type to the template and extracting the type of the index?
b. why we cannot pass the tuple as the non parameter type
Non-type template parameters must be compile-time constants, and std::tuple is a complex type that can't be used as a non-type parameter.
c.  Type Template Parameters and Non-Type Template Parameters:

Type Template Parameters:
Type template parameters allow you to create templates that can work with different data types
template <typename T>
T add(T a, T b) {
    return a + b;
}

Non-Type Template Parameters:
Non-type template parameters allow you to use values (or values derived from them) as template parameters
template <int N>
void printNTimes(const char* message) {
    for (int i = 0; i < N; ++i) {
        std::cout << message << std::endl;
    }
}
=================================
passing the index and the type of the tuple as the non parameter type?
#include <tuple>
#include <iostream>

template <std::size_t Index, typename Tuple>
void printElementType() {
    // Using std::tuple_element<Index, Tuple>::type to get the type
    typename std::tuple_element<Index, Tuple>::type elementType;

    // Do something with elementType...
}

int main() {
    // Creating a tuple with int, double, and string
    std::tuple<int, double, std::string> myTuple;

    // Calling the function for each index in the tuple
    printElementType<0, decltype(myTuple)>();
    printElementType<1, decltype(myTuple)>();
    printElementType<2, decltype(myTuple)>();

    return 0;
}

======================================
passing the tuple as the parameter type and index as the non parameter type?
when you extracting the type from the tuple inside the template , then the typename is required since the Tuple is context
getting the data type: tuple_element from the template parameter argument 
getting the data type: tuple_element from the template parameter argument object; //note it should be reference object
what header file and function name is required to print data type name?

// using ElementType = typename std::tuple_element<Index, decltype(tuple1)>::type;
#include <iostream>
#include <tuple>
#include <typeinfo>

template <std::size_t Index, typename Tuple>
void printElement(const Tuple& tuple) {
    using ElementType = typename std::tuple_element<Index, Tuple>::type;
    std::cout << "Element at index " << Index << ": " << std::get<Index>(tuple) << " (Type: " << typeid(ElementType).name() << ")\n";
}

int main() {
    std::tuple<int, double, std::string> myTuple(42, 3.14, "Hello");
    printElement<0>(myTuple);
    printElement<1>(myTuple);
    printElement<2>(myTuple);

    return 0;
}
Element at index 0: 42 (Type: i)
Element at index 1: 3.14 (Type: d)
Element at index 2: Hello (Type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE)
===============================================
extract the type from the array of the element and check the type is same or not?
header file required?
tuple header file required?
array header file required?
type comparision header file?

// C++ program to implement 
// the above approach 

#include <array> 
#include <iostream> 
#include <tuple> 
#include <type_traits> 
using namespace std; 

// Driver code 
int main() 
{ 
	// Define array 
	array<int, 3> data{ 3, 5, 10 }; 

	// Type of element at index 0 
	using type = std::tuple_element<0, 
									decltype(data)>::type; 

	// Compare type with int 
	// returns true 
	cout << std::is_same<type, 
						int>::value 
		<< '\n'; 

	// Compare type with char 
	// returns false 
	cout << std::is_same<type, 
						char>::value 
		<< '\n'; 
}

typename std::tuple_element<Index, Tuple>::type elementType;
===================================================
How to find the data type of the vector?
std::cout <<typeid(std::vector<int>::value_type).name();
====================================================
find the type from the template parameter where T is vector of <int>
a. using object
b, using struct

template <typename T>
struct MyContainer {
    using value_type1 = typename T::value_type; // 'typename' is required here since we are using T
};

int main() {
    MyContainer<std::vector<int>> container;
    // Use 'typename' to indicate that 'value_type' is a type
	std::cout << typeid(typename MyContainer<std::vector<int>>::value_type1).name() << std::endl; //using typename is optional
    std::cout << typeid(decltype(container)::value_type1).name() << std::endl;
    return 0;
}
========
returning the template parameter as the vector of int

template <typename T>
struct MyContainer {
    using value_type1 = T; // 'typename' is not required here
    
};

int main() {
    MyContainer<std::vector<int>> container;
    // Use 'typename' to indicate that 'value_type' is a type
    std::cout << typeid(decltype(container)::value_type1).name() << std::endl;
    return 0;
}
vector<int>
=======================
Note:
condition check in compilation time?
is typename is required when want the template parameter as the vector of int?
get the type from the vector template parameter?

definition the stl::array?
getting the index value in the non parameter type?
compile time condition check?
return type of the tupe_size and tuple_element
condition check in cout?
call the global new operator?
c++ the negative number are represented in  which compliement?
xor 
template specialization?
Encapsulation?
modularity?
different ways to pass 1d array?
different ways to pass 2d array?
where to specify the default data type in template?
return object&
template requires the must  type to specified in class or function?
overloading the operator << without using the friend keyword?




return object& needs return *this
template requires the must  type to specified  in the class and for the function compiler automatically decides it.

~1 . ~-1
array<int, 3> data{ 3, 5, 10 }; 

template <std::size_t Index, typename Tuple>
void printElementType(Tuple t)
printElementType<0>(tup)

static_assert(condition,"message");
return type of the tupe_size ::value and tuple_element ::type
cout << ()? "" :"";

return ::operator new(size);
~1 = 1+1 = 2 ; -2
-1 = -1+1 =0 

pointer to member access operator?
where the local function is defined?

make_tuple require the data type?
make_shared <datatype> is it must?
coversion function?


inside the class b{
operator double() const {
        return lengthInInches;
    }
}
double lengthInDouble = objectB;

make_shared <datatype> is it must? Yes
int main() {
    // Create a shared pointer to a dynamically allocated int
    std::shared_ptr<int> ptr ;
    ptr = std::make_shared<int>(42); //<int> is must

    // Use the shared pointer as needed

    return 0;
}

std::tuple<std::string, std::string, std::string> tup ;
tup = std::make_tuple<std::string, std::string, std::string>("Hey", "Welcome to", "Geeksforgeeks");
tup = std::make_tuple("Hey", "Welcome to", "Geeksforgeeks"); //std::make_tuple, the template parameters are automatically deduced from the arguments you pass

local class function is defined inside the class itself.

int MyClass::*ptrToMember = &MyClass::myVariable;
negative numbers are represented in 2's complimenet in computer

xor bits are same then ouput is zero

template specialization:
static const int val = 2*funStruct<n-1>::val;

Encapsulation: // Accessing and modifying private members through public functions
Modularity is the concept of breaking down a program into smaller, independent, and interchangeable parts called modules. 
Each module represents a specific functionality and can be developed, tested, and maintained independently.
math class can be considered as one module and maon function can be considered as other module


void printVector(const std::vector<int>& vec)
std::vector<int> myVector = {1, 2, 3, 4, 5};
printVector(myVector);

template <std::size_t N>
void printArray(const std::array<int, N>& arr) 
std::array<int, 5> myArray = {1, 2, 3, 4, 5};
printArray(myArray);

void printArray(int arr[], int size)
int myArray[] = {1, 2, 3, 4, 5};
int size = sizeof(myArray) / sizeof(myArray[0]);

printArray(myArray, size);
====
template <std::size_t N, typename T>
void printArray(const std::array<T, N>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};

    printArray(myArray);

    return 0;
} 
=======
const int ROWS = 3;
const int COLS = 4;

void printArray(int arr[][COLS], int rows, int cols)
int myArray[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
printArray(myArray, ROWS, COLS);
===
void printArray(int (*arr)[COLS], int rows, int cols)
printArray(myArray, ROWS, COLS);

const int ROWS = 3;
const int COLS = 4;

void printVector(const std::vector<int>& vec, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << vec[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
}

====
#include <iostream>
#include <vector>

void printVector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> myVector = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    printVector(myVector);

    return 0;
}
======
default template argument?
template<class T, class U, class V=double>
=====================================
overloading the << in the class?
how to call the overload operator?

myComplex.operator<<(std::cout) << std::endl;
myComplex<<(std::cout) << std::endl;

#include <iostream>

class Complex {
public:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload operator<< as a member function
    std::ostream& operator<<(std::ostream& out) const {
        out << real << " + " << imag << "i";
        return out;
    }
};

int main() {
    Complex myComplex(3.0, 4.5);

    // Use the overloaded operator<< to print the Complex object
    myComplex.operator<<(std::cout) << std::endl;

    return 0;
}
=============================
T is vector<int>
using value_type1 = T; // 'typename' is not required here
using value_type1 = typename T::value_type;
=======================
