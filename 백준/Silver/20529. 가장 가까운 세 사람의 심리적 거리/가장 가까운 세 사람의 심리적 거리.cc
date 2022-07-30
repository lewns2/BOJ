#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const string MBTI[17] = {"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ"};

int solve(string a, string b, string c) {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        if(a[i] != b[i]) cnt++;
        if(b[i] != c[i]) cnt++;
        if(a[i] != c[i]) cnt++;
    }
    return cnt;
}
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> ar;
        for(int i=0; i<n; i++) {
            string s; cin >> s;
            ar.push_back(s);
        }
        if(n > 32) {
            cout << 0 << "\n";
        }
        else {
            int ans = 1e9;
            for(int i=0; i<n-2; i++) {
                for(int j=i+1; j<n-1; j++) {
                    for(int k=j+1; k<n; k++) {
                        int tmp = solve(ar[i], ar[j], ar[k]);
                        ans = min(ans, tmp);
                    }
                }
            }
            cout << ans << "\n";
        }
        
    }
} 