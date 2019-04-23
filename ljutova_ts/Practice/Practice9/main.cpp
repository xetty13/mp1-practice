#include "Time.h" 
#include "Exception.h" 
using namespace std;
int main()
{
	
	try
	{
		int h, min;
		cin >> h >> min;
		Time time(h, min);
		time.Print();
	}
	catch (Exception e)
	{
		e.Print();
	}
}