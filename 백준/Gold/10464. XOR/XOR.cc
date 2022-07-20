#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 1e9;

// 1부터 x까지의 XOR 결과값
int findXOR(int x) {
    int mod = x % 4;

    if(mod == 0) return x;
    if(mod == 1) return 1;
    if(mod == 2) return x+1;
    if(mod == 3) return 0;

    return 0;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int s, f; cin >> s >> f;
        int a = findXOR(s-1);
        int b = findXOR(f);
        int ans = a^b;

        // S ~ F까지의 XOR 결과값 == (1 ~ S-1) ^ (1 ~ F)
        cout << ans << "\n";
    }
} 