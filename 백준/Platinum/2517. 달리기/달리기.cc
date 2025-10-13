#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

int mxN = 5e5, mxM = 1e9+1;

int n;
vector<ll> arr;
vector<ll> tarr;
vector<ll> tree;
vector<ll> cnt;

void comp() {
    tarr = arr;
    sort(tarr.begin(), tarr.end());

    for(int i=0; i<n; i++) {
        arr[i] = lower_bound(tarr.begin(), tarr.end(), arr[i]) - tarr.begin();
    }
}

ll init(int start, int end, int node) {
    if(start == end) return tree[node] = cnt[start];

    ll mid = start + (end - start) / 2;
    
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

ll solve(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];

    ll mid = start + (end - start)/2;

    return solve(start, mid, node*2, left, right) + solve(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, ll diff) {
    if(index < start || index > end) return;
    
    tree[node] = tree[node] + diff;

    ll mid = start + (end - start)/2;

    if(start != end) {
        update(start, mid, node*2, index, diff);
        update(mid+1, end, node*2+1, index, diff);
    }

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    // 1. 좌표압축
    comp();

    // 2. 나보다 작은 배열
    tree.resize(4*n);
    cnt.resize(n);

    init(0, n-1, 1);

    for(int i=0; i<n; i++) {     
        // cnt[arr[i]]++;  // [시간초과] 4. tree update => index : arr[i], diff : 1
        update(0, n-1, 1, arr[i], 1);

        cout << i + 1 - solve(0, n-1, 1, 0, arr[i]-1) << "\n"; // 3. 구간 : 0 ~ 현재 찍은 곳
        
        // tree.clear(); // [시간초괴]
    }


} 