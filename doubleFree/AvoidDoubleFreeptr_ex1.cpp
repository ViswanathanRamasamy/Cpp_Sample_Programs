/*
	Avoid the DoubleFree sample program prepared by viswanatha Ramasamy to help the people to crack c++ interview.
	Share , Subscribe and give me your valuable comments.
	Source Code Location: https://github.com/ViswanathanRamasamy/RockYourInterview-CPP/
*/

#include <iostream>
#include <string>

using namespace std;

class adoubleFree
{
	private:
		/* private member variables */
		int *m_ipptr;
		/* static variable to keep the count on the number of object referring to the 
		shared memory */
	    static int m_sicount;
		
	public:
	/* member functions *
		/* no argument constructor */
		adoubleFree():m_ipptr(nullptr)
		{
		    
		}
		
		/* overloading the copy constructor to keep the reference count */
        adoubleFree(const adoubleFree &a_dfObject )
        {
            m_ipptr = a_dfObject.m_ipptr;
            m_sicount++;
        }
		
		/* overloading the copy constructor to keep the reference count */
        adoubleFree& operator=(const adoubleFree &a_dfObject )
        {
            m_ipptr = a_dfObject.m_ipptr;
            m_sicount++;
			return *this;
        }
		
		/* destructor */
		~adoubleFree()
		{
		    /* when the object is goin out of scope, the destructor will be called
		    so for both the obj1 and obj2 the destrcutor will be called. here the 
		    reference count for the object is implemented so that the delete will be called
		    only for the last object */
		    if (m_sicount == 0)
		    {
				/* now the free will be called only one time */
    			/* freeing the allocated memory */
    			if (m_ipptr != nullptr)
    			{
    			   cout << "calling the delete to free the memory " <<endl; 
    			   delete m_ipptr ;
    			   m_ipptr = nullptr;
    			}
		    }
		    else
		    {
		        m_sicount --;
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

/* definition of the static member */
int adoubleFree::m_sicount=0;

/* main function */
int main()
{
	 adoubleFree l_obj1;
	 l_obj1.setData(30);
	 /* copy constructor */
	 adoubleFree l_obj2(l_obj1);
	 cout << "l_obj1 content " <<endl;
	 l_obj1.getData();
	 cout << "l_obj2 content " <<endl;
	 l_obj2.getData();
	adoubleFree l_obj3;
	 l_obj3= l_obj1;
	 cout << "l_obj3 content " <<endl;
	 l_obj3.getData();
	 
	 return 0;
}

/* output
l_obj1 content 
addr = 0x55b273a84eb0 30
l_obj2 content 
addr = 0x55b273a84eb0 30
l_obj3 content 
addr = 0x55b273a84eb0 30
calling the delete to free the memory 
*/