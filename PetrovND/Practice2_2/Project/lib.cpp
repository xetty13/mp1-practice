#include <iostream>
#include <fstream>
#include <sstream>
#include "lib.h"

bool cardIndex::operator==(const string& otherTitle) const {
    return (title == otherTitle);
}

bool cardIndex::operator!=(const string& otherTitle) const {
    return !(title == otherTitle);
}

ostream& operator<<(ostream& os, const cardIndex& card) {
    os << "Title: " << card.title << endl;
    os << "Authors: ";
    for (int i = 0; i < card.authorsCount; i++) {
        os << card.authors[i];
        if (i < card.authorsCount - 1) {
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

int lib::strCount(const string& path) {
    int count = 0;
    string line;
    ifstream file(path);
    while (getline(file, line)) {
        if (!line.empty()) {
            count++;
        }
    }
    file.close();
    return count;
}

lib::lib(const string& path) {
    int j = 0;
    this->count = strCount(path);
    this->cards = new cardIndex[count];
    ifstream file(path);
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        stringstream ss(line);
        string item;
        cardIndex card;

        getline(ss, item, ';');
        stringstream authorsStream(item);
        string author;
        card.authorsCount = 0;
        while (getline(authorsStream, author, ',')) {
            card.authorsCount++;
        }
        card.authors = new string[card.authorsCount];
        stringstream authorsStream2(item);
        int i = 0;
        while (getline(authorsStream2, author, ',')) {
            card.authors[i] = author;
            i++;
        }
        getline(ss, card.title, ';');
        getline(ss, card.publisher, ';');
        getline(ss, card.section, ';');
        string availabilityStr;
        getline(ss, availabilityStr, ';');
        if (availabilityStr == "Available") {
            card.avb = available;
        }
        else {
            card.avb = not_available;
        }
        string evaluationStr;
        getline(ss, evaluationStr, ';');
        card.evaluation = stof(evaluationStr);

        this->cards[j] = card;
        j++;
    }
    file.close();
}

lib::~lib() {
    for (int i = 0; i < this->count; i++) {
        delete[] this->cards[i].authors;
    }
    delete[] this->cards;
}

set <string> lib::booksBySection() {
    set <string> sections;
    for (int i = 0; i < this->count; i++) {
        sections.insert(this->cards[i].section);
    }
    for (string s : sections) {
        cout << "\nBooks from " << s << endl;
        for (int j = 0; j < this->count; j++) {
            if (this->cards[j].section == s) {
                cout << this->cards[j];
            }
        }
    }
    return sections;
}

vector <cardIndex> lib::findBooks(const set <string>& sections) {
    vector <cardIndex> books;
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
    for (int i = 0; i < this->count; i++) {
        if (this->cards[i].section == requestedSection) {
            books.push_back(this->cards[i]);
            cout << "- " << this->cards[i].title << endl;
        }
    }
    return books;
}

void lib::getBook(const vector <cardIndex>& books) {
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
