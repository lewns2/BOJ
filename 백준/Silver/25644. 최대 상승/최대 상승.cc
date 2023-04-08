#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 2e5+20;
int ar[mxN], mn[mxN];


int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        ar[i] = a;
    }

    mn[0] = ar[0];

    for(int i=1; i<n; i++) {
        mn[i] = min(mn[i-1], ar[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, ar[i] - mn[i]);
    }

    cout << ans;

}
