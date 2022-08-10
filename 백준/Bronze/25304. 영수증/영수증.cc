#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll x, n; cin >> x >> n;
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ll a, b; cin >> a >> b;
        ans += (a * b);
    }
    if(x == ans) cout << "Yes";
    else cout << "No";

} 