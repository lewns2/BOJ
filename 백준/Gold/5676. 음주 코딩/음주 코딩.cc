#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9


const int mxN = 1e5;
int t;
int n, q;
vector<ll> arr;
vector<ll> tree;


ll solve(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 1;
    if(left <= start && end <= right) return tree[node];

    int mid = start + (end - start) / 2;
    return solve(start, mid, node*2, left, right) * solve(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, int diff) {
    if(index < start || index > end) return ;

    tree[node] = diff;
    if(start != end) {
       int mid = start + (end - start) / 2;
       update(start, mid, node*2, index, diff);
       update(mid+1, end, node*2+1, index, diff); 

       tree[node] = (tree[node*2] * tree[node*2+1]);
    }    

}



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(cin >> n >> q) {

        arr.clear(); tree.clear();
        arr.resize(n); tree.resize(n*4);

        for(int i=0; i<n; i++) {
            int x; cin >> x;
            arr.push_back(x);
            if(x == 0) x = 0;
            if(x < 0) x = -1;
            if(x > 0) x = 1;
            update(0, n-1, 1, i, x);
        }

        while(q--) {
            char x; int a, b; 
            cin >> x >> a >> b;

            if(x == 'C') {
                if(b > 0) b = 1;
                else if(b < 0) b = -1;
                else if(b == 0) b = 0;

                update(0, n-1, 1, a-1, b);
            }
            else if(x == 'P') {
                ll res = solve(0, n-1, 1, a-1, b-1);
                char ans;
                if(res == 0) ans = '0';
                if(res > 0) ans = '+';
                if(res < 0) ans = '-'; 
                cout << ans;
            }

        }
        cout << "\n";
    }
    
} 

