/*
* James Kohler
* CMPS 4883
* 8/31/21
*/
#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    
    while (cin >> a >> b) {
        c = b - a;              // get difference
        if (c < 0) c = -1*c;    // if negative, no it's not
        cout << c << '\n';      // print difference in numbers
    }
    return 0;
}