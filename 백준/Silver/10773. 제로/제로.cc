#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k; cin >> k;
    stack<int> st;
    while(k--) {
        int x; cin >> x;
        if(x == 0 && st.size() != 0) st.pop();
        else st.push(x); 
    }
    ll ans = 0;
    while(st.size()) {
        int x = st.top();
        st.pop();
        ans += x;
    }
    cout << ans;
}