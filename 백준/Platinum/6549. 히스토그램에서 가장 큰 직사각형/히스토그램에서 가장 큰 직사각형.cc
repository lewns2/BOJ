#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+10;
int n;
ll ar[mxN];
ll tree[4*mxN];
ll ans;

int cmp(ll a, ll b) {
    if(a == -1) return b;
    if(b == -1) return a;
    if(ar[a] < ar[b]) return a;
    return b;
}

ll init(ll start, ll end, ll node) {
    if(start == end) return tree[node] = start;

    int mid = (start + end) / 2;
    ll a = init(start, mid, node*2);
    ll b = init(mid+1, end, node*2+1);
    return tree[node] = cmp(a, b);
}

ll query(ll start, ll end, ll node, ll left, ll right) {
    if(right < start || end < left) return -1;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    
    ll a = query(start, mid, node*2, left, right);
    ll b = query(mid+1, end, node*2+1, left, right);
    return cmp(a, b);
}

void solve(ll left, ll right) {
    if(left > right) return;
    ll idx = query(0, n-1, 1, left, right);
    ll w = right - left + 1;

    ans = max(ans, ar[idx] * w);

    solve(left, idx-1);
    solve(idx+1, right);
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1) {
        cin >> n;
        if(n == 0) break;

        memset(ar, 0, sizeof(ar));
        memset(tree, 0, sizeof(tree));
        
        ans = 0;
        for(int i=0; i<n; i++) {
            ll x; cin >> x;
            ar[i] = x;
        }
        init(0, n-1, 1);
        solve(0, n-1);
        cout << ans << "\n";
    }
} 
