/*
 * James Kohler
 * CMPS 4883
 * 10/19/21
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define IMAX 2147483647
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int,vii> mvii;

vi dijkstra(mvii m, int s,int n) { // dijkstra implementation adapted from algotree.org
    // initialize distance to max values
    vi d(n+1, IMAX);
    set<ii> q;
    // distance from start to itself is 0
    d[s] = 0;
    q.insert(make_pair(0,s));
    while (!q.empty()) {
        ii top = *q.begin();
        q.erase(q.begin());
        int  adj = top.first, len = top.second;
        vii e = m[len];
        for (const ii& to : e) {
            if (adj + to.second < d[to.first]) {
                q.erase(make_pair(d[to.first],to.first));
                d[to.first] = adj + to.second;
                q.insert(make_pair(d[to.first],to.first));
            }
        }
    }
    return d;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        mvii maze;
        int n,e,t,m,x=0;
        cin >> n >> e >> t >> m;
        while (m--) {
            int a,b,c;
            cin >> a >> b >> c;
            maze[b].push_back(make_pair(a,c));
        }
        vi d = dijkstra(maze,e,n);
        for (auto it : d) {
            if (it <= t) x++;
        }
        cout << x << "\n";
        if (c) cout << '\n';
    }
    return 0;
}