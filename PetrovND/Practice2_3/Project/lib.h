#ifndef _LIB_H
#define _LIB_H

#include <string>
#include <set>
#include <vector>
using namespace std;

enum availability {
    available,
    not_available
};

class CardIndex {
private:
    vector <string> authors;
    string title;
    string publisher;
    string section;
    availability avb;
    float evaluation;

public:
    CardIndex(const vector <string>& authors, const string& title, const string& publisher, const string& section, const availability avb, const float evaluation);
    ~CardIndex();

    bool operator==(const string& otherTitle) const;
    bool operator!=(const string& otherTitle) const;
    friend ostream& operator<<(ostream& os, const CardIndex& card);

    string getTitle() const;
    string getSection() const;
};

class Library {
public:
    Library(const string& path);
    ~Library();

    set <string> booksBySection();
    vector <CardIndex> findBooks(const set <string>& sections);
    void getBook(const vector <CardIndex>& books);

    vector <CardIndex> getCards() const;
private:
    vector <CardIndex> cards;
};

string menu();

#endif // !_LIB_H
