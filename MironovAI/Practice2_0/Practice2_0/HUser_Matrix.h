typedef struct
{
    float** matrix;
    int size;
} CMatrix;

void allocate_matrix(CMatrix** data, int n);
void free_matrix(CMatrix** data);
void fill_matrix(CMatrix* data);
void mprint(CMatrix* data);


CMatrix* multi_matrix(CMatrix* vector1, CMatrix* vector2);
CMatrix* add_matrix(CMatrix* vector1, CMatrix* vector2);
CMatrix* add_const(CMatrix* data, float c);
CMatrix* multi_const(CMatrix* data, float c);
