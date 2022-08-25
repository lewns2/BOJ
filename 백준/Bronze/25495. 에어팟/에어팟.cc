#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    ll ar[n];
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }
    ll cur = ar[0], cost=2, curcost=2;
    for(int i=1; i<n; i++) {
        if(ar[i] != cur) {
            cur = ar[i];
            cost += 2;
            curcost = 2;
        }
        else {
            curcost *= 2;
            cost += curcost;
        }
        if(cost >= 100) {
            cost = 0;
            cur = -1;
            curcost = 0;
        }
    }
    cout << cost << "\n";
}