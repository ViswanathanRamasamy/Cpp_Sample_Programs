/*
	Avoid the DoubleFree sample program prepared by viswanatha Ramasamy to help the people to crack c++ interview.
	Share , Subscribe and give me your valuable comments.
	Source Code Location: https://github.com/ViswanathanRamasamy/Cpp_Sample_Programs
	Author Name: Viswanathan Ramasamy
	Email id: rviswawt@gmail.com
*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class adoubleFree
{
	private:
		/* private member variables */
		shared_ptr<int> m_ipptr;

	public:
	/* member functions *
		/* no argument constructor */
		adoubleFree():m_ipptr(nullptr)
		{
		    
		}
		
		/* destructor */
		~adoubleFree()
		{
			/* now the free will be called only one time */
			/* freeing the allocated memory */
			if (m_ipptr != nullptr)
			{
	            cout<<m_ipptr.use_count() <<endl;
			}
		}

		/* setter function */
		void setData(int az)
		{
			if (m_ipptr == nullptr)// or if (m_ipptr.get() == nullptr)
			{
			    /* allocate the memory and assign the value to the shared memory */
				//m_ipptr = make_shared<int>(az);
				  m_ipptr.reset(new int(az));
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
addr = 0x55d98285cec0 30
l_obj2 content 
addr = 0x55d98285cec0 30
l_obj3 content 
addr = 0x55d98285cec0 30
3
2
1
*/

