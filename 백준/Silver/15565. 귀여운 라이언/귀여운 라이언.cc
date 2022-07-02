#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> arr; 
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        if(a == 2) a = 0;
        arr.push_back(a);
    }
    

    int ans = 1e9, cur = 0;
    for(int i=0, j=0; i<n; i++) {
        while(j<n && cur + arr[j] < k) {
            cur += arr[j];
            j++;
        } 
        if(cur + arr[j] >= k) {
            ans = min(ans, j - i + 1);
        }
        cur -= arr[i];
        
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
}
