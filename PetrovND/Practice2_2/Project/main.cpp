#include "lib.h"

int main() {
    string path = menu();
    int count = strCount(path);
    lib library(path, count);
    set <string> sections = booksBySection(library);
    searchBook(library, sections);
    return 0;
}