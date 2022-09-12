#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 5e6+10;
int n, k;
int ar[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> ar[i];
    
    priority_queue<pair<int, int>> q;
    
    for(int i=0; i<n; i++) {
        q.push({-ar[i], i});
        while(!q.empty()) {
            if(q.top().second >= i - k + 1) {
                break;
            }
            q.pop();
        }
        cout << -q.top().first << " ";
    }
}