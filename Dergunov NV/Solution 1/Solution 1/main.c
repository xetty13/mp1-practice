#include "func.h"

int main(int argc, char** argv)
{
    int n;
    double result;
    TVector V1, V2, s, m;
    char* infilename, * outfilename;

    if (argc < 3) {
        printf("Incorrect argument\n");
        return 1;
    }

    infilename = argv[1];
    printf("IN Filename: %s\n", infilename);
    outfilename = argv[2];
    printf("OUT Filename: %s\n", outfilename);

    read(infilename, &V1, &V2);

    s = sum(&V1, &V2);
    m = minus(&V1, &V2);
    result = dot(&V1, &V2);

    write(outfilename, &s, &m, result);

    free(V1.x);
    free(V2.x);
    if (s.x != NULL) {
        free(s.x);
    }
    if (m.x != NULL) {
        free(m.x);
    }
}