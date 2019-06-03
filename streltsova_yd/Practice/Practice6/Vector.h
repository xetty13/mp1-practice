typedef struct
{
    int n;
    float *x;
}Vector;
Vector* Create(int _n);
Vector* Add(Vector *a);
void Print(Vector *a);
void Delete(Vector *a);
Vector* Sum(Vector *a, Vector *b);
Vector* Diff(Vector *a, Vector *b);
float Scalar(Vector *a, Vector *b);
float Length(Vector*a);
float Angle(Vector *a, Vector *b);
