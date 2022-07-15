#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 1e4+20;
int n, m, p[mxN]; 

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;

    for(int i=2; i<=n; i++) {
        p[i] = i;
    }

    for(int i=2; i<=n; i++) {
        for(int j=i*i; j<=n; j+=i) {
            if(p[j] == 0) continue;
            p[j] = 0;
        }
    }

    bool flag = 0; ll ans = 0;
    ll mi = 0;
    for(int i=m; i<=n; i++) {
        if(!flag && p[i] != 0) {
            mi = p[i];
            flag = 1;
        }
        ans += p[i];
    }
    if(ans == 0) cout << -1;
    else {
        cout << ans << "\n";
        cout << mi << "\n";
    }
} 

