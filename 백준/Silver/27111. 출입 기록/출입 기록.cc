#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9


const int mxN = 2e5+20;
int n;
int ar[mxN];
set<int> st;

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    memset(ar, 0, sizeof(ar));
    
    int ans = 0;
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        st.insert(a);

        if((ar[a]^1) != b) {
            ans++;
        }
        ar[a] = b;
    }
    
    for(auto x : st) {
        if(ar[x] == 1) {
            ans++;
        }
    }
    
    cout << ans;
}