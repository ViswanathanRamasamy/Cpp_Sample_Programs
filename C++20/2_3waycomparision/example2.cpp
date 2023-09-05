/*
	3 way comparision operator in C++20.
	Source Code Location: https://github.com/ViswanathanRamasamy/Cpp_Sample_Programs
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

// 3 way comparision operator or spaceship operator. <=>
// its return type is strong ordering, weak ordering or partial ordering.
/* equality :
strong equality: we copy a value to all the element and we compare all the element of the class;
weak equatity: we copy to few elements of the class and we compare only theose element.

int main1()
{
    string m1("abc"), m2("ABC");
    cout <<m1.compare(m2); // a is higher than A
    return 0;
}


#include <string.h>
int main2()
{
    char m1[]="abc", m2[]="ABC";
    cout <<strcmp(m1,m2); // a is higher than A 
    return 0;
}

int main3()
{
    int n1=10;
    int n2=100.0f;
    auto result = n1<=>n2; //return type is strong, weak or partial ordering
	//Note Ordering can be compared only against 0
    cout <<std::boolalpha;
    cout << (result > 0) <<endl; //flase
    cout << (result == 0)<<endl; //false
    cout << (result < 0)<<endl; //true
    cout << typeid(result).name(); //strong ordering

    return 0;
}

// a==b; a.operator==(b)
// a!=b; !(a.operator==(b)
//default equality operator
class viswa
{
    public:
		bool operator==(const viswa &rhs) const=default; 
	   // != operator overloading is not required. compiler takecare
	   // do the comparsion from the order of the declaration
	   // pointer address are compared
	   //base class members are also compared
	   //Reference member varaiable is not supported.
    
    private:
		int i { 10};

};

int main4()
{
    viswa obj1, obj2;
    cout << std::boolalpha;
    cout << (obj1==obj2); //true
}

#include <compare>
#include <mutex>
using namespace std;

class viswa
{

    private:
		int b;
		int c;
		public:
		viswa(int y)
		{
			b = y;
		}
		bool operator==(const viswa &rhs) const=default; 
};

class viswa1: public viswa
{
    public:
		viswa1(int y): viswa{y}
		{
		
		}
		
		bool operator==(const viswa1 &rhs) const=default; 
	   //base class members are also compared
    
    private:
		int i { 10};

};


int main5()
{
    viswa1 obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj1==obj2); //false
}

//base class has the custom defined equality operation.
class viswa
{

    private:
		int b;
		int c;
		std::mutex m;
    public:
		viswa(int y)
		{
			b = y;
		}
		
		bool operator==(const viswa &rhs) const
		{
			return(this->c == rhs.c);
		}
};

class viswa1: public viswa
{

    public:
		viswa1(int y): viswa{y}
		{
		
		}
		
		bool operator==(const viswa1 &rhs) const=default; 
    
    private:
		int i { 10};

};


int main6()
{
    viswa1 obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj1==obj2); //true
}
///////
pointer comparision for the local varaibale:
class viswa1
{
    public:
		viswa1(int y)
		{
		
		}
		bool operator==(const viswa1 &rhs) const=default; 
    private:
		int i { 10};
		int *pi = &i;

};

int main7()
{
    viswa1 obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj1==obj2); //false
}

/// pointer address not changing ie pointer to the global address:
int cy;

class viswa1
{
    public:
		viswa1(int y)
		{
		
		}
		bool operator==(const viswa1 &rhs) const=default; 

    private:
		int i { 10};
		int *pi = {&cy}; //address to the global variable

};

int main8()
{
    viswa1 obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj1==obj2); //true
}
/////// we cannot have the referrence for the default comparaision operator. 
class viswa1
{
    public:
		viswa1(int y)
		{
		
		}
		bool operator==(const viswa1 &rhs) const=default; 
    private:
		int i { 10};
		int &ri = i;

};

int main9()
{
    viswa1 obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj1==obj2); //false
}
//in c++17 and below we need to overload the != operator since it is not default
class viswa1
{
    public:
        viswa1(int y)
		{
		
		}
		bool operator==(const viswa1 &rhs) const
		{
		    return(this->i == rhs.i);
		}
		bool operator!=(const viswa1 &rhs) const
		{
		    return!(*this == rhs);
		}
    private:
		int i { 10};
	

};
int main10()
{
    viswa1 obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj1 != obj2) <<endl; //false
}
//===================
//implict conversion can be on the right hand side:
class viswa1
{
    public:
        viswa1(int y)
		{
		
		}
		bool operator==(const viswa1 &rhs) const=default; 
    private:
		int i { 10};
		int *pi = &i;

};
int main11()
{
    viswa1 obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (12==obj2) <<endl;; //false
    cout << (12 != obj2) <<endl; //true
}
======
//===================
//implict conversion for the customized function:
class viswa1
{
    public:
        viswa1(int y)
		{
		    i = y;
		}
		bool operator==(const viswa1 &rhs) const 
		{
		    return(i == rhs.i);
		}
    private:
		int i ;

};
int main12()
{
    viswa1 obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (12 ==obj2) <<endl;; //true
    return 0;
}
//// if we are going to use the default 
spaceship operator then compiler will also add the default assignement and != assignement operator for us.
class viswa1
{
    public:
        viswa1(int y)
		{
		    i = y;
		}
		auto operator<=>(const viswa1 &rhs) const= default; 
	
    private:
		int i ;

};
int main13()
{
    viswa1 obj1(11), obj2(12), obj3(10);
    cout << std::boolalpha;
    cout << (12 ==obj2) <<endl; //true
    cout << (12 >obj1) <<endl; //true
    cout << (12 >=obj1) <<endl; //true
    cout << (obj3 < obj1) <<endl; //true
    cout << (obj3 <= obj1) <<endl; //true
    cout << (obj2 <= obj1) <<endl; //false
     auto result = (obj2 <= obj1);
    cout << typeid(result).name()<<endl; //b
    return 0;
}
===========
using spaceship operator where the dependent class:
class base
{
    public:
       base()
       {
           
       }
    
    auto operator<=>(const base &rhs) const= default;
    private:
       int i {10};
       

};

class child
{
    public:
        child(int y)
		{
		    i = y;
		}
	
	auto operator<=>(const child &rhs) const= default; 
	
    private:
		int i ;
        base b;
};
int main()
{
    child obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (12 ==obj2) <<endl; //true

    return 0;
}

===============================
//using spaceship operator where the dependent class doesnot have spaceship:
class base
{
    public:
       base()
       {
           
       }
       auto operator<(const base &rhs) const
        {
            return(i < rhs.i);
        }
        
        auto operator==(const base &rhs) const
        {
            return(i == rhs.i);
        }
    private:
       int i {10};
       

};

class child
{
    public:
        child(int y)
		{
		    i = y;
		}
	
	std::strong_ordering operator<=>(const child &rhs) const= default; 
	
    private:
		int i ;
        base b;
};
int main14()
{
    child obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (12 ==obj2) <<endl; //true

    return 0;
}