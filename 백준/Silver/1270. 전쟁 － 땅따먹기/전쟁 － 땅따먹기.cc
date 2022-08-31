#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        map<ll, ll> mp;
        ll cur = -1, num = -1;
        for(int i=0; i<n; i++) {
            ll a; cin >> a;
            mp[a]++;
            if(mp[a] > cur) {
                cur = mp[a];
                num = a;
            }
        }
        if(cur > n/2) cout << num << "\n";
        else cout << "SYJKGW" << "\n";
    }
}