
/*
	private destructor sample program prepared by viswanatha Ramasamy to help the people to crack c++ interview.
	Share , Subscribe and give me your valuable comments.
	Source Code Location: https://github.com/ViswanathanRamasamy/Cpp_Sample_Programs
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

#include <iostream>
#include <memory>

using namespace std;

class privatedestuctor
{
    private:
      ~privatedestuctor()
      {
          
      }
      
    public:
      friend void fdeletion(privatedestuctor *aoptr);
      static void sdeletion(privatedestuctor *aoptr);
};

void fdeletion(privatedestuctor *aoptr)
{
   cout << "deleteion from the friend function " << endl;    
   delete aoptr;
}

void privatedestuctor::sdeletion(privatedestuctor *aoptr)
{
   cout << "deleteion from the static function " << endl; 
   delete aoptr;
}

int main()
{
    privatedestuctor *l_optr1 = new privatedestuctor();
    privatedestuctor *l_optr2 = new privatedestuctor();
    fdeletion(l_optr1); // friend function doesnot need the class name or the object for calling
    privatedestuctor::sdeletion(l_optr2);
    //sdeletion(l_optr2); will not work , static function needs the class name
    return 0;
}
/* output
deleteion from the friend function 
deleteion from the static function 
*/