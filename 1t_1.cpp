#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct A {
    string els;  
    string mas;   
    int p;
};


int Osszpont(const vector<A>& list) {
    int ossz = 0;
    for (const A& s : list) ossz += s.p;
    return ossz;
}

int main() {
    setlocale(LC_ALL, "hun");
    srand((unsigned int)time(0));

    // file megnyitása
    fstream file("valaszok.txt");
    if (!file.is_open()) { cout << "Nem nyilik meg :(\n"; return 1; }

    string sor;
    string elsosor;
    int s = 0;
    vector<A> list;
    int pp = 0;

    while (getline(file, sor)) {
        if (s == 0) { elsosor = sor; s++; continue; }  // first line out

        istringstream iss(sor);
        string a, b;

        getline(iss, a, ' ');   // szóközzel elválasztva (vagy bármivel) elsõ tag
        getline(iss, b);        // szóközzel elválasztva (vagy bármivel) második tag

        A v;
        v.els = a;
        v.mas = b;
        v.p = 0;
        for (int i = 0; i < elsosor.size() && i < v.mas.size(); i++) { if (v.mas[i] == elsosor[i]) { v.p++; } }
        list.push_back(v);
        s++;
    }



    cout << elsosor << "\t\t helyes válaszok\n";
    int a = 1;
    for (const A& s : list) { cout << s.els << "  " << s.mas << "\t " << a << ".versenyzó kódjai és adatai (pontjai: " << s.p << ")\n"; a++; }

    cout << "\nÖsszesen " << a - 1 << " versenyzõ vett részt\n";
    int k = 0; string n; for (const A& s : list)if (s.p > k) { k = s.p; n = s.els; } cout << "A legtöbbpontot elérte: " << n << ": " << k << "\n";
    for (const A& s : list) if (s.mas == elsosor) cout << "Maximálisat elért versenyzõ: " << s.els << " - " << s.p << " pont\n";
    
    int asd = elsosor.size()/2; int o = 0;
    for (const A& s : list) if(s.p < asd) o++;
    cout << "A versenyzõkbõl " << o << "-an nem tudtak válaszolni a felére.\n";

    int ossz = Osszpont(list);
    cout << "Összesen az összes versenyzõ pontja: " << ossz << "\n";
    

    return 0;
}
