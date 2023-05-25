#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "banki.h"
#define LENGTH 512
#define LEN 30

using namespace std;


banklib::banklib(const string& path) {
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
        
    }
  
    //int stringcount = strcount(path);
    this->banki = new bankstruct[stringcount];
    this->count = stringcount;
    int i = 0;
    int j = 0;
    //ifstream file(path);
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


banklib& banklib::search(float sum, int kMonths, string vkladType) {
    this->vkladType = vkladType;
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
        cout << banki[maxI];
        cout << banki[maxI].our_vklad[a];
        cout << "If your invest " << sum << ", you will receive " << final_sum << endl;
    }
    return *this;
}
banklib::~banklib() {
    for (int i = 0; i < count; i++) {
        delete[] banki[i].our_vklad;
    }
    delete[] banki;
}

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


banklib::banklib(const banklib& banks) {
    //return *this;//опер присваивания
    count = banks.count;
    banki = new bankstruct[count];

    for (int i = 0; i <count; i++) {
        banki[i].bankname = banks.banki[i].bankname;
        banki[i].banktype = banks.banki[i].banktype;
        //banki[i].count = banks.banki[i].count;
        int a;
        if (banks.vkladType == "saving") {
            a = 0;
        }
        else if (banks.vkladType == "debit") {
            a = 1;
        }
        else if (banks.vkladType == "cumulative") {
            a = 2;
        }
        banki[i].count = 1;
        banki[i].our_vklad = new vkladstruct[banki[i].count];
        for (int j = 0; j < banks.banki[i].count; j++) {
            if(banks.banki[i].our_vklad[j].vkladname == banks.vkladType){
                banki[i].our_vklad[0].rate = banks.banki[i].our_vklad[a].rate;
                banki[i].our_vklad[0].times = banks.banki[i].our_vklad[a].times;
                banki[i].our_vklad[0].vkladname = banks.banki[i].our_vklad[a].vkladname;
            }
            else {
                banki[i].our_vklad[0].rate = 0;
                banki[i].our_vklad[0].times = 0;
                banki[i].our_vklad[0].vkladname = "nothing";
            }
        }
    }
    //return *this;//опер присваивания
    
}
bool vkladstruct::operator==(const string& vkladType) const {
    return (vkladname == vkladType);
}

bool vkladstruct::operator!=(const string& vkladType) const {
    return !(vkladname == vkladType);
}

ostream& operator<<(ostream& os, const banklib& banks) {
    /*int count = 0;
    if (banks.vkladType == "saving") {
        count = 1;
    }
    else if (banks.vkladType == "debit") {
        count = 1;
    }
    else if (banks.vkladType == "cumulative") {
        count = 1;
    }*/
    os << "-----------------------" << endl;
    for (int i = 0; i < banks.count; i++) {
        //os << banks.banki[i];
        for (int j = 0; j < banks.banki[i].count; j++) {
            if (banks.banki[i].our_vklad[j].vkladname != "nothing") {
                os << banks.banki[i];
                os << banks.banki[i].our_vklad[j] << " ";
                os << endl;
            }
        }
    }
    os << "-----------------------" << endl;
    //count++;
    return os;
}
ostream& operator<<(ostream& os, const bankstruct& banki) {
    os << "Name of bank - " << banki.bankname << " ";
    os << "Type of  bank - " << banki.banktype << endl;
    return os;
}
ostream& operator<<(ostream& os, const vkladstruct& our_vklad) {
    os << "    Name of vklad - " << our_vklad.vkladname << " ";
    os << "    Rate  of vklad - " << our_vklad.rate << " ";
    os << "    Minimum times of  vklad - " << our_vklad.times << endl;
    return os;
}

