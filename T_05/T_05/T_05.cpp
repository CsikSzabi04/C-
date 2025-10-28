#include <iostream>
using namespace std;

struct Hallgato {
	string nev;
	int szev;
	int prog;
	int fizika;
};

int main() {
	setlocale(LC_ALL, "hun");
	srand((unsigned int)time(NULL));

	int lsz; int h = 0;
	do { cout << "Adja meg a létszámot: (7-20): "; cin >> lsz; } while (lsz < 7 || lsz > 20);

	Hallgato t[20];
	for (int i = 0; i < lsz; i++) {
		cout << i + 1 << ". hallgató neve (szóköz nélkül): ";
		cin >> t[i].nev;
		t[i].szev = 1995 + rand() % (2005 - 1995 + 1);
		t[i].prog = 1 + rand() % 5;
		t[i].fizika = 1 + rand() % 5;
	}

	cout << "\n    Tankör eredmények\n"; cout << "név\tsz_ev\tprog\tfiz\tátl.\n";
	for (int i = 0; i < lsz; i++) {int sum = t[i].prog + t[i].fizika;  cout << t[i].nev << "\t" << t[i].szev << "\t" << t[i].prog << "\t" << t[i].fizika<< "\t" << (float)sum/2 << endl;}

	float progs = 0.0f, fiz = 0.0f;
	for (int i = 0; i < lsz; i++) { progs += t[i].prog; fiz += t[i].fizika; }
	float avg0 = progs / lsz;  float avg1 = fiz / lsz;

	cout << "\nProgramozás átlag: " << avg0 << endl;  cout << "Fizika átlag:      " << avg1 << endl;

	if (avg0 > avg1) cout << "Jobb: Programozás" << endl; else if (avg0 < avg1) cout << "Jobb: Fizika" << endl; else cout << "Mindkét tantárgy átlaga egyenlõ.\n";

	bool buk = false;
	for (int i = 0; i < lsz; i++) if (t[i].fizika == 1) { buk = true; break; }
	cout << "\nVolt-e bukás fizikából? " << (buk ? "Igen" : "Nem") << endl;

	bool jel = false;
	for (int i = 0; i < lsz; i++) if (t[i].prog == 5) { jel = true; break; }
	cout << "Volt-e jeles programozásból? " << (jel ? "Igen" : "Nem") << endl;

	int min = t[0].szev;  string nev1 = ""; int most = 2025;
	for (int i = 1; i < lsz; i++) if (t[i].szev < min) { min = t[i].szev; nev1 = t[i].nev;}
	cout << "\nLegidõsebb hallgató " << nev1 << "aki most (2025)" << most-min << " éves\n";

	int ev = 2025; int plusz = 0;
	for (int i = 0; i < lsz; i++) {	int kor =ev - t[i].szev;if (kor > 25) ++plusz;}
	cout << "\n25 év feletti hallgatók száma: " << plusz << endl;


	cout << "\nMindkét tárgyat teljesítették: " << endl;
	bool voltTeljesito = false;
	for (int i = 0; i < lsz; i++) if (t[i].prog >= 2 && t[i].fizika >= 2) {cout << t[i].nev << ", "; voltTeljesito = true; }
	if (!voltTeljesito) cout << "Nincs ilyen hallgató." << endl;

	system("pause");
	return 0;
}