#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 5e5+10;
string s;
int n;
vector<int> ar[mxN];
int vis[mxN];
char ans[mxN];
int mxdepth = 0;
string res = "";

void dfs(int v, int d) {
    vis[v] = 1;
    mxdepth = max(mxdepth, d);
    for(auto next : ar[v]) {
        if(!vis[next] && ans[d+1] == s[next]) {
            dfs(next, d+1);
        }
    }
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));

    queue<pair<int, int>> q;
    ans[0] = s[0];
    vis[0] = 1;
    q.push({0, 1});
    int pos = -1, pos1 = -1;

    while(q.size()) {
        int now = q.front().first;
        int idx = q.front().second;
        q.pop();

        char c = 'a';
        for(auto x : ar[now]) {
            if(s[x] > c && !vis[x]) c = s[x];
        }

        for(auto x : ar[now]) {
            if(vis[x]) continue;
            if(s[x] == c) {
                vis[x] = 1;
                if(ans[idx] < c) {
                    ans[idx] = c;
                }
                q.push({x, idx+1});
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    dfs(0, 0);
    for(int i=0; i<=mxdepth; i++) {
        cout << ans[i];
    }
}
