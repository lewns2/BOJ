#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e6+10;
int n;

bool sosu(int num) {
    if(num < 2) return false;
    for(int i=2; i*i<=num; i++) {
        if((num % i) == 0) return false;
    }
    return true;
}

bool isP(int num) {
    string x = to_string(num);
    int lo = 0, hi = x.size()-1;
    bool flag = true;
    while(lo < hi) {
        if(x[lo] != x[hi]) {
            flag = false;
            break;
        }
        lo++, hi--;
    }
    return flag;
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for(int i=n; i<=(int)1e9; i++) {
        if(isP(i) && sosu(i)) {
            cout << i;
            break;
        }
    }
}