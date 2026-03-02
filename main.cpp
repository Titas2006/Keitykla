#include <iostream>
#include <iomanip>
#include <limits>
#include <iomanip>

using namespace std;

// ===== SAUGUS INT IVEDIMAS =====
int saugusInt(int min, int max) {
    int x;

    while (true) {
        cin >> x;

        if (cin.fail()) {
            cout << "Privalo buti skaicius: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (x < min || x > max) {
            cout << "Pasirinkimas turi buti tarp " << min << " ir " << max << ": ";
        }
        else {
            return x;
        }
    }
}

// ===== SAUGUS DOUBLE IVEDIMAS =====
double saugusDouble() {
    double x;

    while (true) {
        cin >> x;

        if (cin.fail()) {
            cout << "Privalo buti skaicius: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (x <= 0) {
            cout << "Suma turi buti teigiama: ";
        }
        else {
            return x;
        }
    }
}

int main() {

    // ===== Kursai (kiek gaunama uz 1 EUR) =====
    double kursaiBendri[4] = {1.0, 0.8729, 1.1793, 104.6918};
    double kursaiPirkti[4] = {1.0, 0.8600, 1.1460, 101.3862};
    double kursaiParduoti[4] = {1.0, 0.9220, 1.2340, 107.8546};

    while (true) {

        cout << "\n====================================\n";
        cout << "         VALIUTOS KEITYKLA\n";
        cout << "====================================\n";
        cout << " 1 - Palyginti valiutos kursa\n";
        cout << " 2 - Pirkti valiuta\n";
        cout << " 3 - Parduoti valiuta\n";
        cout << " 4 - Iseiti\n";
        cout << "------------------------------------\n";
        cout << "Pasirinkite: ";

        int pasirinkimas = saugusInt(1, 4);

        if (pasirinkimas == 4) {
            cout << "Programa isjungiama.\n";
            break;
        }

        cout << "\nPasirinkite valiuta:\n";
        cout << "1 - EUR\n";
        cout << "2 - GBP\n";
        cout << "3 - USD\n";
        cout << "4 - INR\n";
        cout << "Pasirinkite: ";
        int isVal = saugusInt(1, 4);

        cout << "\nPasirinkite pirmine valiuta:\n";
        cout << "1 - EUR\n";
        cout << "2 - GBP\n";
        cout << "3 - USD\n";
        cout << "4 - INR\n";
        cout << "Pasirinkite: ";
        int iVal = saugusInt(1, 4);

        if (isVal == iVal) {
            cout << "Negalite keisti i ta pacia valiuta!\n";
            continue;
        }

        cout << "Iveskite suma: ";
        double suma = saugusDouble();

        double rezultatas = 0;

        cout << fixed << setprecision(2);

        // ===== PALYGINIMAS =====
        if (pasirinkimas == 1) {

            rezultatas = suma / kursaiBendri[isVal - 1] * kursaiBendri[iVal - 1];

            cout << "Rezultatas: " << rezultatas << endl;
        }

        // ===== PIRKIMAS =====
        else if (pasirinkimas == 2) {

            rezultatas = suma / kursaiPirkti[isVal - 1] * kursaiPirkti[iVal - 1];

            cout << "Jus gausite: " << rezultatas << endl;
        }

        // ===== PARDAVIMAS =====
        else if (pasirinkimas == 3) {

            rezultatas = suma / kursaiParduoti[isVal - 1] * kursaiParduoti[iVal - 1];

            cout << "Jus gausite: " << rezultatas << endl;
        }
    }

    return 0;
}