/*
* James Kohler
* CMPS 4883
* 11/2/21
*/
#include <iostream>
using namespace std;

int main(){
    int t,x,y,z,a;
    cin >> t;
    for (int c=1;c<=t;c++) {
        cin >> x >> y >> z;
        if (x>y) {
            if (y>z) a=y;
            else if (x>z) a=z;
            else a=x;
        }
        else {
            if (x>z) a=x;
            else if (y>z) a=z;
            else a=y;
        }
        
        cout << "Case " << c << ": " << a << '\n';
    }
    return 0;
}
