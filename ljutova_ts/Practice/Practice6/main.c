#include "Vector.h" 

void main()
{
	Vector v1, v2, v3, s, m, sc;
	int l;
	v1 = fill();
	Output(v1);
	v1 = fill();
	Output(v2);
	v3 = fill();
	Output(v3);
	s = Sum(v1, v2);
	Output(s);
	m = Sub(v1, v2);
	Output(m);
	l = Length(s);
	printf("length = ", l);
	sc = scalar(v1, v2);
	printf("Scalar = ", sc);
	system("pause");
}
