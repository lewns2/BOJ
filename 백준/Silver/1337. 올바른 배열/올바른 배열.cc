#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 55;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> arr;
    
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int ans = 4;
    for(int i=0; i<n; i++) {
        int cnt = 4;
        int j = i+1;
        while(j<n) {
            if(arr[j] - arr[i] < 5) cnt--;
            else break;
            j++;
        }
        ans = min(ans, cnt);
    }
    cout << ans;

}