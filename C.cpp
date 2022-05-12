#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
ll W[mxN];

struct Edge{
    ll u, w;
    bool operator < (const Edge &cmp) const {
        return cmp.w < w;
    }
};

ll dis[mxN];
vector<Edge> adj[mxN];

void Dijkstra() {
    memset(dis, -1, sizeof(dis));
    priority_queue<Edge> pq;
    for (int i=0; i<n; i++) {
        pq.push({i, W[i]});
    }
    while (pq.size()) {
        auto node=pq.top(); pq.pop();
        if (dis[node.u] != -1) continue;
        dis[node.u] = node.w;
        for (auto k:adj[node.u]) {
            if (dis[k.u] == -1)
                pq.push({k.u, 2 * k.w + node.w});
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b; ll w; cin >> a >> b >> w;
        a--; b--;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    for (int i=0; i<n; i++)
        cin >> W[i];

    Dijkstra();
    for (int i=0; i<n; i++)
        cout << dis[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T=1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*


*/
