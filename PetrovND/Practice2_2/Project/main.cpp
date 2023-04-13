#include "lib.h"

int main() {
    string path = menu();
    lib library(path);
    set <string> sections = library.booksBySection();
    vector <cardIndex> books = library.findBooks(sections);
    library.getBook(books);
    return 0;
}
