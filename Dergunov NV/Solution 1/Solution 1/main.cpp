#include "header.h"
int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cout << "something wrong" << std::endl;
        return 1;
    }
    char* infilename = argv[1], * outfilename = argv[2];
    std::ofstream out;
    std::ifstream in;
    TVector V1, V2;

    in.open(infilename);
    in >> V1 >> V2;
    in.close();

    TVector sum = V1 + V2;
    TVector rasn = V1 - V2;
    double skalumn = V1 * V2;

    out.open(outfilename);
    out << sum << rasn << "umn = " << skalumn << std::endl;
    out.close();

    return 0;
}