#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9



int main () {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c; cin >> a >> b >> c;
    int d, e, f; cin >> d >> e >> f;

    cout << abs(c-d) << " " << max(b, e) / min(b, e) << " " << abs(a-f);

}