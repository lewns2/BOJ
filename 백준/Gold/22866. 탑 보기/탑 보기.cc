#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+10;
int n;
int ar[mxN];
int ans[mxN], dist[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for(int i=1; i<=n; i++) cin >> ar[i];

    memset(ans, 0, sizeof(ans));
    memset(dist, 0, sizeof(dist));

    stack<pair<int, int>> st;
    for(int i=1; i<=n; i++) {
        int x = ar[i];
        while(!st.empty()) {
            if(st.top().first > x) {
                if(dist[i] == 0) dist[i] = st.top().second;
                else {
                    int prev = abs(dist[i] - i);
                    int now = abs(i - st.top().second);
                    if(prev > now) {
                        dist[i] = st.top().second;
                    }
                    else if(prev == now) {
                        dist[i] = min(dist[i], st.top().second);
                    }
                }
                break;
            }
            st.pop();
        }
        ans[i] += st.size();
        st.push({x, i});
    }

    while(!st.empty()) st.pop();
    for(int i=n; i>0; i--) {
        int x = ar[i];
        while(!st.empty()) {
            if(st.top().first > x) {
                if(dist[i] == 0) dist[i] = st.top().second;
                else {
                    int prev = abs(dist[i] - i);
                    int now = abs(i - st.top().second);
                    if(prev > now) {
                        dist[i] = st.top().second;
                    }
                    else if(prev == now) {
                        dist[i] = min(dist[i], st.top().second);
                    }
                }
                break;
            }
            st.pop();
        }
        ans[i] += st.size();
        st.push({x, i});
    }

    for(int i=1; i<=n; i++) {
        if(ans[i] == 0) {
            cout << ans[i] << "\n";
        }
        else {
            cout << ans[i] << " " << dist[i] << "\n";
        }
    }
}