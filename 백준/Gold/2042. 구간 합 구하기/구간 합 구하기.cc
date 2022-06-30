#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e6+1;
int n, m, k;
vector<ll> arr;
vector<ll> tree;

ll init(int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];

    int mid = start + (end-start)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

ll sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left<=start && end<=right) return tree[node];

    int mid = start + (end-start)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, ll diff) {
    if(index < start || index > end) return;

    tree[node] += diff;
    if(start == end) return;
    int mid = start + (end-start)/2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
}


int main() {
    cin >> n >> m >> k;
    arr.resize(n+1);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    tree.resize(4*n);
    init(0, n-1, 1);

    for(int i=0; i<m+k; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        if(a==1) {
            ll diff = c - arr[b-1];
            arr[b-1] = c;
            update(0, n-1, 1, b-1, diff);
        }
        if(a==2) {
            cout << sum(0, n-1, 1, b-1, c-1) << "\n";
        }
    }
}