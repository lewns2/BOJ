#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 44;
ll n, s, ans=0;
vector<int> a, b;

void solve() {
    
    vector<ll> suba, subb;

    for(int i=1; i<(1<<a.size()); i++) {
        ll tmp = 0;
        for(int j=0; j<a.size(); j++) {
            if(i & (1 << j)) {
                tmp += a[j];
            }
        }
        if(tmp == s) ans++;
        suba.push_back(tmp);
    }

    for(int i=1; i<(1<<b.size()); i++) {
        ll tmp = 0;
        for(int j=0; j<b.size(); j++) {
            if(i & (1 << j)) {
                tmp += b[j];
            }
        }
        if(tmp == s) ans++;
        subb.push_back(tmp);
    }

    sort(suba.begin(), suba.end());
    sort(subb.begin(), subb.end());

    for(int i=0; i<suba.size(); i++) {
        ll target = s - suba[i];
        auto mi = lower_bound(subb.begin(), subb.end(), target);
        auto mx = upper_bound(subb.begin(), subb.end(), target);
        ans += (mx - mi);
    }

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> s;
    for(int i=0; i<n/2; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    for(int i=n/2; i<n; i++) {
        int x; cin >> x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());

    solve();

    cout << ans;

}