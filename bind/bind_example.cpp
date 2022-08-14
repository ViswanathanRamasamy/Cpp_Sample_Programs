/*
	bind function,  sample program prepared by viswanatha Ramasamy to help the people to crack c++ interview.
	Share , Subscribe and give me your valuable comments.
	Source Code Location: https://github.com/ViswanathanRamasamy/RockYourInterview-CPP/
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

void gfunction( int a, int b, int c, int d)
{
   cout << a  << " " << b << "  " << c <<  " " << d << " " <<endl;
}

int main ()
{
  auto l_f1 = bind(gfunction,_2,_1, 10, 20);
  auto l_f2 = bind (gfunction,11,12,13,_1);
  l_f1(100,200);
  l_f2(6);
  
  return 0;
}
/)output
200 100  10 20 
11 12  13 6 
)/