#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "hun");

	/*
	//Irassuk ki a sz�mok �sszeg�t [1;100] mind a 3 cikulssal

	int i=0; int aa=0;
	for (i = 0; i < 101; i++) aa += i; cout << "1-100ig az �sszeg (for): " << aa << endl;
	while (i < 101) { aa += i; i++; }  cout << "1-100ig az �sszeg (while): " << aa << endl;
	do { aa += i; i++; } while (i < 101); cout << "1-100ig az �sszeg (do while): " << aa << endl;
	

	// Irassuk ki 10t�l 0ig a p�ros sz�mokat //int n; for (n = 10; n >= 0; n=n-2) cout << n << endl;

	// Feladat...
	int b = 0; int f = 0;
	cout << "K�rek egy als� hat�rt (eg�sz sz�mot 1-50 k�z�tt):"; cin >> b; if (b < 0 || b > 50) {cout << "Aztmondtam 1-50 k�z�tt: "; cin >> b; cout << endl;} else cout << "Als� hat�r:"<< b << endl;
	cout << "K�rek egy fels� hat�rt (eg�sz sz�mot 100-200 k�z�tt):"; cin >> f; if (f < 100 || f > 200) { cout << "S�ket vagy? 100-200 k�z�tt: "; cin >> f; cout << endl; }else cout << "Fels� hat�r:" << f << endl;
	int o = 0; int ossz = 0; for (o = b; o <= f; o++) ossz += o; cout << "�sszeg["<<b<<";"<<f<<"]"<<endl;
	*/

	//T�mb!
	int n[5] = { };
	//cout << sizeof(myNumbers) << endl;
	for (int i = 0; i < 5; i++) { do { cout << "Adja meg a(z) " << i + 1 << " sz�mot[1 - 100]: "; cin >> n[i]; } while (n[i] < 1 || n[i]>100); } cout << endl;
	cout << "A t�mb elemei: \n";
	for (int num : n) { cout << num[n] << ". elem: " << num << endl; } cout << endl;
	for (int s : n) if (s == 50) cout << "Szerepel 50-es sz�m!\n"; else { cout << "Nem szerepel 50-es sz�m :(\n"; break; }
	
	system("pause");
	return 0;
}