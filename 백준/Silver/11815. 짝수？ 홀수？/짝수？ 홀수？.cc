#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        ll x; cin >> x;
        ll lo = 0, hi = 1e9;
        while(lo+1 < hi) {
            ll mid = (lo + hi) / 2;
            if(mid * mid > x) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        if(lo * lo == x || hi * hi == x) {
            cout << 1 << " ";
        }
        else cout << 0 << " ";
    }
} 