#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Gyartas {
    string gy_azon;
    string alk_azon;
    int db;
    int ido_perc;
    int total_perc;
    int total_ora;
};

int main() {
    setlocale(LC_ALL, "hun");
    srand((unsigned int)time(0));

    string alkaz[6] = { "G24", "M90", "W31", "X21", "V11", "W33" };
    Gyartas gy[15];

    for (int i = 0; i < 15; ++i) {
        gy[i].gy_azon = "gy" + to_string(i + 1);
        gy[i].alk_azon = alkaz[rand() % 6];
        gy[i].db = 10 + rand() % (100 - 10 + 1);
        gy[i].ido_perc = 10 + rand() % (20 - 10 + 1);
        gy[i].total_perc = gy[i].db * gy[i].ido_perc;
        gy[i].total_ora = (gy[i].total_perc + 59) / 60;
    }

    cout << "Gyártási adatok\n\n";
    cout << "    gyártás alk.r gy.db idő/db  összi_p  összi_ó\n";
    for (int i = 0; i < 15; ++i) {
        cout << "    "
            << gy[i].gy_azon << string(8 - gy[i].gy_azon.length(), ' ')
            << gy[i].alk_azon << string(6 - gy[i].alk_azon.length(), ' ')
            << (gy[i].db < 10 ? "  " : (gy[i].db < 100 ? " " : "")) << gy[i].db << "    "
            << (gy[i].ido_perc < 10 ? " " : "") << gy[i].ido_perc << "     "
            << (gy[i].total_perc < 1000 ? (gy[i].total_perc < 100 ? "   " : "  ") : " ") << gy[i].total_perc << "     "
            << (gy[i].total_ora < 10 ? " " : "") << gy[i].total_ora
            << endl;
    }


    int sum_perc = 0;
    int sum_ora = 0;
    for (int i = 0; i < 15; ++i) {sum_perc += gy[i].total_perc; sum_ora += gy[i].total_ora; }
    double avg_perc = (double)sum_perc / 15.0;
    double avg_ora = (double)sum_ora / 15.0;
    cout << "\nA gyártási idők átlaga(perc): " << avg_perc << " perc\n"<< "A gyártási idők átlaga(óra): " << avg_ora << " óra\n";



    string keres;
    cout << "\nKérek egy alkatrészt(G24 M90 W31 X21 V11 W33): ";
    cin >> keres;
    int total_db = 0;
    for (int i = 0; i < 15; ++i) {
        if (gy[i].alk_azon == keres)
            total_db += gy[i].db;
    }
    cout << "Összesen " << total_db << " db-ot gyártottak az adott alkatrészből.\n";



    bool volt = false;
    cout << "\n12 óránál hosszabb gyártások:\n";
    for (int i = 0; i < 15; ++i) {
        if (gy[i].total_ora > 12) {
            cout << "\t" << gy[i].gy_azon << "\t" << gy[i].alk_azon << "\t" << gy[i].total_perc << " perc\n";
            volt = true;
        }
    } if (!volt) { cout << "Nem volt 12 óránál hosszabb gyártás!\n"; }

    int minIdx = 0;
    for (int i = 1; i < 15; ++i)
        if (gy[i].total_perc < gy[minIdx].total_perc)
            minIdx = i;
    cout << endl << gy[minIdx].gy_azon << " gyártás volt a legrövidebb " << gy[minIdx].total_perc << " perc\n";


    int max_db = 0; string max_alk = "";
    for (int i = 0; i < 6; ++i) {
        int osszdb = 0;
        for (int j = 0; j < 15; ++j) if (gy[j].alk_azon == alkaz[i]) osszdb += gy[j].db; if (osszdb > max_db) { max_db = osszdb; max_alk = alkaz[i]; }
    }
    cout << max_alk << " alkatrészből gyártottak a legtöbbet " << max_db << " db\n";


    bool voltnincs = false;
    for (int i = 0; i < 6; ++i) {
        bool voltgy = false;
        for (int j = 0; j < 15; ++j) { if (gy[j].alk_azon == alkaz[i]) {voltgy = true; break;}}
        if (!voltgy) {cout << "Nem volt gyártás: " << alkaz[i] << endl; voltnincs = true;}}
    if (!voltnincs) cout << "Nem volt olyan alkatrész, amelyikből nem gyártottak\n";

    return 0;
}


/*

NJE GAMF Műszaki és Informatika Kar
Informatika Tanszék
Programozás feladat-gyártás
Egy járműalkatrészeket készítő gyártó-sor gyártásainak adatait tároljuk az alábbiak szerint:
- az alkatrész azonosítóját(6 féle)
- az alkatrészből legyártott darabszámot
- egy alkatrész elkészítéséhez szükséges gyártási időt percben(gyártásonként változhat)
pl.: G24 120 12
a gyártás során a G24 alkatrészből 120 db készült – 1 db 12 perc alatt készül el
- egy gyártás alatt csak egy féle alkatrészt készül
- 15 gyártás adatait tároljuk, gyártás azonosítása: ”gy” + sorszám 1-15-ig pl.: gy1, gy2…
Hozzon létre egy megfelelő méretű és típusú tömböt a gyártások adatainak tárolására és egy másikat az
alkatrész azonosítóknak! – (string alkaz[6] = {"G24", "M90", "W31", "X21", ”V11” ", ”W33”};)
Készítsen programot, amely megoldja az alábbi feladatokat!
1. Töltse fel a gyártások adatait:
a. véletlenszerűen az alkatrészek azonosítóit az alkaz tömbből!
b. generáljon legyártott darabszámokat - [10 – 100]!
c. generáljon gyártási időket [10 – 20] perc!
d. számolja ki a gyártások időtartamát percben, órában – minden megkezdett óra számít!
2. Írja ki képernyőre az adatokat „táblázatos” formában! (lásd minta!)
3. Számolja ki a gyártási idők átlagát (perc és óra is)!
4. Kérjen be egy alkatrész azonosítót és írja ki, hogy összesen hány darabot gyártottak belőle!
5. Volt – e 12 óránál hosszabb gyártás, ha volt(lehet, hogy több is volt) írja ki az gyártás azonosítóit,
az alkatrészek azonosítóit és a gyártások időtartamát percben, ha nem volt azt is írassa ki!
6. Írassa ki a legrövidebb ideig tartó gyártás adatait(gyártás azonosító, időtartam)!
7. Melyik alkatrészből gyártottak a legtöbbet?
8. Volt-e olyan termék, amelyikből nem volt gyártás!
futtatási képernyőkép(minta):

*/