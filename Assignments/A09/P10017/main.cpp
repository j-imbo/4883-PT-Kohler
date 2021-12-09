/*
 * James Kohler
 * CMPS 4883
 * 9/28/21
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> h[3];
int m,c;

void write() {
    cout << '\n';
    for (int i=0;i<3;i++) {
        cout << char(i+65) << "=>";
        if (!h[i].empty()) {
            cout << "  ";
            for (int j=0;j<h[i].size();j++) cout << " " << h[i][j];
        }
        cout << '\n';
    }
}

void hanoi(int n, int sc, int bf, int ds) {
    if (c==m) return; // check step counter
    if (n==1) {
        c++; // increase step counter
        //move from source to dest
        h[ds].push_back(h[sc].back());
        h[sc].pop_back();
        write();
        return;
    }
    hanoi(n-1,sc,ds,bf); //move from source to buffer
    if (c==m) return; // check step counter
    c++; // increase step counter
    //move from source to dest
    h[ds].push_back(h[sc].back());
    h[sc].pop_back();
    write();
    hanoi(n-1,bf,sc,ds); //move from buffer to source
}

int main(){
    int n,p=0;
    while (cin>>n){
        if (n==0) break;
        cin >> m; c=0;
        for (int i=n;i!=0;i--) h[0].push_back(i);

        p++;
        cout << "Problem #" << p << '\n';
        write();
        hanoi(n,0,1,2);

        for (int i=0;i<3;i++) h[i].clear();
        cout << '\n';

    }
    return 0;
}