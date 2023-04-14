#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 21;
vector<int> ar;

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int tot = 0;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        tot += x;
        ar.push_back(x);
    }

    vector<int> res;

    for(int i=0; i<(1<<n); i++) {
        int tmp = 0;
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) {
                tmp += ar[j];
            }
        }
        res.push_back(tmp);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    int ans = 0;
    
    for(int i=0; i<res.size()-1; i++) {
        int nxt = res[i+1];
        int now = res[i];
        if(nxt - now != 1) {
            ans += (nxt-now-1);
        }
    }
    cout << ans;


}

/*

*/
