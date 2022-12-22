#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9

const int mxN = 2e3+10;
int n, m, t, s, g, h;
vector<pair<int, int>> ar[mxN];
int dist[mxN];

int solve(int s, int e) {

    vector<int> chk;

    priority_queue<pair<int, int>> pq;
    for(int i=0; i<=n; i++) dist[i] = INF;
    dist[s] = 0;
    pq.push({dist[s], s});

    
    while(pq.size()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < cost) continue;

        chk.push_back(now);

        for(int i=0; i<ar[now].size(); i++) {
            int next = ar[now][i].first;
            int nextcost = ar[now][i].second;
            if(dist[next] > dist[now] + nextcost) {
                dist[next] = dist[now] + nextcost;
                pq.push({-dist[next], next});
            }
        }
    }

    return dist[e];
}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        // init
        for(int i=0; i<=n; i++) {
            dist[i] = INF;
            ar[i].clear();
        }

        for(int i=0; i<m; i++) {
            int a, b, d; cin >> a >> b >> d;
            ar[a].push_back({b, d});
            ar[b].push_back({a, d});
        }

        // s -> g -> h -> goal
        // s -> h -> g -> goal
        int course1[4] = {s, g, h};
        int course2[4] = {s, h, g};

        set<int> st;
        while(t--) {
            ll res1=0, res2=0, res3=0;
            int goal; cin >> goal;
            // s -> goal;
            res1 = solve(s, goal);
            course1[3] = goal;
            course2[3] = goal;
            for(int i=0; i<3; i++) {
                res2 += solve(course1[i], course1[i+1]);
                res3 += solve(course2[i], course2[i+1]);
            }
            if(res1 == res2 || res1 == res3) st.insert(goal);
        }
        for(auto x : st) cout << x << " ";
        cout << "\n";
    }

} 