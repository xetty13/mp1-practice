#include "lib.h"

int main() {
    string path = menu();
    Library lib(path);
    set <string> sections = lib.booksBySection();
    vector <CardIndex> books = lib.findBooks(sections);
    lib.getBook(books);
    return 0;
}