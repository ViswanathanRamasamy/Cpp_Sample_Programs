/*
	doubleFree sample program prepared by viswanatha Ramasamy to help the people to crack c++ interview.
	Share , Subscribe and give me your valuable comments.
	Source Code Location: https://github.com/ViswanathanRamasamy/RockYourInterview-CPP/
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

#include <iostream>
#include <string>

using namespace std;

class doubleFree
{
	private:
		/* private member variables */
		int *m_ipptr;

	public:
	     /* member functions *
		/* no argument constructor */
		doubleFree():m_ipptr(nullptr)
		{
		    
		}

		/* destructor */
		~doubleFree()
		{
		    /* when the object is going out of scope, the destructor will be called.
		    so for both the obj1 and obj2  delete will be called twice for the sample
		    memory */
		    
			/* freeing the allocated memory */
			if (m_ipptr != nullptr)
			{
			   cout << "calling the delete to free the memory " <<endl; 
			   delete m_ipptr ;
			   m_ipptr = nullptr;
			}
		    
		}

		/* setter function */
		void setData(int az)
		{
			if (m_ipptr == nullptr)
			{
				m_ipptr = new int(az);
			}
			else
			{
				*m_ipptr = az;
			}
		}

		/* getter function */
		void getData()
		{
			cout << "addr = " << m_ipptr << " " << *m_ipptr << endl;
		}
};

/* main function */
int main()
{
	 doubleFree l_obj1;
	 l_obj1.setData(30);
	 cout << "l_obj1 content " <<endl;
	 l_obj1.getData();
	 /* copy constructor */
	 doubleFree l_obj2(l_obj1);
	  l_obj2.setData(130);
	 cout << "l_obj1 content " <<endl;
	 l_obj1.getData();
	 cout << "l_obj2 content " <<endl;
	 l_obj2.getData();
	 doubleFree l_obj3;
	 l_obj3= l_obj1;
	 cout << "l_obj3 content " <<endl;
	 l_obj3.getData();
	 return 0;
}

/*output
l_obj1 content 
addr = 0x5646c12e8eb0 30
l_obj1 content 
addr = 0x5646c12e8eb0 130
l_obj2 content 
addr = 0x5646c12e8eb0 130
l_obj3 content 
addr = 0x5646c12e8eb0 130
calling the delete to free the memory 
calling the delete to free the memory 
free(): double free detected in tcache 2
*/

