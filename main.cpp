#include <stdio.h>
#include <iostream>
 
using namespace std;
 
 typedef struct
{
  string text;
  int val_loc;
  unsigned char val_type;
//val_type
//  1 char  1
//  2 unsigned char 1
//  3 short 2
//  4 unsigned short  2
//  5 int32_t 4
//  6 uint32_t  4
//  7 int64_t 8
//  8 uint64_t  8
//  9 float 4
//  10  double  8
//  11  long double 10

  unsigned char val_mode;  // 0 - read only;1 - auto; 2 - manual;
// TO DO: VAL_MODE AS FLAGS:
//0 RO/RW
//1 AUTO/MANUAL
//2 NOALARMS/ALARMS
//3 OK/ATARMHI
//4 OK/ALARMLO
//5
//6
//7
} points;




#define RO 0
#define RW 1
template < int ARRAY_LEN >
class Points
{
  private:
  unsigned int count=0;
  points array[ARRAY_LEN];
  public:
    void pointAdd(string ntext, unsigned char (&nval_loc)[4])
	{
			array[count].text=ntext;
		array[count].val_loc=(int)&nval_loc;
		array[count].val_type=2;
		array[count].val_mode=1;
		count++;
	}; 
    void pointAdd(string ntext, short& nval_loc, unsigned char val_mode){}; 
    void pointAdd(string ntext, unsigned short& nval_loc, unsigned char val_mode){}; 
    void pointAdd(string ntext, int& nval_loc, unsigned char val_mode){}; 
    void pointAdd(string ntext, unsigned int& nval_loc, unsigned char val_mode){}; 
    void pointAdd(string ntext, long int& nval_loc, unsigned char val_mode){}; 
    void pointAdd(string ntext, unsigned long int& nval_loc, unsigned char val_mode){}; 
    void pointAdd(string ntext, float& nval_loc, unsigned char val_mode){}; 
    void pointAdd(string ntext, double (&nval_loc)[4])
	{
		array[count].text=ntext;
		array[count].val_loc=(int)&nval_loc;
		array[count].val_type=10;
		array[count].val_mode=1;
		count++;
	}; 
    void pointAdd(string ntext, long double& nval_loc, unsigned char val_mode){}; 
    void pointAdd(string ntext/*, char &nval_loc, unsigned char val_mode*/)
    
    
    
    {
     array[count].text = ntext;
    count++;
   };
   unsigned char typeLength(signed char type)
   {
   	switch(type)
   	{
   		case 1:
   		return 1;	
   		break;
   		
   		case 2:
   		return 1;		
   		break;   		
		
		case 3:
   		return 2;		
   		break;
   		
   		case 4:
   		return 2;		
   		break;
		      		
   		case 5:
   		return 4;		
   		break;
   		
   		case 6:
   		return 4;		
   		break;   		
		
		case 7:
   		return 8;		
   		break;
   		
   		case 8:
   		return 8;		
   		break;
   		
   		case 9:
   		return 4;		
   		break;
   		
   		case 10:
   		return 8;		
   		break;
		   
   		case 11:
   		return 10;		
   		break;
   		
		default:
		return -1;		
		break;	   		        		
	   }
   }
   unsigned char readByte(int id, unsigned char loc)
   {
   	unsigned char temp = typeLength(array[id].val_type)-1;
   	if (count >= id && loc <= temp)
   	{
	cout<<"ok";
	return *((unsigned char *)array[id].val_loc + loc);

	}
	else
	{
		return -1;
	}
   }
   void printLoc(unsigned char id)
   {
   //	double *testtt = *(double*)array[id].val_loc;
   	cout<<endl<<"address w klasie: "<<array[id].val_loc<<endl<<"Wartosc przekazana: "<<*(double*)array[id].val_loc;
   }
      int getLoc(unsigned char id)
   {
   if (id <= count)
   {
   	return array[id].val_loc;
   }
   	 
   }
void test(short& testint)
{
  //
};
};
/*class Base
{
public:
    virtual void doSomething() = 0;
};

class A : public Base
{
    void doSomething() { }
};

class B : public Base
{
    void doSomething() { }
};

std::vector<Base*> pointers;
pointers.push_back(new A);
pointers.push_back(new B);*/
 
 
 
int main()
{
//	point_manual_alarm_double
double dtest[4] = {1234,0,0};
unsigned char ztest[4] = {1,2,3,4};
int ctest	= (int)&dtest;
double *final = (double*)ctest;
//*final = 280.280;
int testt[2] = {3,5};
int byte = *((int *)&testt + 1);
double & ref = dtest[0];
//double final = (double)&ctest;
Points<5> ptest;
ptest.pointAdd("testorwywy",dtest);
ptest.pointAdd("testorwywy",ztest);
    cout<<dtest<<endl<<&dtest<<endl << std::hex <<ctest;
    cout<<endl<<*final<<endl<<*final;
    cout<<endl<<"ref address"<<endl<<&ref<<endl<<"test wartości z klasy: "<<*(double*)ptest.getLoc(0);
    ptest.printLoc(0);
    cout<<endl<<(unsigned int)ptest.readByte(1,1);
    cin.get();
    return 0;
}
