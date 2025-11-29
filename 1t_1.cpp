#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct A {
	string els;
	int mas;
};

int main() {
	setlocale(LC_ALL, "hun");
	srand((unsigned int)time(0));

	//filebeolvasás
	fstream file("asd.txt");
	if (!file.is_open()) { cout << "Nem nyilik meg :(\n"; return 1; }

	string sor;
	int s = 0;
	vector<A> list;

	while (getline(file, sor)) {
		istringstream iss(sor);
		string a;
		int b;

		while (iss >> a >> b) {
			A v;
			v.els = a;
			v.mas = b;
			list.push_back(v);
		}
		s++;
	}

	//listbejárás
	for (const A& s : list) {}

	//kiiratás
	ofstream ki("fgh.txt");
	for (const A& s : list) if (s.mas < 80) ki << "";

	return 0;
}