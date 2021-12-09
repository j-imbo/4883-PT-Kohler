/*
 * James Kohler
 * CMPS 4883
 * 9/21/21
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Team {
    string n;
    int p, g, w, l, t, gs, ga;
    Team(string s) {
        n = s;
        p = g = w = l = t = gs = ga = 0;
    }
    Team() {
        p = g = w = l = t = gs = ga = 0;
    }
};

bool teamcomp(pair<string,Team> aa, pair<string,Team> bb) {
    Team a = aa.second, b = bb.second;
    if (a.p != b.p) return a.p > b.p; // points
    if (a.w != b.w) return a.w > b.w; // wins
    if (a.gs-a.ga != b.gs-b.ga) // goal difference
        return a.gs-a.ga > b.gs-b.ga;
    if (a.gs != b.gs) return a.gs > b.gs; // goals scored
    if (a.g < b.g) return a.g < b.g; // games played
    string ta = a.n, tb = b.n; // make names lowercase
    transform(ta.begin(), ta.end(), ta.begin(), ::tolower);
    transform(tb.begin(), tb.end(), tb.begin(), ::tolower);
    return (ta < tb); // lexicographical order
}

int main() {
    int n,t,g,sc;
    string s,tmp;
    cin >> n;
    getchar(); // newline char begone
    while (n--) {
        map<string,Team> teams;
        getline(cin,s); // league name
        cin >> t;
        getchar(); // newline char begone
        for (int i=0; i<t; i++) { // team list
            getline(cin,tmp); // newline char begone
            Team tm = Team(tmp);
            teams.insert(make_pair(tmp,tm));
        }
        cin >> g;
        getchar(); // newline char begone
        while (g--) { // games played
            int g1, g2;
            string t1, t2, gc1, gc2;
            char ta[31],tb[31];
            getline(cin,tmp);
            int l = tmp.size();
            int i=0, j=0;

            while(tmp[i]!='#') { ta[j++] = tmp[i++]; } // team 1 name
            ta[j] = '\0'; j=0; i++; t1 = ta;
            while (tmp[i]!='@') { gc1[j++] = tmp[i++]; } // team 1 goals
            gc1[j] = '\0'; j=0; i++; g1 = atoi(gc1.c_str()); 
            while (tmp[i]!='#') { gc2[j++] = tmp[i++]; } // team 2 goals
            gc2[j] = '\0'; j=0; i++; g2 = atoi(gc2.c_str());
            while (tmp[i]!='\0') { tb[j++] = tmp[i++]; } // team 2 name
            tb[j] = '\0'; t2 = tb;

            // each team played a game
            teams[t1].g++;
            teams[t2].g++;
            // team 1 goals, scores t1, against t2
            teams[t1].gs += g1;
            teams[t2].ga += g1;
            // team 2 goals, against t1, scores t2
            teams[t1].ga += g2;
            teams[t2].gs += g2;

            if (g1 > g2) { //t1 win
                teams[t1].w++;
                teams[t1].p += 3;
                teams[t2].l++;
            }
            else if (g1 < g2) { //t2 win
                teams[t1].l++;
                teams[t2].w++;
                teams[t2].p += 3;
            }
            else { // tie
                teams[t1].t++;
                teams[t1].p++;
                teams[t2].t++;
                teams[t2].p++;
            }
        }
        // sort teams based on criteria
        vector<pair<string,Team>> teamlist;
        copy(teams.begin(),teams.end(),back_inserter(teamlist));
        sort(teamlist.begin(),teamlist.end(),teamcomp);

        // output
        cout << s << '\n'; // league name
        for (int i=0; i < teamlist.size(); i++) { // teams by ranking
            cout << i+1 << ") " << teamlist[i].first << ' ' << teamlist[i].second.p << "p, " << teamlist[i].second.g << "g (" <<
                teamlist[i].second.w << '-' << teamlist[i].second.t << '-' << teamlist[i].second.l << "), " << teamlist[i].second.gs-teamlist[i].second.ga <<
                "gd (" << teamlist[i].second.gs << '-' << teamlist[i].second.ga << ")\n";
        }
        if (n) cout << '\n';
        teams.clear(); teamlist.clear();
    }
    return 0;
}