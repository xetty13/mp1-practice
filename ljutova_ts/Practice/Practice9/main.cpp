#include "Date.h" 
#include "Exception.h" 
using namespace std;
int main()
{
	int d, m, y;
	cin >> d >> m >> y;
	Date date(d, m, y);
	date.Print();
}