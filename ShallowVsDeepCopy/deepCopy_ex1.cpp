/*
	deep copy sample program prepared by viswanatha Ramasamy to help the people 
	to crack c++ interview. Share , Subscribe and give me your valuable comments.
	source code location: https://github.com/ViswanathanRamasamy/RockYourInterview-CPP/
*/

#include <iostream>
#include <string>

using namespace std;

class deepCopy
{
   private:
     /* private member variables */
     int m_ix, m_iy, *m_ipptr;
   public:
     /* public member functions */
    /* no argument constructor */
    deepCopy()
    {
    }
    
    /* destructor */
    ~deepCopy()
    {
       /* free the allocated memory */    
       delete m_ipptr ;
    }
    
    /* copy constructor */
    deepCopy(deepCopy &a_l_obj)
    {
        m_ix = a_l_obj.m_ix;
        m_iy = a_l_obj.m_iy;
        m_ipptr = new int (*(a_l_obj.m_ipptr));
    }
    
    /* overload the assignment operator */ 
    deepCopy& operator=(const deepCopy &a_l_obj)
    {
        if(this != &a_l_obj)
        {
            m_ix = a_l_obj.m_ix;
            m_iy = a_l_obj.m_iy;
            m_ipptr = new int (*(a_l_obj.m_ipptr));
        }
        return *this;
    }
    
    /* setter function */
    void setData(int ax, int ay, int az)
	{
	    m_ix = ax;
		m_iy = ay;
		m_ipptr = new int(az);
	}
	
	/* getter function */
	void getData()
	{
	  cout << m_ix <<" " << m_iy <<endl;
	  cout << "addr = " << m_ipptr << " " << *m_ipptr << endl;
	  
	}
};

/* main function */
int main()
{
 deepCopy l_obj1;
 l_obj1.setData(10,20,30);
 /* copy constructor */
 deepCopy l_obj2(l_obj1);
 cout << "l_obj1 content " <<endl;
 l_obj1.getData();
 cout << "l_obj2 content " <<endl;
 l_obj2.getData();
 deepCopy l_obj3 = l_obj2;
 cout << "l_obj3 content " <<endl;
 l_obj3.getData();
 /* assignement operator */
 deepCopy l_obj4;
 l_obj4=l_obj3; // call l_obj4.operator=(l_obj3)
 cout << "l_obj4 content " <<endl;
 l_obj4.getData();
 
  /* assignement operator */
 deepCopy l_obj5,l_obj6;
 l_obj5=l_obj6=l_obj4;
 cout << "l_obj5 content " <<endl;
 l_obj5.getData();
 
 cout << "l_obj6 content " <<endl;
 l_obj6.getData();
 
 return 0;
}
/* output
l_obj1 content 
10 20
addr = 0x55b2c804deb0 30
l_obj2 content 
10 20
addr = 0x55b2c804ded0 30
l_obj3 content 
10 20
addr = 0x55b2c804e300 30
l_obj4 content 
10 20
addr = 0x55b2c804e320 30
l_obj5 content 
10 20
addr = 0x55b2c804e360 30
l_obj6 content 
10 20
addr = 0x55b2c804e340 30
*/

