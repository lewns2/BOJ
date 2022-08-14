#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 10000009;
int n, m;
int a[mxN], b[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=m; i++) cin >> b[i];
        
        int ans = 0;
        for(int i=1; i<=n; i++) {
            int x = a[i];
            int lo = 1, hi = m;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(b[mid] > x) {
                    hi = mid -1;
                }
                else {
                    lo = mid + 1;
                }
            }
            if(x == b[hi]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
