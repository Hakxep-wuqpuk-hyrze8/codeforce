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

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<int> sz(k);
    for (int i = 0; i < k; i++) {
        cin >> sz[i];
    }

    ll kn = 0, km = 0, ln = 0, lm = 0;
    bool three = 0;

    for (int i = 0; i < k; i++) {
        if (sz[i] >= 2 * n) {
            ll mxSz = sz[i] / n;

            if (mxSz >= 3) {
                three = 1;
            }

            km += mxSz;
            lm++;
        }
    }

    ll total = m;
    if (2 * lm <= total && km >= total) {
        cout << "YES\n";
        return;
    }
    if (2 * lm > total) {
        if (three || m % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }

    three = 0;

    for (int i = 0; i < k; i++) {
        if (sz[i] >= 2 * m) {
            int mxSz = sz[i] / m;

            if (mxSz >= 3) {
                three = 1;
            }

            kn += mxSz;
            ln++;
        }
    }

    total = n;
    if (2 * ln <= total && kn >= total) {
        cout << "YES\n";
        return;
    }
    if (2 * ln > total) {
        if (three || n % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
