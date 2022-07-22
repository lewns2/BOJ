#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+10;
int n, m;
vector<ll> arr;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    while(m--) {
        sort(arr.begin(), arr.end());
        ll x = arr[0] + arr[1];
        arr[0] = x;
        arr[1] = x;
    }
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ans += arr[i];
    }
    cout << ans;

} 