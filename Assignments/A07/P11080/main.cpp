/*
* James Kohler
* CMPS 4883
* 9/14/21
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define INF 2147483647

int main(){
    int n;
    cin >> n;
    while (n--) {
        int v, e, a, b;
        cin >> v >> e;
        vector<vi> adj(v);
        vi c(v, INF);
        vector<bool> vis(v, false);
        // read in
        while (e--) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // bipartite check
        bool bi = true;
        int tot=0;
        for (int i=0; i<v;i++) {
            if (!vis[i]) { // no need to revisit already-seen places, catches disconnected-ness
                int ct[2] = {0};
                queue<int> q;
                q.push(i); vis[i] = true; c[i] = 0; // start off queue with first unvisited piece
                ct[c[i]]++;
                while (!q.empty() && bi) {
                    int u = q.front(); q.pop();
                    vis[u] = true;
                    for (int j=0;j<adj[u].size();j++) {
                        int tmp = adj[u][j];
                        if (c[tmp] == INF) { // unmarked
                            c[tmp] = 1 - c[u];
                            ct[c[tmp]]++;
                            q.push(tmp);
                        }
                        else if (c[tmp] == c[u]) { // same-color neighbors
                            bi = false;
                            break;
                        }
                    }
                }
                tot += max(1, min(ct[0],ct[1]));
            }
        }
        // output
        if (bi) cout << tot << '\n';
        else cout << "-1\n";
    }
    return 0;
}
