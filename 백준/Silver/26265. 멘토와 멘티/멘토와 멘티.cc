#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

int n;
vector<pair<string, string>> ar;

bool cmp(pair<string, string> a, pair<string, string> b) {
    if(a.first == b.first) {
        return a > b;
    }
    return a < b;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        string a, b; cin >> a >> b;
        ar.push_back({a, b});
    }

    sort(ar.begin(), ar.end(), cmp);
    for(auto x : ar) {
        cout << x.first << " " << x.second << "\n";
    }
} 