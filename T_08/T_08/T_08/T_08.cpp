#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
using namespace std;

struct Jatekos {
	string nev;
	int szul_ev;
	int p1;
	int p2;
	int p3;
	int ossz;
};

int main() {

	setlocale(LC_ALL, "hun");
	srand((unsigned int)time(0));

	//fájl beolvasás
	ifstream file("vetelked.txt");
	if (!file.is_open()) {cout << "Nem sikerült megnyitni a fájlt!\n"; return 1;}

	string sor; 
	int sorSzam = 0;
	vector<Jatekos> csapat1, csapat2;

	while (getline(file, sor)) {
		istringstream iss(sor);
		string nev;
		int ev;

		while (iss >> nev >> ev) {
			Jatekos j;
			j.nev = nev;
			j.szul_ev = ev;
			j.p1 = rand() % 11;
			j.p2 = rand() % 11;
			j.p3 = rand() % 11;
			j.ossz = j.p1 + j.p2 + j.p3;
			if (sorSzam == 0) { csapat1.push_back(j); }
			else if (sorSzam == 1) csapat2.push_back(j);
		}
		sorSzam++;

	}

	cout << "Eminensek\n\t név (szül.)\t 1.ford\t 2.ford\t 3.ford\t összp.\n";
	for (const Jatekos& s : csapat1) {cout << "\t " << s.nev << "(" << s.szul_ev << ")\t " << s.p1 << "\t " << s.p2 << "\t " << s.p3 << "\t " << s.ossz << "\n";}
	int oszl1 = 0, oszl2 = 0, oszl3 = 0, oszlossz1=0;
	for (const Jatekos& s : csapat1) {
		oszl1 += s.p1;
		oszl2 += s.p2;
		oszl3 += s.p3;
		oszlossz1 += s.ossz;
	}
	int atl1 = csapat1.size();
	cout << "\t összesen: \t " << oszl1 << "\t " << oszl2 << "\t " << oszl3 << "\t " << oszlossz1 << "\t pont   csapatátlag: " << atl1 << "\n";

	cout << "Tudorok\n\t név (szül.)\t 1.ford\t 2.ford\t 3.ford\t összp.\n";
	for (const Jatekos& s : csapat2) { cout << "\t " << s.nev << "(" << s.szul_ev << ")\t " << s.p1 << "\t " << s.p2 << "\t " << s.p3 << "\t " << s.ossz << "\n"; }
	int oszl4 = 0, oszl5 = 0, oszl6 = 0, oszlossz2 = 0;
	for (const Jatekos& s : csapat2) {
		oszl4 += s.p1;
		oszl5 += s.p2;
		oszl6 += s.p3;
		oszlossz2 += s.ossz;
	}
	int atl2 = csapat2.size();
	cout << "\t összesen: \t " << oszl4 << "\t " << oszl5 << "\t " << oszl6 << "\t " << oszlossz2 << "\t pont   csapatátlag: " << atl2 << "\n";

	cout << "Végeredmény: ";
	

	return 0;
}