#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

int n;
int arr[9];
int vis[9];
int narr[9];

int ans = 0;

void sol(int cur) {
    if(cur == n) {
        int tmp = 0;
        for(int i=0; i<n-1; i++) {
            tmp += abs(narr[i] - narr[i+1]);
        }
        ans = max(ans, tmp);
    }

    for(int i=0; i<n; i++) {
        if(vis[i]) continue;

        vis[i] = 1;
        narr[cur] = arr[i];
        sol(cur+1); 
        vis[i] = 0;
    }

}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    memset(vis, sizeof(vis), 0);
    memset(narr, sizeof(narr), 0);

    sol(0);

    cout << ans;

}

