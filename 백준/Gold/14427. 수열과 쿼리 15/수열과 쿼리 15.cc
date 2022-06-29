#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+50;
int n, m;
vector<int> arr;
vector<int> tree;

int solve(int x, int y) {
    if(arr[x] == arr[y]) return x > y ? y : x;
    else return arr[x] > arr[y] ? y : x;
}

int init(int start, int end, int node) {
    if(start == end) return tree[node] = start;
    int mid = (start + end) /2;
    
    int a = init(start, mid, node*2);
    int b = init(mid+1, end, node*2+1);

    return tree[node] = solve(a, b);
}

int update(int start, int end, int node, int index) {
    if(index < start || end < index) return tree[node];
    if(start == end) return tree[node];

    int mid = (start + end) / 2;
    int a = update(start, mid, node*2, index);
    int b = update(mid+1, end, node*2+1, index);

    return tree[node] = solve(a, b);
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n;
    arr.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    tree.resize(4*n + 40);
    init(1, n, 1);

    cin >> m;
    while(m--) {
        int x; cin >> x;
        if(x == 1) {
            int idx, v; cin >> idx >> v;
            arr[idx] = v;
            update(1, n, 1, idx);
        }
        if(x == 2) {
            cout << tree[1] << "\n";
        }
    }

}
