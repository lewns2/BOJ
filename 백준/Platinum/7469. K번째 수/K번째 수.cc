#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 1e5;
int n, q;
vector<ll> arr;
vector<ll> tree[500100];
vector<ll> ans;

void update(int start, int end, int node, int index, int diff) {
    if(index < start || index > end) return;

    tree[node].push_back(diff);

    if(start != end) {
        int mid = start + (end - start) / 2;
        update(start, mid, node*2, index, diff);
        update(mid+1,end, node*2+1, index, diff);
    }
}

ll solve(int start, int end, int node, int left, int right, int k) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();   

    int mid = start + (end - start) / 2;
    return solve(start, mid, node*2, left, right, k) + solve(mid+1, end, node*2+1, left, right, k);
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> q;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
        update(0, n-1, 1, i, x);
    }

    for(int i=0; i<500100; i++) {
        sort(tree[i].begin(), tree[i].end());
    }

    while(q--) {
        int a, b, c; cin >> a >> b >> c;
        // cout << "k 보다 큰 숫자의 개수 " << solve(0, n-1, 1, a-1, b-1, c) << "\n";

        int lo = -1e9, hi = 1e9;

        while(lo<=hi) {
            int mid = lo + (hi - lo) / 2;

            if(solve(0, n-1, 1, a-1, b-1, mid) < c) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << "\n";
        
    }

} 
