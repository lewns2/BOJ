#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n, k; cin >> n >> k;
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++) {
        int m, v; cin >> m >> v;
        arr.push_back({-v, m});
    }
    sort(arr.begin(), arr.end());

    ll ans = 0;
    multiset<int> ms;
    while(k--) {
        int c; cin >> c;
        ms.insert(c);
    }
    
    for(int i=0; i<n; i++) {
        int value = -arr[i].first;
        int weight = arr[i].second;

        auto it = ms.lower_bound(weight);

        if(it != ms.end()) {
            ans += value;
            ms.erase(it);
        }
    }
    cout << ans;
}