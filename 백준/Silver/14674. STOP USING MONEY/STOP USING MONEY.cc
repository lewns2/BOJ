#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

bool cmp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {

    // 1LL*a.first.first * b.first.second;
    // 1LL*a.first.second * b.first.first;
    
    if(1LL*a.first.first * b.first.second == 1LL*a.first.second * b.first.first) {
        if(a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        }
        
        return a.second.first < b.second.first;
    }

    return 1LL*a.first.first * b.first.second > 1LL*a.first.second * b.first.first;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n, k; cin >> n >> k;

    vector<pair<pair<int, int>, pair<int, int>>> arr;

    for(int i=1; i<=n; i++) {
        int x, c, h; cin >> x >> c >> h;
        arr.push_back({{h, c}, {c, x}});
    }
    sort(arr.begin(), arr.end(), cmp);

    for(int i=0; i<k; i++) {
        cout << arr[i].second.second << "\n";
    }
}
