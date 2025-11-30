#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct A {
    string els;  
    string mas;   
};

int main() {
    setlocale(LC_ALL, "hun");
    srand((unsigned int)time(0));

    // file megnyitása
    fstream file("valaszok.txt");
    if (!file.is_open()) {cout << "Nem nyilik meg :(\n";return 1;}

    string sor;
    int s = 0;
    vector<A> list;

    while (getline(file, sor)) {
        if (s == 0) {s++; continue;}  // first line out

        istringstream iss(sor);
        string a, b;

        getline(iss, a, ' ');   // szóközzel elválasztva (vagy bármivel) első tag
        getline(iss, b);        // szóközzel elválasztva (vagy bármivel) második tag

        A v;
        v.els = a;
        v.mas = b;

        list.push_back(v);
        s++;
    }

    for (const A& s : list) {cout << s.els << " - " << s.mas << "\n"; }
    
    ofstream ki("fgh.txt");
    for (const A& t : list) {ki << t.els << "-" << t.mas << "\n";}
    

    return 0;
}

