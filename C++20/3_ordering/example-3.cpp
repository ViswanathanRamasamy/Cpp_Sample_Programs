/*
	3 way comparision operator in C++20.
	Source Code Location: https://github.com/ViswanathanRamasamy/Cpp_Sample_Programs
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

a < b ; a.operator <=> b < 0
a >= b ; a.operator <=> b >= 0
12 >= b; b.operator <=> (12) < 0
a==b; a.operator == (b);  !(a < b) && !(b < a).

>= operator using > or < 

(5 >= 6) ==> !(5 < 6) ==> !(6 > 5)
(5 <= 6) ==> !(5 > 6) ==> !(6 < 5)

unlike the constructor and destructor are added by the compiler by default if the user haven't written.
 <=> operator is not inserted by the compiler by default.
compiler use the spaceship operaor to generate the other comparision operator but not viceversa
// if we overload the spaceship operator then the == operator will not be inserted by the compiler and we needs
write our own == operator

//using the <=> operator default:
//// compiler generates all six two-way comparison operators
// difference between the equal or equality and equivalent or equaliance

if(a == b){
     std::cout << "a and b are equal\n";
}
if"aA" < "aa" and "aa" < "aA"{
     std::cout << "a and b are equivalent\n";
}

/// 3 way comparision operator can only be compared against zero.
//ie int a =0; ((a<=>b) > a) will not work.
//we can cosider
enum weak_ordering{
	less =-1,
	equivalent,
	greater,
};

enum strong_ordering{
	less =-1,
	equal,
	equivalent,
	greater,
};

partial ordering is based on the strongg and weak ordering:

    std::partial_ordering operator<=>(const Person& other) const {
        if (isnan(age) || isnan(other.age)){
			return std::partial_ordering::unordered;
		}else if (age < other.age) {
            return std::partial_ordering::less;
        } else if (age > other.age) {
            return std::partial_ordering::greater;
        } 
		else {
            return std::partial_ordering::equivalent;
        }
		
// only if we mark <=> operator as default the == operator and !=operator is inserted by the compiler
class child
{
    public:
        child(int y)
		{
		    i = y;
		}
	//for default function argument name is not required here rhs is not must.
	strong_ordering operator<=> (const child &rhs) const= default; 
	
    private:
		int i ;
};
int main1()
{
    child obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj1 == obj2) <<endl; //false
    cout << (obj1 < obj2) <<endl;  //true
    cout << ((obj1 <=> obj2) < 0) <<endl; //true

    return 0;
}
================================================================
// overload the <=> operator , inthat case no == and != operator inserted by the compiler
#include <iostream>

using namespace std;

class ID 
{
    public:
    ID(string d, int v)
    {
        domain = d;
        value = v;
    }
    
    string domain;
    int value;
    
    auto operator <=> (const ID& rhs) const
    {
        return (value <=> rhs.value);
    }
};

int main2()
{
    ID value1("org", 123),value2("org", 123);
    //cout << (value1 == value2); //error no equal comparision
	 cout << ((value1 <=> value2) == 0); //1
    return 0;
}

//how to call the <=> member variable type
class ID 
{
    public:
    ID(string d, int v)
    {
        domain = d;
        value = v;
    }
    
    string domain;
    int value;
    
    auto operator <=> (const ID& rhs) const
    {
      if (auto comp=(domain<=>rhs.domain); comp != 0 )
      {
          cout <<typeid(comp).name(); //strong ordering
          return (comp);
      } 
     return (value <=> rhs.value);
    }
};

int main3()
{
    ID value1("org1", 123),value2("org", 123);
    //cout << (value1 == value2);
    cout << ((value1 <=> value2) == 0);
    return 0;
}


// the third party code dont have the <=>, == and less than operator overlaoaded
class userdefinedDatatype
{
    public:
    int a;
    userdefinedDatatype(int aa=10)
    {
        a =aa;
    }
    bool operator == (const userdefinedDatatype & lhs) const
    {
        return (a == lhs.a);
    }
    
    bool operator < (const userdefinedDatatype & lhs) const
    {
        return (a < lhs.a);
    }
};

class ID 
{
    public:
    ID(string d, int v)
    {
        domain = d;
        value = v;
    }
    
    string domain;
    userdefinedDatatype value; 
    
    auto operator <=> (const ID& rhs) const
    {
          if (auto comp=(domain<=>rhs.domain); comp == 0 )
          {
              cout <<typeid(comp).name();
              return (comp);
          } 
          
         if (value == rhs.value) // we cannot use the operator >  since the 
         // > operator is not overloaded in the userdefinedDatatype class
         {
            return std::strong_ordering::equal; 
         }
         if (value < rhs.value)
         {
             return std::strong_ordering::less;
         }
         else
         {
             return std::strong_ordering::greater;
         }
    }
    
};

int main()
{
    ID value1("org1", 123),value2("org", 123);
    //cout << (value1 == value2);
    cout << std::boolalpha;
    cout << ((value1 <=> value2) == 0); //true
    return 0;
}

// if he class has the float then the spaceship operator return type is the partial ordering.
// class has the int, bool then the spaceship operator return type is the strong ordering.

class Foo {
    public:
    Foo(float y)
    {
    
    }
    float f;
    string s;
    int i;
    auto operator<=>(Foo const&) const = default; // not the argument is not required
};
int main5()
{
    Foo a{12},b{12};
    cout << std::boolalpha;
    cout << typeid((a <=> b)).name() <<endl; //partial ordering
    cout << ((a<=>b) == 0) <<endl; //true
    return 0;
}

// we can overload the <=> and change the return type.
class Foo {
    public:
    Foo(float y)
    {
    
    }
    float f;
    string s;
    int i;
    auto operator<=>(Foo const& rhs) const 
    {
        return s<=> rhs.s;
    }
};
int main6()
{
    Foo a{12},b{12};
    cout << std::boolalpha;
    cout << typeid((a <=> b)).name() <<endl; //strong
    cout << ((a<=>b) == 0) <<endl; //true
    return 0;
}

// if the dependend class has the weak ordering , then actual needs to have the weak ordering overload 
//function.
//strong ordering ==> weak ordering ==> partial ordering.
//if the has the partial ordering ordering , then actual class needs to have the partial ordering
// ordering overload function.
// any type that is weakly ordered
class Weak {
   public:
    Weak(float c=0)
    {
        
    }
    int f;

    std::partial_ordering operator<=>(Weak const&) const =default;
};

class Foo {
    public:
    Foo(float y)
    {
    
    }
    Weak w;
    auto operator<=>(Foo const& rhs) const =default;
};
int main7()
{
    Foo a{12},b{12};
    cout << std::boolalpha;
    cout << typeid((a <=> b)).name() <<endl; //partial_ordering
    cout << ((a<=>b) == 0) <<endl; //true
    return 0;
}
//the dependent class has the weak ordering
class Weak {
   public:
    Weak(float c=0)
    {
        
    }
    int f;

    std::weak_ordering operator<=>(Weak const&) const =default;
};

class Foo {
    public:
    Foo(float y)
    {
    
    }
    Weak w;
    auto operator<=>(Foo const& rhs) const =default;
};
int main8()
{
    Foo a{12},b{12};
    cout << std::boolalpha;
    cout << typeid((a <=> b)).name() <<endl; //weak ordering
    cout << ((a<=>b) == 0) <<endl; //true
    return 0;
}

/// based on the member variable type auto deterrmines the type of the 
class Weak {
   public:
    Weak(float c=0)
    {
        
    }
    float f;

    auto operator<=>(Weak const&) const =default;
};

class Foo {
    public:
    Foo(float y)
    {
    
    }
    Weak w;
    auto operator<=>(Foo const& rhs) const =default;
};
int main9()
{
    Foo a{12},b{12};
    cout << std::boolalpha;
    cout << typeid((a <=> b)).name() <<endl; //partial ordering
    cout << ((a<=>b) == 0) <<endl; //true
    return 0;
}

//strong ordering converted into waek ordering
class Weak {
   public:
    Weak(float c=0)
    {
        
    }
    std::strong_ordering operator<=>(Weak const&) const =default;
};

class Foo {
    public:
    Foo(float y)
    {
    
    }
    Weak w;
    std::weak_ordering operator<=>(Foo const& rhs) const =default;
};
int main10()
{
    Foo a{12},b{12};
    cout << std::boolalpha;
    cout << typeid((a <=> b)).name() <<endl; //weak ordering
    cout << ((a<=>b) == 0) <<endl; //true
    return 0;
}

//overloading weak ordering:
#include <iostream>
#include <compare>
#include <string.h> //for strcasecmp
std::weak_ordering CaseInsensitiveString::caseInsenComp(const std::string& s1, 
                                 const std::string s2)
{
    if(s1.size() < s2.size()){
        return std::weak_ordering::less;
    }
    else if(s1.size() > s2.size()){
        return std::weak_ordering::greater;
    }
    else{
        int res = strcasecmp(s1.c_str(), s2.c_str());
        return res == 0? std::weak_ordering::equivalent:
               res < 0 ? std::weak_ordering::less :
                         std::weak_ordering::greater;
    }
}

class CaseInsensitiveString{
   private:
        std::string str_;
   public:
     CaseInsensitiveString(const std::string& s):str_{s}{   }
     std::weak_ordering operator<=>(const CaseInsensitiveString& b)
     { return caseInsenComp(str_, b.str_);  }
};

int main11(){
    CaseInsensitiveString hello{"hello"};
    CaseInsensitiveString Hello{"Hello"};
    CaseInsensitiveString iello{"iello"};
    std::cout << "1. " << ((hello <=> Hello) == 0) << "\n"; //1
    std::cout << "2. " << ((iello <=> Hello) > 0 ) << "\n"; //1
    
}
=========================
// To make check if the class is using the <=> or legacy operator and call the corresponding function
#include <iostream>
#include <compare>

using namespace std;

template <typename T>
auto synth_three_way (const T& lhs, const T& rhs) 
{
    if constexpr (std::three_way_comparable_with<T, T>) //constexpr : value is evaluated at compile time
    {
        return (lhs <=> rhs);
    }
    else
    {
        cout << "in the else part " ; //in the else part
        if (lhs == rhs) // we cannot use the operator >  since the 
         // > operator is not overloaded in the userdefinedDatatype class
         {
            return std::strong_ordering::equal;  //0 
         }
         else if (lhs < rhs)
         {
             return std::strong_ordering::less;
         }
         else
         {
             return std::strong_ordering::greater;
         }
    }
}

class userdefinedDatatype
{
    public:
    int a;
    
    userdefinedDatatype(int aa=10)
    {
        a =aa;
    }
    
    bool operator == (const userdefinedDatatype & lhs) const
    {
        return (a == lhs.a);
    }
    
    bool operator < (const userdefinedDatatype & lhs) const
    {
        return (a < lhs.a);
    }
};

class ID 
{
    public:
    ID(string d, int v)
    {
        domain = d;
        value = v;
    }
    
    string domain;
    userdefinedDatatype value; 
    
    auto operator <=> (const ID& rhs) const
    {
        if (auto comp = (domain <=> rhs.domain); comp == 0 )
        {
            cout <<typeid(comp).name();
            return (comp);
        } 
          
        return synth_three_way<userdefinedDatatype>(value, rhs.value);
    }
    
    /* necessary to have the == operator if we are overloading the <=> */
    bool operator == (const ID& rhs) const
    {
        return ((domain == rhs.domain) && (value == rhs.value));
    }
    
};

int main12()
{
    ID value1("org1", 123),value2("org", 123);
    cout << std::boolalpha;
    cout << (value1 == value2); // false
    
    /* here the template function is called */
    cout << ((value1 <=> value2) == 0); //true
    return 0;
}

/* o/p
false
in the else part
true
*/
===================================================

// if the class has the spaceship operator the compiler will rewrite < to spaceship
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
};

int main13()
{
    child obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj1 < obj2) <<endl; //true // compiler rewrite it as ((obj1 <=> obj2) < 0)
    cout << (obj1 <=> obj2 < 0); //true
    return 0;
}
==================================
// comparing the 2 objects which are off different type
class Automobile{
    private:
        std::string name_;
        
   public:
        auto operator <=>(const Automobile& rhs) const = default;
        void setname(string aname)
        {
            name_ =aname;
        }
};

//forward class
class Car;

class Bus: public Automobile{
    private:
        double fuelAmt_;
        
    public:
        Bus (string name, double ad)
        {
            fuelAmt_ = ad;
            setname(name);
        }
        
		auto operator <=>(const Bus& rhs) const = default;
		auto operator<=>(const Car& rhs)const{
			return std::partial_ordering::unordered;
		}
		
		bool operator==(const Car& rhs)const{
			return (std::partial_ordering::unordered == 0);
		}
};
class Car : public Automobile{
    private:
        double chargeHrs_;
    public:
        auto operator<=>(const Car& rhs) const = default;
        Car (string name, double ad)
        {
            chargeHrs_ = ad;
            setname(name);
        }
};

int main14(){
    std::cout << std::boolalpha;
    Bus bus{"volvo", 50};
    Car car{"tesla", 50};
    //It is not necessary that the bus < car , it can be car < bus
    // the partial ordering can be implemented in bus or car class
    std::cout << "1. " << (bus < car) << "\n"; //false
    std::cout << "2. " << (car > bus) << "\n";  //false
    std::cout << "3. " << (car >= bus) << "\n";  //false
    std::cout << "4. " << (car <= bus) << "\n";  //false
    std::cout << "5. " << (car == bus) << "\n";  //false
    //!= operator is inserted by the compiler
    std::cout << "6. " << (car != bus) << "\n\n";  //true
}
==========================================================
class Automobile{
    private:
        std::string name_;
        
   public:
        auto operator <=>(const Automobile& rhs) const = default;
        void setname(string aname)
        {
            name_ =aname;
        }
};


class Bus: public Automobile{
    private:
        double fuelAmt_;
        
    public:
        Bus (string name, double ad)
        {
            fuelAmt_ = ad;
            setname(name);
        }
        
		auto operator <=>(const Bus& rhs) const = default;
	
		bool operator==(const Car& rhs)const{
			return (std::partial_ordering::unordered == 0);
		}
};
class Car : public Automobile{
    private:
        double chargeHrs_;
    public:
        auto operator<=>(const Car& rhs) const = default;
        //comparing not related objects 
        auto operator<=>(const Bus& rhs)const{
			return std::partial_ordering::unordered;
		}
        Car (string name, double ad)
        {
            chargeHrs_ = ad;
            setname(name);
        }
};

int main15(){
    std::cout << std::boolalpha;
    Bus bus{"volvo", 50};
    Car car{"tesla", 50};
    //It is not necessary that the bus < car , it can be car < bus
    // the partial ordering can be implemented in bus or car class
    std::cout << "1. " << (bus < car) << "\n"; //false
    std::cout << "2. " << (car > bus) << "\n";  //false
    std::cout << "3. " << (car >= bus) << "\n";  //false
    std::cout << "4. " << (car <= bus) << "\n";  //false
    std::cout << "5. " << (car == bus) << "\n";  //false
    //!= operator is inserted by the compiler
    std::cout << "6. " << (car != bus) << "\n\n";  //true
}
=====================================================
//comparision operator is not default
int a =10;
class base
{
    public:
       base(int y=0)
       {
           i = a;
       }
    
   bool operator == (const base &rhs) const = default;
   
    public:
       int i {10};
      
};

class child: public base
{
    public:
        child(int y=0): base ()
		{
		    ii = y;
		}
	
	bool operator == (const child &rhs) const = default;
	
    private:
		int ii ;
       
};

int main()
{
    child obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (obj2 == 11) <<endl; 

    return 0;
}

//output
//false
=================================================================
#calling the base class custom == operator
int a =10;
class base
{
    public:
       base(int y=0)
       {
           i = a++;
       }
    
    bool operator == (const base &rhs) const
    {
        cout << "base class " <<endl ;
        return (this->i == rhs.i);
    }
    
    private:
       int i {10};
};

class child
{
    public:
        child(int y=0):b(y)
		{
		    ii = y;
		}
	
	 bool operator == (const child &rhs) const
	 {
	     cout << "child class " <<endl ;
	    if (this->b == (rhs.b))
	    {
            return (this->ii == rhs.ii);
	    }
	    else
	    {
	        return false;
	    }
    }
	
    private:
		int ii ;
        base b;
};

int main()
{
    child obj1(11), obj2(12);
    cout << std::boolalpha;
    cout << (12 == obj2) <<endl; 

    return 0;
}

//output
// child class
//base class
//false
===========================================
//spaceship comparision operator for vector
class IntVectorWrapper{
   private:
      std::vector<int> vec_;
   public:
      IntVectorWrapper(std::vector<int>&& vec): 
                           vec_{std::move(vec)}{}
      auto operator<=>(const IntVectorWrapper& rhs) const = default;
};

int main(){
    std::cout << std::boolalpha;
    IntVectorWrapper v3{std::vector<int>{0,0,0}}; 
    IntVectorWrapper v4{std::vector<int>{0,0,0,0}};
   

   std::cout << (v3 > v4)  << "\n"; //false
   std::cout << (v3 < v4)  << "\n"; //true
   // here the value and size is compared
   std::cout << (v3 == v4) << "\n"; //false
   
    IntVectorWrapper v31{std::vector<int>{1,3,2}};
    IntVectorWrapper v32{std::vector<int>{1,2,3}};
    
    std::cout << (v31 == v32) << "\n"; //false
    std::cout << (v31  > v32) << "\n"; //true
    std::cout << (v31  < v32) << "\n"; //false
    
    //for > here the value is compared
    IntVectorWrapper v311{std::vector<int>{1,2,3}};
    IntVectorWrapper v411{std::vector<int>{1,2,2,4}};
    std::cout << "last" << (v311 > v411) << "\n";
   

    return 0;
}
==============================================

//Only the base class member is compared
// How to use the friend function for the <=>
class Base {
public:
    int x;
    Base (int xx):x{xx}
    {
        
    }
	// error cannot have const qualifier for the friend function
	//friend auto operator<=>(const Base& lhs, const Base& rhs) const = default;
    //friend auto operator<=>(const Base& lhs, const Base& rhs)  = default; or auto operator<=>(const Base& rhs) cost = default	
    // note there can be only one space between the const = default
	friend auto operator<=>(const Base& lhs, const Base& rhs);  

    //auto operator<=>(const Base& rhs)const = default;
};
auto operator<=>(const Base& lhs, const Base& rhs)
{
    return (lhs.x <=> rhs.x);
}


class Derived : public Base {
public:
    int y;
    Derived(int xx,int yy):Base(xx),y{yy}
    {
        
    }
};

int main() {
    Derived d1{10, 20};
    Derived d2{100, 3};
    std::cout << ((d1 <=> d2) < 0) << std::endl; 
    // prints 1 means d1.x  is less than d2.x ; only base class is compared
    return 0;
}
==========================
//comparision between the base class object and derived class object.

class Base {
public:
    virtual std::strong_ordering operator<=>(const Base& other) const {
        std::cout << "Base comparison\n";
        return std::strong_ordering::greater;
    }
};

class Derived : public Base {
public:
    virtual std::strong_ordering operator<=>(const Base& other) const override {
        std::cout << "Derived comparison\n";
        return std::strong_ordering::equal;
    }
};

int main() {
    Base b;
    Derived d;
    std::cout << ((b <=> b) > 0) << "\n";  // Base comparison
    std::cout << ((d <=> d) == 0 ) << "\n";  // Derived comparison
    std::cout << ((d <=> b) == 0 ) << "\n";  // Derived comparison
}
/*
Base comparison
1
Derived comparison
1
Derived comparison
1
*/
============

class Base {
public:
    std::strong_ordering operator<=>(const Base& other) const {
        std::cout << "Base comparison\n";
        return std::strong_ordering::greater;
    }
};

class Derived : public Base {
public:
    std::strong_ordering operator<=>(const Derived& other) const  {
        std::cout << "Derived comparison\n";
        return std::strong_ordering::equal;
    }
};

int main() {
    Base b;
    Derived d;
    std::cout << ((b <=> b) > 0) << "\n";  // Base comparison
    std::cout << ((d <=> d) == 0 ) << "\n";  // Derived comparison
    std::cout << ((d <=> b) == 0 ) << "\n";  // derived comparison
}
==========================
//spaceship operator return the order
//Order of the comparision:
//base class first and then the derived class
class Base {
public:
    Base(int b) : base(b) {}
    int getBase() const { return base; }
    auto operator <=> (const Base& ) const = default;
private:
    int base;
};

class Derived : public Base {
public:
    Derived(int b, int d) : Base(b), derived(d) {}
    auto operator <=> (const Derived& ) const = default;
    int getDerived() const { return derived; }
private:
    int derived;
};

int main() {
    Derived d1{2, 3}, d2{2, 4};

    std::strong_ordering result = d1 <=> d2;
    if (result == std::strong_ordering::less) {
        std::cout << "d1 is less than d2\n";
    } else if (result == std::strong_ordering::greater) {
        std::cout << "d1 is greater than d2\n";
    } else {
        std::cout << "d1 is equal to d2\n";
    }
}
///"d1 is less than d2\n"
============================================
class Base{
    private:
        float a_{};
    public:
        Base(float a):a_{a}{}
        virtual ~Base() = default;
        auto operator<=>(const Base& rhs) const = default;
};
class Derived : public Base{
    private:
        int b_{};
    public:
        Derived(float a, int b):Base(a), b_{b}{}
        virtual ~Derived() = default;
        auto operator<=>(const Derived& rhs)const = default;
};
int main(){
    Derived d0{0.1, 2};
    Derived d1{0.2, 2};
    Derived d2{0.2, 3};    
    std::cout << (d0 < d1) << "\n";
    std::cout << (d1 < d2) << "\n";
}
//
true
true