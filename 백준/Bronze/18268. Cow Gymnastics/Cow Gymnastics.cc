#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 21;
int k, n;
int cnt[mxN][mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k >> n;
    int K = k;
    while(k--) {
        vector<int> ar(n);
        for(int i=0; i<n; i++) {
            cin >> ar[i];            
        }
        for(int i=0; i<n; i++) {
            int A = ar[i];
            for(int j=i+1; j<n; j++) {
                int B = ar[j];
                cnt[A][B] += 1;
                cnt[B][A] -= 1;
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(cnt[i][j] == K) ans++;
        }
    }
    cout << ans;
}
