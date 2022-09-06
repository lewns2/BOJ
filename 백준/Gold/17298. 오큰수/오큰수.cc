#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e6+10;
int n;
int ar[mxN], ans[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) cin >> ar[i];

    memset(ans, -1, sizeof(ans));

    stack<int> st;
    for(int i=n-1; i>-1; i--) {
        int x = ar[i];
        while(!st.empty()) {
            if(st.top() > x) {
                ans[i] = st.top();
                break;
            }
            st.pop();
        }
        st.push(x);
    }
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
}