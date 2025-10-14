#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 1e9;

int n;
vector<int> arr;
vector<int> tmp;
set<int> st;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
        st.insert(x);
        
    }

    for(int x : st) {
        tmp.push_back(x);
    }
    
    // sort(tmp.begin(), tmp.end());
    // tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end()); 

    for(int i=0; i<n; i++) {
        arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

} 