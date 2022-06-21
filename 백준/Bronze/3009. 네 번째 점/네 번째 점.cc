#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n = 3;

    map<int, int> mpx, mpy;
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        if(mpx.find(a) != mpx.end()) {
            mpx.erase(a);
        } else {
            mpx[a]++;
        }
        if(mpy.find(b) != mpy.end()) {
            mpy.erase(b);
        } else {
            mpy[b]++;
        }
    }
    for(auto x : mpx) {
        cout << x.first << " ";
    }
    for(auto x: mpy) {
        cout << x.first;
    }
}
