#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 1e5+20, mxM = 1e5+20;
int n, m;
vector<int> arr;
vector<ll> tree;

ll solve(int x, int y) {
    if(x == -1) return y;
    if(y == -1) return x;
    if(arr[x] == arr[y]) return x < y ? x : y;
    else return arr[x] < arr[y] ? x : y;
}

ll init(int start, int end, int node) {
    if(start == end) return tree[node] = start;

    int mid = (start + end)/2;
    return tree[node] = solve(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

ll update(int start, int end, int node, int index) {
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node];

    int mid = (start + end)/2;
    return tree[node] = solve(update(start, mid, node*2, index), update(mid+1, end, node*2+1, index));
}

ll query(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return -1;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end)/2;
    return solve(query(start, mid, node*2, left, right), query(mid+1, end, node*2+1, left, right));
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    tree.resize(4*n + 40);
    init(0, n-1, 1);

    cin >> m;
    while(m--) {
        int q; cin >> q;
        if(q == 1) {
            int idx, v; cin >> idx >> v;
            arr[idx-1] = v;
            update(0, n-1, 1, idx-1);
        }   
        if(q == 2) {
            int l, r; cin >> l >> r;
            cout << query(0, n-1, 1, l-1, r-1) + 1 << "\n";
        }
    }
}