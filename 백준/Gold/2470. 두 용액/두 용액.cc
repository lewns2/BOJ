#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+10;
int n;
vector<int> arr;

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    ll ref = 2000000020;
    int l = 0, r = n-1;
    int ansl = l, ansr = r;
    while(l < r) {
        ll tmp = arr[l] + arr[r];

        if(ref > abs(tmp)) {
            ref = abs(tmp);
            ansl = l;
            ansr = r;
        }

        if(tmp > 0) {
            r--;
        }
        else if(tmp < 0) {
            l++;
        }
        else {
            ansl = l;
            ansr = r;
            break;
        }
    }
    cout << arr[ansl] << " " << arr[ansr];
} 