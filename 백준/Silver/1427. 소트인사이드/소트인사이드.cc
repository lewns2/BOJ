#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


bool cmp(int a, int b) {
    return a > b;
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> ar;
    
    while(n) {
        int x = n % 10;
        ar.push_back(x);
        n /= 10;
    }
    sort(ar.begin(), ar.end(), cmp);
    for(auto x : ar) {
        cout << x;
    }
}
