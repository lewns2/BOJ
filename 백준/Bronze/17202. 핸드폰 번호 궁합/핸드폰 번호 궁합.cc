#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

vector<int> arr;
string ans = "";
void solve(vector<int> a) {

    vector<int> narr;
    for(int i=0; i<a.size()-1; i++) {
        int x = (a[i] + a[i+1])%10;
        narr.push_back(x);
    }

    if(narr.size() == 2) {
        cout << narr[0] << narr[1] << "\n";
    }

    else {
        solve(narr);
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b; cin >> a >> b;
    
    for(int i=0; i<a.size(); i++) {
        arr.push_back(a[i] - '0');
        arr.push_back(b[i] - '0');
    }
    solve(arr);
    cout << ans;
} 

