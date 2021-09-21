/*
 * James Kohler
 * CMPS 4883
 * 9/21/21
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

int main() {
    int n; string t;
    cin >> n;
    cin.ignore(); cin.ignore();
    cout << setprecision(4) << fixed; // decimals to ten thousandths
    while (n--) {
        map<string,int> list;
        map<string,int>::iterator it;
        int tot;

        while (getline(cin,t)) { // read in each line, counting trees
            if (t=="") break;
            list[t]++;
            tot++;
        }

        for (it = list.begin(); it != list.end(); it++) { // output tree stats
            cout << it->first << " " << ((it->second)*100)/double(tot) << '\n';
        }
        if (n) cout << '\n';
        list.clear(); tot = 0;
    }
    return 0;
}