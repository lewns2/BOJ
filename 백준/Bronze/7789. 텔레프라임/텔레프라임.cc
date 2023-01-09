#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9



ll n, m;


bool sosu(ll num) {
    if(num < 2) return false;
    for(int i=2; i*i<=num; i++) {
        if((num % i) == 0) return false; 
    }
    return true;
}

int main() {
    cin >> n >> m;
    bool ok1 = false, ok2 = false;

    string tmp = "";
    tmp += to_string(m);
    tmp += to_string(n);

    ll a = stoll(tmp);

    ok1 = sosu(n);
    ok2 = sosu(a);

    if(ok1 & ok2) cout << "Yes";
    else cout << "No";
} 

