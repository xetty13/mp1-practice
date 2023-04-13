#include "lib.h"

int main() {
    string path = menu();
    int count = strCount(path);
    lib library(path, count);
    set <string> sections = booksBySection(library);
    vector <cardIndex> books = findBooks(library, sections);
    getBook(books);
    return 0;
}