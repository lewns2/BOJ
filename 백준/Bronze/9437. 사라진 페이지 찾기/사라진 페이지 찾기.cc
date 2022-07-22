#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e3+20;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1) {
        int n, p; cin >> n;
        if(n == 0) break;
        cin >> p;
        
        vector<int> ans;
        int tot = n+1;
        ans.push_back(tot - p);
        
        int mi = min(p, tot-p);
        int mx = max(p, tot-p);

        if(mi % 2 != 0) {
            ans.push_back(mi+1);
        }
        else {
            ans.push_back(mi-1);
        }
        if(mx % 2 != 0) {
            ans.push_back(mx+1);
        }
        else {
            ans.push_back(mx-1);
        }
        sort(ans.begin(), ans.end());
        for(auto x : ans) {
            cout << x << " ";
        } cout << "\n";
    }
} 
