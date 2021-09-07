/*
* James Kohler
* CMPS 4883
* 9/2/21
*/
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int main(){
    int n,m,r,tmp;
    vi l;
    bool fail,succ;
    cin >> n;
    m = n;
    while(n != 0) {
        do {
            l.push_back(n);
            m = min(m, n); // m is minimum cycle
            cin>>n;
        } while(n!=0);
        int t=m*2; // start at second cycle of shortest light
        succ = false; fail = false;
        while (t <= 18000) { // 5h max
            for (int i=0;i<(m-5);i++) { // green period of shortest light
                if (t+i > 18000) {
                    t += i;
                    break;
                }
                fail = false;
                for (int j=0;j<l.size();j++) { // go thru each light
                    if (((t+i) / l[j]) % 2) { // red period
                        fail = true;
                        break;
                    }
                    else if (((t+i) % l[j]) >= (l[j]-5)) { // yellow period
                        fail = true;
                        break;
                    }
                }
                if (!fail) { // winner winner winner winner
                    t += i;
                    succ = true;
                    break;
                }
            }
            if (succ) break;
            else t += 2*m; // next period
        }

        if (t>18000) cout << "Signals fail to synchronise in 5 hours\n";
        else {
            cout << "0" << (t / 3600) << ":";
            if (((t % 3600)/60)<10) cout << "0";
            cout << ((t % 3600)/60) << ":";
            if ((t % 60)<10) cout << "0";
            cout << (t % 60) << "\n";
        }

        l.clear();
        cin>>n;
        m = n;
    }
    return 0;
}