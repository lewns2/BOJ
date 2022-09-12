#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN=1e5;
int n, m;
vector<ll> arr;
vector<ll> mntree;
vector<ll> mxtree;

ll mninit(int start, int end, int node) {
    if(start == end) return mntree[node] = arr[start];

    int mid = start + (end-start)/2;
    return mntree[node] = min(mninit(start, mid, node*2), mninit(mid+1, end, node*2+1));
}

ll mxinit(int start, int end, int node) {
    if(start == end) return mxtree[node] = arr[start];

    int mid = start + (end-start)/2;
    return mxtree[node] = max(mxinit(start, mid, node*2), mxinit(mid+1, end, node*2+1));
}

ll mnsolve(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return INF;
    if(left <= start && end <= right) return mntree[node];

    int mid = start + (end-start)/2;
    return min(mnsolve(start, mid, node*2, left, right), mnsolve(mid+1, end, node*2+1, left, right));
}

ll mxsolve(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return mxtree[node];

    int mid = start + (end-start)/2;
    return max(mxsolve(start, mid, node*2, left, right), mxsolve(mid+1, end, node*2+1, left, right));
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    arr.resize(n); mntree.resize(n*4); mxtree.resize(n*4);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    mninit(0, n-1, 1); mxinit(0, n-1, 1);

    for(int i=0; i<m; i++) {
        ll a, b; cin >> a >> b;
        cout << mnsolve(0, n-1, 1, min(a-1, b-1), max(a-1, b-1)) << " ";
        cout << mxsolve(0, n-1, 1, min(a-1, b-1), max(a-1, b-1)) << "\n";
    }

}