/*
	order of constructor and destructor calling,  sample program prepared by viswanatha Ramasamy to help the people to crack c++ interview.
	Share , Subscribe and give me your valuable comments.
	Source Code Location: https://github.com/ViswanathanRamasamy/RockYourInterview-CPP/
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

#include <iostream>
#include <memory>

using namespace std;

int g_icount = 0;

class orderCD {
   private:
        int m_icount;
   public:
   orderCD()
   {
       m_icount = g_icount++;
       cout<<"Inside the constructor " <<endl;
   }
   ~orderCD() {
      cout<<"Inside Destructor " << m_icount <<endl;
   }
};

class orderCD1 {
   private:
        int m_icount;
   public:
       orderCD1()
       {
           m_icount = g_icount++;
           cout<<"Inside the constructor1 " <<endl;
       }
       ~orderCD1() {
          cout<<"Inside Destructor1 " << m_icount <<endl;
       }
};

int main()
{
    orderCD demo[2];
    orderCD1 demo1[2];
}
/*output

Inside the constructor 
Inside the constructor 
Inside the constructor1 
Inside the constructor1 
Inside Destructor1 3
Inside Destructor1 2
Inside Destructor 1
Inside Destructor 0

*/