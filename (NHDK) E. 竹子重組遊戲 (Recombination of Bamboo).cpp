#include <bits/stdc++.h>

using namespace std;

const int mxN = 500005;
const double EPS = 1e-7;


#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

const int LOG = 20;
vector<int> adj[mxN];
int dp[mxN][26];
int depth[mxN];
int up[mxN][LOG];
map<int, char> mp;

void dfs(int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        //
        for (int i = 0; i <= 25; i++) {
            dp[v][i] = dp[u][i];
        }
        char curNode = mp[v];
        int curNum = mp[v] - 'a';
        dp[v][curNum] = dp[v][curNum] + 1;
        //
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for (int i = 1; i < 20; i++) {
            up[v][i] = up[ up[v][i-1] ][i-1];
        }
        //
        dfs(v, u);
    }
}

int get_lca (int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    int k = depth[a] - depth[b];
    for (int i = LOG-1; i >= 0; i--) {
        if (k & (1 << i)) {
            a = up[a][i];
        }
    }

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    if (a == 1) return 1;
    return up[a][0];
}

bool is_palin(int a, int b) {
    int check = 0;

    int lca = get_lca(a, b);
    int lcaTag = mp[lca] - 'a';

    for (int i = 0; i < 26; i++) {
        int charNum = dp[a][i] + dp[b][i];
        if (i == lcaTag) charNum--;
        if (charNum % 2 == 1) check++;
        if (check == 2) return false;
     }

    return true;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        char a; cin >> a;
        mp[i] = a;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dp[1][mp[1]-'a']++;
    dfs(1, 0);

    while (q--) {
        int a, b; cin >> a >> b;
        if (is_palin(a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}
