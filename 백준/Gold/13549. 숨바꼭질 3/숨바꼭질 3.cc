#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+1;
int n, k;
int vis[mxN*2];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    for(int i=0; i<mxN; i++) {
        vis[i] = INF;
    }

    queue<pair<int, int>> q;
    q.push({0, n});
    vis[n] = 0;

    while(q.size()) {
        int t = q.front().first;
        int now = q.front().second;
        q.pop();

        if(now == k) break;

        if(now+1 < mxN && vis[now+1] > vis[now]+1) {
            vis[now+1] = vis[now] + 1;
            q.push({vis[now+1], now+1});
        }
        if(now - 1 >=0 && vis[now-1] > vis[now]+1) {
            vis[now-1] = vis[now] + 1;
            q.push({vis[now-1], now-1});
        }
        if(now*2 < mxN && vis[now*2] > vis[now]) {
            vis[now*2] = vis[now];
            q.push({vis[now*2], now*2});
        }
    }

    cout << vis[k];
} 