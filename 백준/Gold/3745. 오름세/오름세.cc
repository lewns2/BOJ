#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

int n;
vector<int> ar;
vector<int> ans;

int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while(cin >> n) {
        
        ar.clear();
        ans.clear();

        for(int i=0; i<n; i++) {
            int a; cin >> a;
            ar.push_back(a);
        }

        int last = 0;
        ans.push_back(ar[0]);

        for(int i=1; i<n; i++) {
            if(ans[last] < ar[i]) {
                ans.push_back(ar[i]);
                last++;
            }
            else {
                int pos = lower_bound(ans.begin(), ans.end(), ar[i]) - ans.begin();
                ans[pos] = ar[i];
            }
        }
        cout << last+1 << "\n";
    }
}