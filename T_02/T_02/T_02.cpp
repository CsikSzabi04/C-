#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "hun");

	/*
	//Irassuk ki a számok összegét [1;100] mind a 3 cikulssal

	int i=0; int aa=0;
	for (i = 0; i < 101; i++) aa += i; cout << "1-100ig az összeg (for): " << aa << endl;
	while (i < 101) { aa += i; i++; }  cout << "1-100ig az összeg (while): " << aa << endl;
	do { aa += i; i++; } while (i < 101); cout << "1-100ig az összeg (do while): " << aa << endl;
	

	// Irassuk ki 10tõl 0ig a páros számokat //int n; for (n = 10; n >= 0; n=n-2) cout << n << endl;

	// Feladat...
	int b = 0; int f = 0;
	cout << "Kérek egy alsó határt (egész számot 1-50 között):"; cin >> b; if (b < 0 || b > 50) {cout << "Aztmondtam 1-50 között: "; cin >> b; cout << endl;} else cout << "Alsó határ:"<< b << endl;
	cout << "Kérek egy felsõ határt (egész számot 100-200 között):"; cin >> f; if (f < 100 || f > 200) { cout << "Süket vagy? 100-200 között: "; cin >> f; cout << endl; }else cout << "Felsõ határ:" << f << endl;
	int o = 0; int ossz = 0; for (o = b; o <= f; o++) ossz += o; cout << "Összeg["<<b<<";"<<f<<"]"<<endl;
	*/

	//Tömb!
	int n[5] = { };
	//cout << sizeof(myNumbers) << endl;
	for (int i = 0; i < 5; i++) { do { cout << "Adja meg a(z) " << i + 1 << " számot[1 - 100]: "; cin >> n[i]; } while (n[i] < 1 || n[i]>100); } cout << endl;
	cout << "A tömb elemei: \n";
	for (int num : n) { cout << num[n] << ". elem: " << num << endl; } cout << endl;
	for (int s : n) if (s == 50) cout << "Szerepel 50-es szám!\n"; else { cout << "Nem szerepel 50-es szám :(\n"; break; }
	
	system("pause");
	return 0;
}