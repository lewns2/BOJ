#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+10;
ll n, pos[mxN], human[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> pos[i] >> human[i];
    }

    ll lo = -1e9, hi = 1e9;
    while(lo <= hi) {
        ll mid = (lo+hi) / 2;
        ll A = 0, B = 0;
        for(int i=0; i<n; i++) {
            A += abs(pos[i] - mid) * human[i];
            B += abs(pos[i] - (mid+1)) * human[i];
        }
        if(A <= B) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << lo;
}

/*
total => (x[i] - target) * a[i] 을 최소로
*/