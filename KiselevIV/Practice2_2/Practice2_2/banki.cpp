#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "banki.h"
#define LENGTH 512
#define LEN 30

using namespace std;

int strcount(string path) {
    int stringcount = 0;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "ERROR: Could not open file!" << endl;
    }
    else {
        string line;
        while (getline(file, line))
        {
            if (line != "\0") {
                stringcount++;
            }
        }
        file.close();
    }
    return stringcount;
}

banklib::banklib(const string& path) {
    int stringcount = strcount(path);
    this->banki = new bankstruct[stringcount];
    this->count = stringcount;
    int i = 0;
    int j = 0;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "ERROR: Could not open file!" << endl;
    }
    else {
        string str;
        string line;
        string token;
        ifstream file(path);
        while (getline(file, line))
        {
            if (line == "\0") {
                continue;
            }
            stringstream ss(line);
            while (getline(ss, token, ',')) {
                switch (i) {
                case 0:
                    banki[j].bankname = token;
                    break;
                case 1:
                    banki[j].banktype = token;
                    break;
                case 2:
                    banki[j].count = stoi(token);
                    banki[j].our_vklad = new vkladstruct[banki[j].count];
                    break;
                case 3:
                    banki[j].our_vklad[0].vkladname = token;
                    break;
                case 4:
                    banki[j].our_vklad[0].rate = stoi(token);
                    break;
                case 5:
                    banki[j].our_vklad[0].times = stoi(token);
                    if (banki[j].count == 1) {
                        i = -1;
                        j++;
                    }
                    break;
                case 6:
                    banki[j].our_vklad[1].vkladname = token;
                    break;
                case 7:
                    banki[j].our_vklad[1].rate = stoi(token);
                    break;
                case 8:
                    banki[j].our_vklad[1].times = stoi(token);
                    if (banki[j].count == 2) {
                        i = -1;
                        j++;
                    }
                    break;
                case 9:
                    banki[j].our_vklad[2].vkladname = token;
                    break;
                case 10:
                    banki[j].our_vklad[2].rate = stoi(token);
                    break;
                case 11:
                    banki[j].our_vklad[2].times = stoi(token);
                    if (banki[j].count == 3) {
                        i = -1;
                        j++;
                    }
                    break;
                }
                i++;
            }
        }
    }
    file.close();

}


void banklib::search(float sum, int kMonths, string vkladType) {
    int a = 0;
    if (vkladType == "saving") {
        a = 0;
    }
    else if (vkladType == "debit") {
        a = 1;
    }
    else if (vkladType == "cumulative") {
        a = 2;
    }
    int maxI = 0;
    int i;
    float maxproc = -1;
    int koef = 0;
    int j = 0;
    int k = 0;
    for (i = 1; i < this->count; i++) {
        if (banki[i].count >= (a + 1)) {
            if (banki[i].our_vklad[a].rate > maxproc && kMonths >= banki[i].our_vklad[a].times) {
                koef = (int)kMonths / banki[i].our_vklad[a].times;
                maxproc = banki[i].our_vklad[a].rate;
                maxI = i;
            }
        }
    }
    double final_sum = sum;
    double s = (double)banki[maxI].our_vklad[a].times / 12;
    for (j = 0; j < koef; j++) {
        final_sum *= (double)(1.00 + maxproc * s / 100);
    }
    if (maxproc == -1) {
        cout << "The debit invest is not suitable for the terms" << endl;
    }
    else {
        //cout << banki[maxI];
        //cout << banki[maxI].our_vklad[a];
        cout << "If your invest " << sum << ", you will receive " << final_sum << endl;
    }
    //return *this;
}
banklib::~banklib() {
    for (int i = 0; i < count; i++) {
        delete[] banki[i].our_vklad;
    }
    delete[] banki;
}
/*ostream& operator<<(ostream& os, const vkladstruct& our_vklad) {
    os << "-----------------------" << endl;
  //  os << "Name of bank - " << banki.bankname << endl;
    //os << "Type of bank - " << banki.banktype << endl;
    os << "-----------------------" << endl;
    return os;
}*/
ostream& operator<<(ostream& os, const banklib& banks) {
    os << "-----------------------" << endl;
    for (int i = 0; i < banks.count; i++) {
        os << "Name of bank - " << banks.banki[i].bankname << " ";
        os << "Type of  bank - " << banks.banki[i].banktype << endl;
        for (int j = 0; j < banks.banki[i].count; j++) {
            os << "    Vkladname of  bank - " << banks.banki[i].our_vklad[j].vkladname << " ";
            os << "Times of vklad- " << banks.banki[i].our_vklad[j].times << " ";
            os << "Rate of vklad - " << banks.banki[i].our_vklad[j].rate << endl;
        }
        os << endl;
    }
    os << "-----------------------" << endl;
    return os;
}
/*bestbank::bestbank(int stringcount) {
    this->banki = new bankstruct[stringcount];
    this->stringcount = stringcount;
}
*/
string getfile() {
    string path;
    while (true) {
        cout << "Enter the full location of the file" << endl;
        getline(cin, path);
        ifstream file(path);
        if (file.good()) {
            file.close();
            return path;
        }
        else {
            cout << "ERROR: Could not open file!\n" << endl;
        }
    }

}



/*ostream& operator<<(ostream& os, const bankstruct& banki) {
    os << "-----------------------" << endl;
    os << "Name of bank - " << banki.bankname << endl;
    os << "Type of  bank - " << banki.banktype << endl;
    os << "-----------------------" << endl;
    return os;
}
*/
/*ostream& operator<<(ostream& os, const vkladstruct& our_vklad) {
    os << "Name of vklad - " << our_vklad.vkladname << endl;
    os << "Rate  of vklad - " << our_vklad.rate << endl;
    os << "Minimum times of  vklad - " << our_vklad.times << endl;
    os << "-----------------------" << endl;
    return os;
}*/

