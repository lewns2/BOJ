#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n; cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    int k; cin >> k;
    ll ans = 0, cur = 0;
    for(int i=0, j=0; i<n; i++) {
        while(j<n && cur + arr[j] <= k) {
            cur += arr[j];
            j++;
        }
        if(cur + arr[j] > k) {
            ans += (n - j);
        }
        cur -= arr[i];
    }
    cout << ans;

}