#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

vector<int> adj[mxN], v;

void dfs (int node, int p) {
    v.pb(node);
    for (auto e : adj[node]) {
        dfs (e, node);
    }

    if (!v.size()) return;
    cout << v.size() << '\n';
    for (auto d : v) cout << d << ' ';
    cout << '\n';
    v.clear();
}

void solve() {
    int n, ans=0, root; cin >> n;
    map<int, int> mp;
    for (int i=1; i<=n; i++) {
        int m; cin >> m;
        if (!mp[m]) mp[m]++;
        else ans++;
        if (m == i) {
            root = m;
            continue;
        }
        adj[m].pb(i);
    }
    if (!ans) ans++;
    cout << ans << '\n';

    dfs(root, -1);

    for (int i=0; i<mxN; i++)
        adj[i].clear();
    v.clear();
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

     int T;
     cin >> T;
     while (T--) {
        solve();
     }

    return 0;
}

/*
*/
