#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 10;
int n, m, ar[mxN];
int vis[mxN], A[mxN];
set<int> st;

bool sosu(int num) {
    if(num < 2) return false;
    for(int i=2; i*i<=num; i++) {
        if((num % i) == 0) {
            return false;
        }
    }
    return true;
}

void recur(int cur, int idx) {
    if(cur == m) {
        int tot = 0;
        for(int i=0; i<m; i++) {
            tot += A[i];
        }
        if(sosu(tot)) {
            st.insert(tot);
        }
        return;
    }

    for(int i=idx; i<n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        A[cur] = ar[i];
        recur(cur+1, i);
        vis[i] = 0;
    }

}



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> ar[i];
    }

    recur(0, 0);
    if(st.size() == 0) cout << -1;
    else {
        for(auto x : st) {
            cout << x << " ";
        }
    }

}