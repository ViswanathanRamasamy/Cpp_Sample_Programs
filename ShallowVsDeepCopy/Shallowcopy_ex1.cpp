/*
	Shallow copy sample program prepared by viswanatha Ramasamy to help the people to crack c++ interview.
	Share , Subscribe and give me your valuable comments.
	source code location: https://github.com/ViswanathanRamasamy/RockYourInterview-CPP/
*/

#include <iostream>
#include <string>

using namespace std;

class shallowCopy
{
	private:
		/* private member variables */
		int m_ix, m_iy, *m_ipptr;
	
	public:
	/* member functions *
		/* no argument constructor */
		shallowCopy()
		{
			m_ix = m_iy = 0;
			m_ipptr = nullptr;
		}

		/* destructor */
		~shallowCopy()
		{
			/* freeing the allocated memory */
			if (m_ipptr != nullptr)
			{
			   //delete m_ipptr ;
			   // m_ipptr = nullptr;
			}
		}

		/* setter function */
		void setData(int ax, int ay, int az)
		{
			m_ix = ax;
			m_iy = ay;
			
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
			cout << m_ix <<" " <<m_iy <<endl;
			cout << "addr = " << m_ipptr << " " << *m_ipptr << endl;
		}
};

/* main function */
int main()
{
	 shallowCopy l_obj1;
	 l_obj1.setData(10,20,30);
	 /* copy constructor */
	 shallowCopy l_obj2(l_obj1);
	 cout << "l_obj1 content " <<endl;
	 l_obj1.getData();
	 cout << "l_obj2 content " <<endl;
	 l_obj2.getData();
	 shallowCopy l_obj3 = l_obj2;
	 cout << "l_obj3 content " <<endl;
	 l_obj3.getData();
	 /* assignement operator */
	 shallowCopy l_obj4;
	 l_obj4=l_obj3;
	 cout << "l_obj4 content " <<endl;
	 l_obj4.getData();
	 
	 shallowCopy l_obj5;
	 l_obj5=l_obj4;
	 l_obj5.setData(11,21,31);
	 cout << "l_obj5 content " <<endl;
	 l_obj5.getData();
	 cout << "l_obj4 content " <<endl;
	 l_obj4.getData();
	 
	 return 0;
}

/* output
l_obj1 content 
10 20
addr = 0x556ddcff0eb0 30
l_obj2 content 
10 20
addr = 0x556ddcff0eb0 30
l_obj3 content 
10 20
addr = 0x556ddcff0eb0 30
l_obj4 content 
10 20
addr = 0x556ddcff0eb0 30
l_obj5 content 
11 21
addr = 0x556ddcff0eb0 31
l_obj4 content 
10 20
addr = 0x556ddcff0eb0 31

*/