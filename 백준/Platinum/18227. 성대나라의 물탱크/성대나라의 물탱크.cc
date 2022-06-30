#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 2e5+20;
int n, c;
vector<int> arr[mxN];
int idxTree[mxN][2];
vector<ll> tree;
int depth[mxN], nodeNum = 0;

void dfs(int v, int d, int p = -1) {
    
    idxTree[v][0] = ++nodeNum;
    depth[v] = d;
    for(auto next : arr[v]) {
        if(next != p) {
            dfs(next, d+1, v);
        }
    }
    idxTree[v][1] = nodeNum;
}

void update(int start, int end, int node, int index, int diff) {
    if(index < start || index > end) return;

    tree[node] += diff;
    if(start == end) return;
    int mid = start + (end-start)/2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
}

ll sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> c;
    for(int i=0; i<n-1; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        arr[to].push_back(fr);
    }

    dfs(c, 1);

    // for(int i=1; i<=n; i++) {
    //     cout << i << " " << depth[i] << "\n";
    //     cout << idxTree[i][0] << " " << idxTree[i][1] << "\n\n";
    // }
    tree.resize(4*n+40);

    int q; cin >> q;
    while(q--) {
        int x, city; cin >> x >> city;
        if(x == 1) {
            int m = idxTree[city][0];
            int diff = 1;
            update(1, n, 1, m, diff);
            // for(int i=1; i<=4*n; i++) {
            //     cout << tree[i] << " ";
            // } cout << "\n";
        }
        
        if(x == 2) {
            int l = idxTree[city][0];
            int r = idxTree[city][1];
            cout << sum(1, n, 1, l, r) * depth[city] << "\n";
        }

    }
}