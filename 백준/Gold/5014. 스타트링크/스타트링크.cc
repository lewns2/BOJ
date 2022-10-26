#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 1e6+10;
int f, s, g, u, d;
int ans[mxN];

int main() {
    cin >> f >> s >> g >> u >> d;

    for(int i=0; i<=f; i++) ans[i] = INF;
    // ans[s] = 0;

    queue<pair<int, int>> q;
    q.push({s, 0});

    while(q.size()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(ans[now] <= cnt) continue;
        ans[now] = min(ans[now], cnt);
        if(now == g) break;

        if(now + u <= f) q.push({now+u, cnt+1});
        if(now - d > 0) q.push({now-d, cnt+1});
    }
    if(ans[g] == INF) cout << "use the stairs";
    else cout << ans[g];


} 