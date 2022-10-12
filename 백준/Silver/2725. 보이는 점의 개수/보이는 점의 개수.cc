#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 1001;
int dp[mxN];

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    dp[1] = 3;
    
    for(int i=2; i<1001; i++) {
        int cnt = 0;
        for(int j=1; j<i; j++) {
            if(gcd(i, j) == 1) cnt++;
        }
        dp[i] = dp[i-1] + (2 * cnt);
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
}