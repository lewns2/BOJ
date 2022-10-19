#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

int n, k;
int ar[101], dp[10001];
int main() {
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }
    for(int i=0; i<=k; i++) dp[i] = 1e9;
    for(int i=0; i<n; i++) {
        if(ar[i] > 10000) continue;
        dp[ar[i]] = 1;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=1; j<=k; j++) {
            if(j - ar[i] >= 0) {
                dp[j] = min(dp[j], dp[j-ar[i]] + 1);
            }
        }
    }
    if(dp[k] == 1e9) cout << -1;
    else cout << dp[k];
} 