#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 1e5;

int n, q;
vector<int> arr;
vector<int> tree[500010];

void update(int start, int end, int node, int index, int diff) {
    if(index < start || index > end) return;

    tree[node].push_back(diff);

    if(start != end) {
        int mid = start + (end - start) / 2;
        update(start, mid, node*2, index, diff);
        update(mid+1,end, node*2+1, index, diff);
    }
}

int solve(int start, int end, int node, int left, int right, int x) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), x);

    int mid = start + (end - start)/2;
    return solve(start, mid, node*2, left, right, x) + solve(mid+1, end, node*2+1, left, right, x);

}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
        update(0, n-1, 1, i, x);
    } 

    for(int i=0; i<500010; i++) {
        sort(tree[i].begin(), tree[i].end());   
    }
    
    cin >> q;
    while(q--) {
        int l, r, k; 
        cin >> l >> r >> k;
        cout << solve(0, n-1, 1, l-1, r-1, k) << "\n";
    }

} 

