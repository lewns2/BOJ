#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

string s; 
int n;
int vis[1001];
vector<pair<int, int>> ar;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1) {
        cin >> n;
        if(n == 0) break;
        cin >> s;
        
        memset(vis, 0, sizeof(vis));
        ar.clear();

        string tmp = "", tmp1 = "";
        int S = 0, E = 0;
        int flag = -1;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '-' || s[i] == ',') continue;

            if(s[i+1] == '-') {
                tmp += s[i];
                S = stoi(tmp);
                flag = 1;
            }
            else if(i == s.size()-1 || s[i+1] == ',') {
                if(S == 0) {
                    tmp += s[i];
                    E = stoi(tmp);
                }
                else {
                    tmp1 += s[i];
                    E = stoi(tmp1);
                }
                flag = -1;
                if(S == 0) S = E;
                ar.push_back({S, E});
                S = 0, E = 0;
                tmp = ""; tmp1 = "";
            }
            else if(flag == -1) {
                tmp += s[i];
            }
            else if(flag == 1) {
                tmp1 += s[i];
            }
        }

        for(auto x : ar) {
            int sp = x.first;
            int ep = x.second;
            if(sp > ep) continue;
            if(sp > n) continue;
            for(int i=sp; i<=min(ep, n); i++) {
                vis[i] = 1;
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(vis[i]) ans++;
        }
        cout << ans << "\n";
    }
}
