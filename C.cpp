#include <bits/stdc++.h>

using namespace std;

const int mxN = 100005;
const double EPS = 1e-7;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

vector<int> adj[mxN];

void solve() {
    int n, m; cin >> n >> m;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int in[n+1] = {0};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        in[a]++; in[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (m % 2 == 0) {
        for (int i = 0; i <= n; i++)
                adj[i].clear();

        cout << "0\n";
        return;
    }

    int oddNum = 1e9, evenNum = 1e9;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) continue;

        if (in[i] % 2 == 1) {
            oddNum = min(oddNum, a[i]);
        }
        else {
            for (auto e: adj[i]) {
                if (in[e] % 2 == 0) {
                    evenNum = min(evenNum, a[e] + a[i]);
                }
            }
        }
    }

    cout << min(oddNum, evenNum) << '\n';

    for (int i = 0; i <= n; i++)
            adj[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
