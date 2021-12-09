/*
* James Kohler
* CMPS 4883
* 11/2/21
*/
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int main(){
    int t,n,m,x;
    cin >> t;
    for (int c=1;c<=t;c++) {
        cin >> n; m=n;
        vi w;
        while (n--) {
            cin >> x;
            w.push_back(x);
        }
        int h(0),l(0);
        for (int i=1;i<m;i++) {
            if (w[i-1]<w[i]) h++;
            else if (w[i-1]>w[i]) l++;
        }
        cout << "Case " << c << ": " << h << ' ' << l << '\n';
    }
    return 0;
}
