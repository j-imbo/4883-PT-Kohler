/*
 * James Kohler
 * CMPS 4883
 * 9/30/21
 */
#include<iostream>
using namespace std;
typedef long long ll;

class fb{ // generate fibonaccis 
public:
    ll f[51];
    fb() {
        f[0] = f[1] = 1;
        for (int i=2;i<51;i++) {
            f[i] = f[i-1] + f[i-2];
        }
    }
    ll nacc(int n){
        return f[n];
    }

};

int main(){
  int i;
  fb fibo;
  while (cin>>i){
    if (i==0) break;
    cout << fibo.nacc(i) << '\n'; // fun with variable/function names
  }
  return 0;
}