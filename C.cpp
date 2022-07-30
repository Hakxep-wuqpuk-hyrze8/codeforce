#include <bits/stdc++.h>

using namespace std;

const int mxN = 200005;
const double EPS = 1e-7;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

ll a[mxN], treenode[mxN * 4];

void build (int l, int r, int v) {
    if (l == r) {
        treenode[v] = a[l];
        return;
    }

    int mid = (l+r) / 2;
    build(l, mid, v*2);
    build(mid+1, r, v*2+1);
    treenode[v] = max(treenode[v*2], treenode[v*2+1]);
}

ll query (int ql, int qr, int l, int r, int v) {
    if (ql == l && qr == r) {
        return treenode[v];
    }

    int mid = (l+r) / 2;
    if (qr <= mid) {
        return query(ql, qr, l, mid, v*2);
    } else if (ql > mid) {
        return query(ql, qr, mid+1, r, v*2+1);
    } else {
        return max(query(ql, mid, l, mid, v*2), query(mid+1, qr, mid+1, r, v*2+1));
    }
}

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    build(1, m, 1);

    int q; cin >> q;

    while (q--) {
        int sx, sy, fx, fy, k;
        cin >> sx >> sy >> fx >> fy >> k;

        if (sy > fy) {
            swap(sy, fy);
        }

        if (abs(sx - fx) % k != 0 || abs(sy - fy) % k != 0) {
            cout << "NO\n";
            continue;
        }

        ll mxBlock = query(sy, fy, 1, m, 1);

        ll to = (n - sx) / k;
        sx += k * to;

        if (sx > mxBlock) {
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
