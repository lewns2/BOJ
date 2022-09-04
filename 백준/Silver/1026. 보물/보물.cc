#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 51;
int n;
int a[mxN], b[mxN];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    
    sort(a, a+n);
    sort(b, b+n, cmp);

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += (a[i] * b[i]);
    }
    cout << ans;
}