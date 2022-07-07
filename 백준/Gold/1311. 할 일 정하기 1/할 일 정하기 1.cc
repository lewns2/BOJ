#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 25;
int n;
int arr[mxN][mxN];
int dp[1<<21];


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<(1<<n); i++) {
        dp[i] = INF;
    }
    
    dp[0] = 0;
    for(int i=0; i<(1<<n); i++) {
        
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) cnt++;
        }
        
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) continue;
            dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i]+arr[cnt][j]);
        }
    }

    cout << dp[(1<<n)-1];
}