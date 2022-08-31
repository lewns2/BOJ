#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 110;
int n, k;
vector<int> ar[mxN];
int vis[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    while(k--) {
        int a, b; cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    bool flag = true;
    for(int i=1; i<=n; i++) {
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({0, i});
        while(q.size()) {
            int cnt = q.front().first;
            int now = q.front().second;
            q.pop();

            if(cnt > 6) continue;
            vis[now] = 1;

            for(auto next : ar[now]) {
                if(!vis[next]) {
                    q.push({cnt+1, next});
                }
            }
        }
        bool ok = true;
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "Small World!";
    else cout << "Big World!";
}