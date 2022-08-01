#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+5;
int n;
int ar[mxN];
vector<ll> sum_tree;
vector<ll> min_tree;
ll ans = 0;

int cmp(int a, int b) {
    if(a == INF) return b;
    if(b == INF) return a;
    if(ar[a] < ar[b]) return a;
    return b;
}

ll sum_init(int start, int end, int node) {
    if(start == end) return sum_tree[node] = ar[start];

    int mid = (start + end) / 2;
    ll a = sum_init(start, mid, node*2);
    ll b = sum_init(mid+1, end, node*2+1);
    return sum_tree[node] = a + b;
} 

ll min_init(int start, int end, int node) {
    if(start == end) return min_tree[node] = start;

    int mid = (start + end) / 2;
    ll a = min_init(start, mid, node*2);
    ll b = min_init(mid+1, end, node*2+1);
    return min_tree[node] = cmp(a, b);
}

ll sum_solve(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return sum_tree[node];

    int mid = (start + end) / 2;
    return sum_solve(start, mid, node*2, left, right) + sum_solve(mid+1, end, node*2+1, left, right);
}

ll min_solve(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return INF;
    if(left <= start && end <= right) return min_tree[node];

    int mid = (start + end) / 2;
    return cmp(min_solve(start, mid, node*2, left, right), min_solve(mid+1, end, node*2+1, left, right));
}

void query(int left, int right) {
    if(left > right) return;
    ll idx = min_solve(0, n-1, 1, left, right);
    ll tot = sum_solve(0, n-1, 1, left, right);

    ans = max(ans,tot*ar[idx]);

    query(left, idx-1);
    query(idx+1, right);
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> ar[i];
    } 
    sum_tree.resize(4*n+40);
    min_tree.resize(4*n+40);
    sum_init(0, n-1, 1);
    min_init(0, n-1, 1);
    
    query(0, n-1);

    cout << ans;
} 