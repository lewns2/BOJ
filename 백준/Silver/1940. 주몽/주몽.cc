#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 15010;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int l = 0, r = n-1;
    int ans = 0;
    while(l<r) {
        if(arr[l] + arr[r] > m) r--;
        else if(arr[l] + arr[r] < m) l++;
        else {
            ans++;
            l++;
            r--;
        }
    }
    
    cout << ans;
}