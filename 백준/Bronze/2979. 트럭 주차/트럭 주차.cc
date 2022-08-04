#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c; cin >> a >> b >> c;
    int cost[4];
    memset(cost, 0, 4);
    cost[1] = a; cost[2] = b*2; cost[3] = c*3;
    
    map<int, int> mpin;
    map<int, int> mpout;

    int start = 1e9, end = 0;
    for(int i=0; i<3; i++) {
        int x, y; cin >> x >> y;
        mpin[x]++;
        mpout[y]++;        

        start = min(start, x);
        end = max(end, y);
    }

    int cnt = 0, ans = 0;
    for(int i=start; i<end; i++) {
        if(mpin[i] && mpout[i] == 0) {
            cnt += mpin[i];
        }
        else if(mpout[i] && mpin[i] == 0) {
            cnt -= mpout[i];
        }
        ans += cost[cnt];
    }
    cout << ans;
    
} 
/*
5 3 1
1 3
3 5
2 8
*/