#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 2e5, mxM = 2e5;
int n, m;
int ar[mxN];

int bs(int x) {
    int l = 0, r = n - 1;

    int idx = 1e9;

    while(l<r) {
        int mid = l + (r - l)/2;
        
        if(x <= ar[mid]) {
            r = mid;
        } else {
            l = mid+1;
        }
    }

    if(idx == 1e9 && ar[l] != x) {
        idx = -1;
    } else {
        idx = min(idx, l);
    }

    return idx;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    memset(ar, 0, sizeof(ar));
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        ar[i] = x;
    }
    
    sort(ar, ar+n);
    
    for(int i=0; i<m; i++) {
        int x; cin >> x;   
        cout << bs(x) << "\n";
    }

}
