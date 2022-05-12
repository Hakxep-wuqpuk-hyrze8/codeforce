/*
https://codeforces.com/problemset/problem/1676/G
*/
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 4e3+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int black[mxN], sz[mxN], ans;
vector<int> adj[mxN];

void dfs(int node,int parent) {

    for (auto e : adj[node]) {
        if (e != parent)
            dfs(e, node);
    }

    if (black[node]) {
        sz[parent] += sz[node]+1;
    } else {
        sz[parent] += sz[node]-1;
    }
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i=2; i<=n; i++) {
        cin >> a[i];
        adj[i].pb(a[i]);
        adj[a[i]].pb(i);
    }
    string s;
    cin >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='B')
            black[i+1]=1;
    }
    dfs(1, 0);
    for (int i=1; i<=n; i++) {
        if (black[i]) {
            ans += (sz[i]==-1);
        } else {
            ans += (sz[i]==1);
        }
    }
    cout << ans << '\n';
    ans=0;
    memset(black, 0, sizeof(black));
    memset(sz, 0, sizeof(sz));
    for (int i=0; i<mxN; i++)
        adj[i].clear();
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
