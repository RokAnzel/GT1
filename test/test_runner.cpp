#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

bool primerjajDatoteki(const string& file1, const string& file2) {
    ifstream f1(file1), f2(file2);
    string line1, line2;

    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) return false;
    }

    return f1.eof() && f2.eof();
}

int main() {
    int result = system("./sort 0 test/test1.txt");

    if (result != 0) {
        cerr << "NAPAKA: Program se ni uspešno izvedel.\n";
        return 1;
    }

    if (primerjajDatoteki("out.txt", "test/expected1.txt")) {
        cout << "✅ Test je uspel.\n";
        return 0;
    }
    else {
        cerr << "❌ Test NI uspel – izhod ni pravilen.\n";
        return 1;
    }
}
