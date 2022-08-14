/*
	initialize the shared_ptr, sample program prepared by viswanatha Ramasamy to help the people to crack c++ interview.
	Share , Subscribe and give me your valuable comments.
	Source Code Location: https://github.com/ViswanathanRamasamy/RockYourInterview-CPP/
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> ptr(new int(4));
    shared_ptr<int> ptr1;
    ptr1 =make_shared <int>(5);
    shared_ptr<int> ptr2;
    ptr2.reset(new int(6));
    shared_ptr<int> ptr3= make_shared<int>(7);
    shared_ptr<int> ptr4(new int());
    shared_ptr<int> ptr5(new int);
    
    cout << *ptr << " " << *ptr1 << " " << *ptr2 <<" " << *ptr3 <<  " " << *ptr4 << " " <<*ptr5;

    return 0;
}
/* output
4 5 6 7 0 0
*/

