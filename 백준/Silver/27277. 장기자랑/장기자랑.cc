#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9


const int mxN = 1e5+10;
int n;
vector<int> ar;
int nar[mxN];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        ar.push_back(x);
    }
    sort(ar.begin(), ar.end(), cmp);

    int pos = 0;
    for(int i=0; i<n; i+=2) {
        nar[i] = ar[pos];
        pos++;
    }

    pos = n-1;
    for(int i=1; i<n; i+=2) {
        nar[i] = ar[pos];
        pos--;
    }

    ll ans = nar[0];
    for(int i=1; i<n; i++) {
        ans += max(0, nar[i] - nar[i-1]);
    }
    cout << ans;
} 
