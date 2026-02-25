#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct adat{
	string nev;
	int pont;
};

int Osszegez(adat csoport[], int n){
	int ossz = 0;
	for (int i = 0; i < n; i++)ossz += csoport[i].pont;
	return ossz;
}

int main()
{
	adat csoport[20];
	int i = 0;
	ifstream be("pontok.txt");

	if (be.fail())cerr << "Hiba a file beolvasasnal .";

	while (!be.eof() && i < 20){
		be >> csoport[i].nev;
		be >> csoport[i].pont;
		cout << setw(10) << csoport[i].nev << "\t" << csoport[i].pont << endl;
		i++;
	}
	be.close();

	int osszpont = Osszegez(csoport, i);
	float atlag = (float)osszpont / i;
	cout << "Az ossz bonuszpontszam: " << osszpont << endl;
	cout << "Az atlag bonuszpontszam: " << atlag << endl;
	
	return 0;
}