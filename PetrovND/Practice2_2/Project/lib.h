#ifndef _CARD_H
#define _CARD_H

#include <string>
#include <vector>
#include <set>
using namespace std;

enum availability {
    available,
    not_available
};

struct cardIndex {
    string* authors;
    int authorsCount;
    string title;
    string publisher;
    string section;
    availability avb;
    float evaluation;

    bool operator==(const string& otherTitle) const;
    bool operator!=(const string& otherTitle) const;
    friend ostream& operator<<(ostream& os, const cardIndex& card);
};

struct lib {
    cardIndex* cards;
    int count;
    lib(const string& path);
    ~lib();
    set <string> booksBySection();
    vector <cardIndex> findBooks(const set <string>& sections);
    void getBook(const vector <cardIndex>& books);
    int strCount(const string& path);
};

string menu();

#endif // !_CARD_H
