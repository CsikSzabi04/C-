#include<iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "hun");

	/*
	
	//1.)

	//Kör kerülete/területe
	double r = 12.5;
	cout << "kerület: " << 2 * r * 3.14 << endl;
	cout << "területe: " << r * r * 3.14 << endl;
	cout << "\n";

	//2.)
	//adatbekérés - cin
	//Kérjük be egy téglalap 2 
	//oldalát és irassuk ki
	//Kerületét és Területét
	float old1, old2;
	cout << "Kérem a téglalap egyik oldalát: "; cin >> old1;
	cout << "Kérem a téglalap másik oldalát: ";  cin >> old2;
	system("cls");
	cout << "Oldalak: \n a:" << old1 << "	 b:" <<old2 << endl << " Kerület: " << 2*(old1+old2) << "\n Terület: " << old1 * old2 << endl;
	

	//3.)
	//Kérjünk be két egés számot és irassuk ki: +,-,*,/,%
	int sz1, sz2;
	cout << "Kérek egy egész számot: "; cin >> sz1;
	cout << "Kérek egy másik egész számot: "; cin >> sz2;
	system("cls");
	cout << "Szám1: " << sz1 << "	Szám2: " << sz2 << "\n A számok összege: " << sz1 + sz2 << "\n A számok különbsége: " << sz1 - sz2 << "\n A számok szorzata " << sz1 * sz2 << "\n A számok osztva maradék nélkül: " << sz1 / sz2 << "\n A számok osztás maradéka: " << sz1 % sz2 << endl;

	//4.)
	char betu = 'A'; int b;
	cout << "Karakter kiratása betûvel: " << betu << " " << "Számmal: " << b << endl;
	
	//5.)
	//vezérlési szerkezetek - if
	//Kérjünk be egy egész számot és irassuk ki: páros/páratlan
	int sz01;
	cout << "Kérek egy számot: "; cin >> sz01;
	if (sz01 % 2 == 0) cout << "Ez a szám páros\n"; else cout << "Ez a szám páratlan\n";
	

	//6.)
	int sz04; cout << "Kérek egy számot: "; cin >> sz04;
	if (sz04 > 10) cout << "Ez nagyobb mint 10\n"; if (sz04 == 10) cout << "Ez a szám egyenlõ 10el\n";  else cout << "Ez kisebb mint 10\n";
	

	//7.)
	//Kérjünk be egy egész számot és irassuk ki: pozitív vagy negatíB
	int b; cout << "Kérek egy számot: "; cin >> b;
	if (b < 0) cout << "Ez negatív szám\n"; if (b > 0) cout << "Ez a szám pozitív\n"; else cout << "Ez se nem pozitív se nem negatív\n";
	

	//8.)
	//ciklusok - for
	//Irassuk ki a keresztnevünket egymás alá 10x sorszámozottan

	string n; cout << "Kérem a keresztenved: "; cin >> n;
	int i;  for (i = 1; i <= 10; i++) cout << i << ". "<< n << endl;

	*/

	system("pause");
	return 0;
}