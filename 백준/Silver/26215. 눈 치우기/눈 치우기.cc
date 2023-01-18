#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 102;
int n;
vector<int> ar;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n;

    bool ok = true;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        ar.push_back(x);
        if(x >= 1441) ok = false;
    }

    if(!ok) cout << -1;
    else if(ar.size() == 1) {
        cout << ar[0];
    }
    else {
        int ans = 0;
        while(1) {
            sort(ar.begin(), ar.end(), cmp);
            if(ar[0] == 0) break;

            ar[0]--;
            if(ar[1] >= 1) {
                ar[1]--;
            }

            ans++;
            
        }
        if(ans > 1440) cout << -1;
        else cout << ans;
    }
} 
