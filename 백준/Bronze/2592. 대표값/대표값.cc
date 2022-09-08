#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 10;
    map<int, int> mp;
    int tot = 0, mx = -1, cur = 0;
    while(t--) {
        int x; cin >> x;
        tot += x;
        mp[x]++;
        if(mp[x] > mx) {
            mx = mp[x];
            cur = x;
        }
    }
    cout << tot / 10 << "\n" << cur << "\n";

}