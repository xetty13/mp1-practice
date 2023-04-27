#include <iostream>
#include <fstream>
#include <sstream>
#include "lib.h"

string CardIndex::getSection() const { return this->section; }
string CardIndex::getTitle() const { return this->title; }
vector <CardIndex> Library::getCards() const { return this->cards; }

bool CardIndex::operator==(const string& otherTitle) const {
    return (title == otherTitle);
}

bool CardIndex::operator!=(const string& otherTitle) const {
    return !(title == otherTitle);
}

ostream& operator<<(ostream& os, const CardIndex& card) {
    os << "Title: " << card.title << endl;
    os << "Authors: ";
    for (int i = 0; i < card.authors.size(); i++) {
        os << card.authors[i];
        if (i < card.authors.size() - 1) {
            os << ", ";
        }
    }
    os << endl;
    os << "Publisher: " << card.publisher << endl;
    os << "Section: " << card.section << endl;
    os << "Availability: " << (card.avb == availability::available ? "Available" : "Not available") << endl;
    os << "Evaluation: " << card.evaluation << endl;
    os << "-----------------------" << endl;
    return os;
}

string menu() {
    string path;
    while (true) {
        cout << "Enter the file path..." << endl;
        getline(cin, path);
        ifstream file(path);
        if (file.good()) {
            file.close();
            return path;
        }
        cout << "ERROR: Could not open file!\n" << endl;
    }
}

CardIndex::CardIndex(const vector <string>& authors, const string& title, const string& publisher, const string& section, const availability avb, const float evaluation) :
    authors(authors), title(title), publisher(publisher), section(section), avb(avb), evaluation(evaluation) {}

Library::Library(const string& path) {
    int j = 0;
    ifstream file(path);
    string line;
    float evaluation;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        stringstream ss(line);
        string item;

        getline(ss, item, ';');
        stringstream authorsStream(item);
        string author;
        stringstream authorsStream2(item);
        int i = 0;
        vector <string> authors;
        string title;
        string publisher;
        string section;
        availability avb;
        while (getline(authorsStream2, author, ',')) {
            authors.push_back(author);
            i++;
        }
        getline(ss, title, ';');
        getline(ss, publisher, ';');
        getline(ss, section, ';');
        string availabilityStr;
        getline(ss, availabilityStr, ';');
        if (availabilityStr == "Available") {
            avb = available;
        }
        else {
            avb = not_available;
        }
        string evaluationStr;
        getline(ss, evaluationStr, ';');
        evaluation = stof(evaluationStr);
        CardIndex card(authors, title, publisher, section, avb, evaluation);
        this->cards.push_back(card);
        j++;
    }
    file.close();
}

CardIndex::~CardIndex() { this->authors.clear(); }
Library::~Library() { this->cards.clear(); }

set <string> Library::booksBySection() {
    int count = this->cards.size();
    set <string> sections;
    vector <CardIndex> crd = this->getCards();
    for (int i = 0; i < count; i++) {
        sections.insert(this->getCards()[i].getSection());
    }
    for (string s : sections) {
        cout << "\nBooks from " << s << endl;
        for (int j = 0; j < count; j++) {
            if (this->getCards()[j].getSection() == s) {
                cout << this->cards[j];
            }
        }
    }
    return sections;
}

vector <CardIndex> Library::findBooks(const set <string>& sections) {
    vector <CardIndex> books;
    cout << "Available sections:" << endl;
    for (auto it = sections.begin(); it != sections.end(); it++) {
        cout << *it << endl;
    }
    string requestedSection;
    do {
        cout << "Enter the section you are interested in: ";
        getline(cin, requestedSection);
        auto it = sections.find(requestedSection);
        if (it != sections.end()) {
            break;
        }
    } while (true);
    cout << "Books in section \"" << requestedSection << "\":" << endl;
    int count = this->cards.size();
    for (int i = 0; i < count; i++) {
        if (this->cards[i].getSection() == requestedSection) {
            books.push_back(this->cards[i]);
            cout << "- " << this->cards[i].getTitle() << endl;
        }
    }
    return books;
}

void Library::getBook(const vector <CardIndex>& books) {
    string requestedTitle;
    do {
        cout << "Enter the title of the book you are interested in: ";
        getline(cin, requestedTitle);
        for (int i = 0; i < books.size(); i++) {
            if (books[i] == requestedTitle) {
                cout << books[i];
                return;
            }
        }
    } while (true);
}
