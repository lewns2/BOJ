#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10;
int n, m;
vector<string> code;
vector<int> ar[mxN];
int dp[mxN], back[mxN];

int solve(int cur, int end) {

    if(cur == end) return dp[cur];

    if(dp[cur] != -1) return dp[cur];
    dp[cur] = INF;

    for(auto next : ar[cur]) {
        int ret = solve(next, end);
        if(dp[cur] > ret + 1) {
            dp[cur] = ret + 1;
            back[cur] = next;
        }
    }

    return dp[cur];
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        code.push_back(s);
    }
    for(int i=0; i<n-1; i++) {
        string A = code[i];
        for(int j=i+1; j<n; j++) {
            string B = code[j];
            int cnt = 0;
            for(int k=0; k<m; k++) {
                if(A[k] != B[k]) cnt++;
            }
            if(cnt == 1) {
                ar[i+1].push_back(j+1);
                ar[j+1].push_back(i+1);
            }
        }
    }
    int s, e; cin >> s >> e;
    memset(dp, -1, sizeof(dp));
    dp[e] = 0;
    int ret = solve(s, e);
    if(ret == INF) {
        cout << -1;
    }
    else {
        for(int i=s; i != 0; i = back[i]) {
            cout << i << " "; 
        }
    }
}
