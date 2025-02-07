#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 1e6;
int n;
ll ar[mxN];

int bs(int x, int idx) {
    int l = 0, r = n-1, res = 0;
    
    while(l<r) {
        int mid = l + (r - l)/2;         

        if(ar[mid] * 0.9 <= x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if(l < idx) {
        res = 0;   
    } else if(ar[l] * 0.9 <= x) {
        res = l - idx;
    } else {
        res = l - idx - 1;
    }

    return res;    

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar+n);

    ll ans = 0;
    for(int i=0; i<n-1; i++) {
        ans += bs(ar[i], i);
    }
    cout << ans;

}
