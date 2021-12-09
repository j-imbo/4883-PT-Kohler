/*
* James Kohler
* CMPS 4883
* 9/9/21
*/
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int main(){
    int n,tmp;
    vi jj, df;
    while (cin>>n) {
        for (int i=0;i<n;i++) {
            cin >> tmp;
            jj.push_back(tmp);
        }
        if (n==1) { // 1-long always jolly
                cout << "Jolly\n";
        }
        else {
            df.resize(n,0);
            for (int i=1;i<n;i++) {
                tmp = abs(jj[i]-jj[i-1]);
                if (df[tmp]) { // if item already exists, very unjolly
                    cout << "Not jolly\n";
                    break;
                }
                df[tmp] = 1; // item exists
                if (i==(n-1)) { // runs at end of list
                    for (int j=1;j<n;j++) {
                        if (!df[j]) { // if any 0s exist
                            cout << "Not jolly\n";
                            break;
                        }
                        else if (j==(n-1)) cout << "Jolly\n";
                    }
                }
            }   
        }
        jj.clear(); df.clear();
    }
    return 0;
}