#include <iostream>
#include <typeinfo> //required for typeid
using namespace std;

/*type interface: automatic detection of data type. the compilation time will increase but less time in 
writing.
a. auto: variable should be initialized at the time of declaration.
b.decltype: declared type of the varaiable or expression
*/
int main1()
{
    auto a = 10;
    auto b = 12.0f;
    auto c = &b;
    auto &d = b;
    cout << typeid(a).name() <<std::endl; // i
    cout <<typeid(b).name() <<std::endl; //f
    cout << typeid(c).name() <<std::endl; // pf
    cout <<typeid(d).name() <<std::endl; //f
    return 0;
}

// decltype resolves the type during the compilation time and not at the runtime.
//decltype will also provide the data type based on the expression like decltype()
int main2()
{
    decltype(main1()) x;
    float y;
    decltype(y) x1;
    cout << typeid(x).name() <<std::endl; //i
    cout << typeid(x1).name() <<std::endl; //f
    return 0;
}

// function return ype is selected based on the expression
auto func(int a, int b)
{
    return (a+b+67.89f);
}

//forcing the function to return the int
auto func1(int a, int b) ->decltype(3>2.0f ?3:2.0f)
{
    return (a+b+67.89f);
}

int main3()
{
    cout<<func(1,2) << " " << typeid(func(1,2)).name() <<std::endl; //70.89.0f f
    cout<<func1(1,2) << " " << typeid(func1(1,2)).name() <<std::endl; //70 i
    const type_info &type1 = typeid(decltype(12+2.0f));
    cout << type1.name(); //f
    return 0;
}

//NaN: not a number. 
//sqrt of negative number, log of negative number, 
// nan division nan., inf division inf
#include <iostream>
#include <limits> //numeric_limits
#include <cmath> //isnan
using namespace std;


int main4()
{
    double d=std::numeric_limits<double>::quiet_NaN();
    float f=std::numeric_limits<float>::quiet_NaN();
    
    if (d != d)
    {
        cout << "double is false "<< d <<endl; //double is false nan
    }
    
    if (f != f)
    {
        cout << "1.float is false " << f <<endl; //1. float is false nan
    }
    
    if (isnan(f))
    {
        cout << "2.float is false" << f <<endl; //2. float is false nan
    }
    return 0;
}


int main5()
{
    double d=std::numeric_limits<double>::quiet_NaN();
    float f=std::numeric_limits<float>::quiet_NaN();
    float c = d/f;
    cout << " " << c; //nan
    return 0;
}

int main6()
{
    if (int comp = (10-9); comp==0)
       cout << comp;

    return 0;
}