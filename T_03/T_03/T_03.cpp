#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "hun");
	srand((unsigned int)time(NULL));
	/*
	int n[6] = {}; int i = 0;
	for (i = 0; i < 6; i++) { do { cout << "Add meg a(z) " << i + 1 << ". számot: "; cin >> n[i]; } while (n[i] < 0 || n[i] > 100); }
	cout << "A tömb elemei: \n"; 
	for (i = 0; i < 6; i++) { cout << i + 1 << ". eleme: " << n[i] << endl;}
	for (int s : n) { if (s == 10) { cout << "Van a tömbben 10es!\n"; break; } else { cout << "Nincs benne 10es!\n"; break; } }
	float atl = 0; int ossz = 0; for (int a : n) { ossz += a; } cout << "A számok átlaga: " << (float)ossz / sizeof(n) << endl;
	int ot = 0; cout << "Az 50-nél nagyobb számok: "; for (int b : n) { if (b > 50) { cout << b << " "; ot++; } } cout << endl << "Ez összesen "<<ot<<" db!"<<endl;
	*/

	int d1[25] = {}; int d2[25] = {};
	cout << "Elsõ kocka: \n";
	for (int i = 0; i < 25; i++) { 
		int lowest = 1, highest = 12;
		int random_integer = lowest + rand() % ((highest - lowest) + 1);
		d1[i] = random_integer; 
		if ((i + 1) % 10 == 0) cout << d1[i] << endl; else { cout << d1[i] << " "; } 
	}
	cout << endl << endl;

	cout << "Második kocka: \n";
	for (int i = 0; i < 25; i++) {
		int lowest = 1, highest = 12;
		int random_integer1 = lowest + rand() % ((highest - lowest) + 1);
		d2[i] = random_integer1;
		if ((i + 1) % 10 == 0) cout << d2[i] << endl; else { cout << d2[i] << " "; }
	}
	cout << endl << endl;


	//egy tankör zh eredményeit tároljuk az alábbiak szerint:
	//a tankör létszáma: [5;15]
	//max. elérhetõ pontszám 100
	//sikeres a zh pontszám>=50
	//csak az írhatott zh-t, aki a félév során már 10 pontot elért beadandó feladatokból
	//oldjuk meg az alábbi feladatokat:
	//hozzunk létre egy megfelelõ típusú és méretû tömböt(pontok)
	//kérjük be a létszámot E.  [5;15]
	//töltsü fel a tömböt vszámgen [10;100]
	//írasuk ki a pontszámokat:
	//1. hallgató: 56 pont
	//2. hallgató: 77 pont ...
	//számítsuk ki a pontszámok átlagát
	//volt-e 100 pontos zh?
	//sikeres vagy sikertelen zh-ból volt több(egyenlõ)
	//mennyi volt a maximális pontszám?
	//a legtöbb pontot a(z) 4. hallgató éte el 98 pont
	//cseréljük meg a max. pontszámot és a 2.  hallgató pontszámait
	//és írassuk ki újra eredményeket
	//írassuki ki a sikeres hallgatok sorszámait (tömbbõl)

	int p[15]; int lsz;
	do { cout << "Kérem a látszámot[5;15]: "; cin >> lsz; } while (lsz < 5 || lsz > 15);
	for (int a = 0; a < lsz; a++) p[a] = rand() % 91 + 10;
	for (int i = 0; i < lsz; i++) cout << i + 1 << ". hallgató: " << p[i] << " pont\n"; cout << endl;
	int ossz = 0; for (int i = 0; i < lsz; i++) ossz += p[i]; cout << "A pontok átlaga: " << (float)ossz / lsz << endl;
	for (int b : p)if (b == 100) { cout << "Van benne 100 pontos!\n";  break; } else { cout << "Nincs benne 100 pontos! :(\n"; break; }
	int s = 0; int f = 0; for (int k : p)if (k < 50)f++; else { s++; } if (s > f)cout << "Sikeres vizsgából volt több! :)\n";  if (s < f) { cout << "Sikertelen vizsgákból volt több! :(\n"; } if(s==f) { cout << "Sikertelen és Sikeres vizsga ugyanannyi :|\n"; } cout << endl;
	int max = 0; for (int i = 1; i < lsz; i++) { if (p[i] > p[max]) max = i; } cout << "A legtöbb pontot a(z) " << max + 1 << ". hallgató érte el " << p[max] << " ponttal \n"; 

	int seged = p[max];
	p[max] = p[1];
	p[1] = seged;
	for (int i = 0; i < lsz; i++) cout << i + 1 << ". hallgató: " << p[i] << " pont\n";

	int eredm[15];
	int j = 0;
	for (int i = 0; i < lsz; i++) if (p[i] >= 50) { eredm[j] = i + 1; j++; }
	cout << "\nSikeresek: ";
	for (int i = 0; i < j; i++)cout << eredm[i] << "; "; cout << endl;

	return 0;
}