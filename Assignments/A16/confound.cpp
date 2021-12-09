#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

string inname = "sort100k1.dat";
string outname = "conf50-100k1.dat";
int conf = 50; // percentage of data swapped

int main() {
    conf = 100/conf;
    ifstream fin; int n, *data;
    fin.open(inname);
    fin >> n;
    data = new int[n];
    for (int i = 0; i < n; i++) fin >> data[i];

    srand(time(0));
    for (int i = 0; i < n/conf; i++) {
        int rando1 = rand() % n, rando2 = rand() % n, tmp;
        tmp = data[rando1]; data[rando1] = data[rando2]; data[rando2] = tmp;
    }

    ofstream fout;
    fout.open(outname);
    fout << n << " ";
    for (int i = 0; i < n; i++) {
        fout << data[i] << " ";
    }
    fout.close();

    return 0;

}