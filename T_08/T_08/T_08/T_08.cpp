#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Jatekos {
	string nev;
	int ev;
	int p1;
	int p2;
	int p3;
	int ossz;
};

int main() {
	setlocale(LC_ALL, "hun");
	srand((unsigned int)time(0));

	fstream file("vetelked.txt");
	if (!file.is_open()) { cout << "Nem nyit meg!\n"; return 1; }

	string sor;
	int s = 0;
	vector<Jatekos> csapat1, csapat2;

	while (getline(file, sor)) {
		istringstream iss(sor);
		string nev;
		int ev;

		while (iss >> nev >> ev) {
			Jatekos j;
			j.nev = nev;
			j.ev = ev;
			j.p1 = rand() % 11;
			j.p2 = rand() % 11;
			j.p3 = rand() % 11;
			j.ossz = j.p1 + j.p2 + j.p3;
			if (s == 0) csapat1.push_back(j);
			if (s == 1) csapat2.push_back(j);
		}
		s++;
	}
	 
	cout << "Eminensek\n\t név(szül.)\t 1.ford\t 2.ford\t 3.ford\t összp.\n";
	for (const Jatekos& s : csapat1) { cout << "\t " << s.nev << "(" << s.ev << ")\t " << s.p1 << "\t " << s.p2 << "\t " << s.p3 << "\t "<<s.ossz<<"\n"; }
	int o1 = 0, o2 = 0, o3 = 0, ossz = 0; int p = 0;
	for (const Jatekos& s : csapat1) { o1 += s.p1; o2 += s.p2; o3 += s.p3; ossz += s.ossz; p++; }
	float atl1 = ossz / p;
	cout << "\t összesen:\t " << o1 <<"\t " << o2 << "\t " << o3 << "\t " << ossz << " pont  csapatátlag: " << atl1 << endl;
	int lg = 0; string nev1 = "";
	for (const Jatekos& s : csapat1) { if (s.ossz > lg) { lg = s.ossz; nev1 = s.nev; } }
	cout << "a csapat legjobbja: " << nev1 << " " << lg << " ponttal\n";

	cout << "Tudorok\n\t név(szül.)\t 1.ford\t 2.ford\t 3.ford\t összp.\n";
	for (const Jatekos& s : csapat2) { cout << "\t " << s.nev << "(" << s.ev << ")\t " << s.p1 << "\t " << s.p2 << "\t " << s.p3 << "\t " << s.ossz << "\n"; }
	int o4 = 0, o5 = 0, o6 = 0, ossz1 = 0; int p1 = 0;
	for (const Jatekos& s : csapat2) { o4 += s.p1; o5 += s.p2; o6 += s.p3; ossz1 += s.ossz; p1++; }
	float atl2 = ossz1 / p1;
	cout << "\t összesen:\t " << o4 << "\t " << o5 << "\t " << o6 << "\t " << ossz1 << " pont  csapatátlag: " << atl2 << endl;
	int lg1 = 0; string nev2 = "";
	for (const Jatekos& s : csapat2) { if (s.ossz > lg1) { lg1 = s.ossz; nev2 = s.nev; } }
	cout << "a csapat legjobbja: " << nev2 << " " << lg1 << " ponttal\n";
	cout << "\n";

	if (ossz > ossz1) cout << "Végeredmény: Eminensek - Tudorok " << ossz << ":" << ossz1 << "\n";
	if (ossz < ossz1) cout << "Végeredmény: Tudorok - Eminensek " << ossz1 << ":" << ossz << "\n";
	if (ossz == ossz1) cout << "Végeredmény: Döntetlen!\n";
	
	bool i = false;

	if (o1 > 25) { cout << "A(z) Eminensek csapat 25-nél több, azaz " << o1 << "pontot ért el a(z) 1. fordulóban\n"; i = true; }
	if (o2 > 25) { cout << "A(z) Eminensek csapat 25-nél több, azaz " << o2 << "pontot ért el a(z) 2. fordulóban\n"; i = true;}
	if (o3 > 25) { cout << "A(z) Eminensek csapat 25-nél több, azaz " << o3 << "pontot ért el a(z) 3. fordulóban\n"; i = true;}
	if (o4 > 25) { cout << "A(z) Tudorok csapat 25-nél több, azaz " << o4 << "pontot ért el a(z) 1. fordulóban\n"; i = true;}
	if (o5 > 25) { cout << "A(z) Tudorok csapat 25-nél több, azaz " << o5 << "pontot ért el a(z) 2. fordulóban\n"; i = true;}
	if (o6 > 25) { cout << "A(z) Tudorok csapat 25-nél több, azaz " << o6 << "pontot ért el a(z) 3. fordulóban\n"; i = true;}
	if (o1 < 25 && o2 < 25 && o3 < 25 && o4 < 25 && o5 < 25 && o6 < 25 && i == true) { cout << "Egyik csapat egyik fordulóban sem ért el 25-nél több pontot\n"; }

	return 0;
}
