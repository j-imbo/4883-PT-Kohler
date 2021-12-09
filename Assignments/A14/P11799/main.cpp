/*
* James Kohler
* CMPS 4883
* 11/2/21
*/
#include <iostream>
using namespace std;

int main(){
    int t,n,x;
    cin >> t;
    for (int c=1;c<=t;c++) {
        cin >> n;
        int a(0);
        while (n--) {
            cin >> x;
            if (x>a) a=x;
        }
        cout << "Case " << c << ": " << a << '\n';
    }
    return 0;
}
