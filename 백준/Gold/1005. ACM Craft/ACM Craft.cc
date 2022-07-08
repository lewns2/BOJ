#include<bits/stdc++.h>
using namespace std;

const int mxN=1e4+1;
int n, k, build[mxN], degree[mxN], target;
vector<int> arr[mxN];
int result[mxN];


void solve() {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(degree[i]==0) {
            q.push(i);
            result[i] = build[i];
        }
    }

    for(int j=0; j<=n; j++) {
        if(q.empty()) return;

        int x = q.front();
        q.pop();

        // cout << x << " ";

        for(int i=0; i<arr[x].size(); i++) {
            int next = arr[x][i];
            result[next] = max(result[next], result[x]+build[next]);
            if(--degree[next]==0) {
                q.push(next);
            }
        }
    }
}

void init() {
    for(int i=0; i<=n; i++) {
        arr[i].clear();
    }
    memset(build, 0, sizeof(build));
    memset(degree, 0, sizeof(degree));
    memset(result, 0, sizeof(result));
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> build[i];
        }
        for(int i=0; i<k; i++) {
            int fr, to;
            cin >> fr >> to;
            arr[fr].push_back(to);
            degree[to]++;
        }
        cin >> target;
        solve();
        cout << result[target] << "\n";
        init();
    }
    
}