#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 2e18
#define INF 1e9

int n, k;
vector<int> arr;

bool check(ll x) {
    ll cost = 0;
    for(int i=0; i<n; i++) {
        cost += (x/arr[i]);
        if(cost >= k) return true;
    }

    return false;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    arr.resize(n);
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    ll left = 0, right = 1e18+1;
    while(left+1 < right) {
        ll mid = left + (right - left) /2;

        if(!check(mid)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    cout << right;
    
}
