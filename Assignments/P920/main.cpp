/*
 * James Kohler
 * CMPS 4883
 * 9/30/21
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef double d;
typedef vector<pair<d,d>> vdd;
typedef pair<d,d> dd;
typedef vector<d> vd;

bool cmp(dd &a, dd &b){
    return a.first<b.first;
}

d distance(dd a, dd b) { // distance between two points
    return sqrt(
        (d) (a.first -b.first )*(a.first -b.first )
         +  (a.second-b.second)*(a.second-b.second)
    );
}

int main() {
    int c;
    cin >> c;
    while (c--){
        int n,m=0;
        d l=0;
        vdd p;
        cin >> n;
        while (n--){
            d x,y;
            cin >> x >> y;
            p.push_back(dd(x,y));
        }
        sort(p.begin(),p.end(),cmp);
        for (vdd::reverse_iterator it = p.rbegin();it != p.rend();it++) { // go backwards due to sun direction
            if (it->second > m) { // if point is a new peak
                l += (distance(*it, *(it-1)) * (it->second - m) / (it->second - (it-1)->second)); // projected peak
                m = it->second; // new peak
            }
        }
        cout << fixed << setprecision(2) << l << '\n';
        p.clear();
    }
    return 0;
}