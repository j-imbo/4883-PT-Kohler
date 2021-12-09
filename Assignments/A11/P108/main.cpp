/*
 * James Kohler
 * CMPS 4883
 * 10/7/21
 */
#include <iostream>
#include <vector>
#define INT_MIN (-2147483647 - 1)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n;
    while (cin>>n) {
        int x=INT_MIN,z;
        vvi a; a.resize(n+1);
        for (int i=0;i<=n;i++) {a[i].resize(n+1);}
        a[0][0] = 0;
        for (int i=1;i<=n;i++) {a[i][0] = 0; a[0][i] = 0;}
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++) {
                cin >> z;
                a[i][j] = z;
            }
        }
        // memo table with sums
        vvi m = a;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++) {
                m[i][j] += m[i-1][j];
                m[i][j] += m[i][j-1];
                m[i][j] -= m[i-1][j-1];
            }
        }
        for (int i=1;i<=n;i++) { // calc submatrices
            for (int j=1;j<=n;j++) {
                for (int k=i;k<=n;k++) {
                    for (int l=j;l<=n;l++) {
                        int s = m[k][l];
                        s -= m[i-1][l];
                        s -= m[k][j-1];
                        s += m[i-1][j-1];
                        if (s > x) x = s; // copy if bigger
                    }
                }
            }
        }
        cout << x << '\n';
    }
    return 0;
}
