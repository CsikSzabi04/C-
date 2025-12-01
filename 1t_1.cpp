#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct A {
	int p0, p1;
	string v0, v1;
	int sl1;
	int pl1;
};

int main() {
	setlocale(LC_ALL, "hun");
	
	fstream file("merkozes.txt");
	if (!file.is_open()) { cout << "Nem nyílik meg\n"; return 1; }

	string sor;
	vector<A> list;

	while (getline(file, sor)) {
		istringstream iss(sor);

		A s;
		iss >> s.p0 >> s.p1 >> s.v0 >> s.v1;

		s.sl1 = rand() % 4 + 2;
		
		do {
			cout << s.v0 << " - " << s.v1 << " piros lap (0-4): ";
			cin >> s.pl1;
		} while (s.pl1 < 0 || s.pl1 > 4);

		list.push_back(s);
	}

	cout << "\nÖsszesen " << list.size() << " mérkőzés volt\n";
	for (const A& s : list) cout << s.v0 << " - " << s.v1 << " " << s.p0 << " : " << s.p1 << " sárgalap:" << s.sl1 << " piroslap: " << s.pl1 << "\n";

	int o = 0;
	for (const A& s : list) o += s.p1 + s.p0;
	cout << "\nA fordulóban az összes gól: " << o << "\n";

	A legk = list[0];   
	for (const A& s : list) if (s.p0 + s.p1 < legk.p0 + legk.p1) legk = s;   
	cout << "\nA legkevesebb gólos mérkőzés: "<< legk.v0 << " - " << legk.v1 << " "<< legk.p0 << " : " << legk.p1<< " sárgalap:" << legk.sl1<< " piroslap:" << legk.pl1 << "\n";

	int h = 0, v = 0, d = 0;
	for (const A& s : list) {if (s.p0 > s.p1) h++;if (s.p0 < s.p1) v++;if (s.p0 == s.p1) d++;}
	cout << "\nhazai gy: " << h << " vendég gy: " << v << " döntetlen: " << d << endl << "\n";

	for (const A& s : list) if (s.p0 + s.p1 < 6) cout << s.v0 << " - " << s.v1 << " " << s.p0 << " : " << s.p1 << endl;

	return 0;
}
