/*
https://codeforces.com/problemset/problem/1676/H2
*/
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int bit[mxN], b[mxN];
vi v;
int get_id (int x) {
    return lower_bound(v.begin(), v.end(), x)-v.begin()+1;
}
void update(int x) {
    while (x<mxN) {
        bit[x]++;
        x += x & -x;
    }
}
ll query(int x) {
    ll res=0;
    while (x) {
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

void solve () {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());

    ll ans=0;
    for (int i=0; i<n; i++) {
        if (b[a[i]]) {
            ans+=b[a[i]];
        }
        b[a[i]]++;
        ans += i-query(get_id(a[i]));
        update(get_id(a[i]));
    }
    cout << ans << '\n';
    memset(bit, 0, sizeof(bit));
    memset(b, 0, sizeof(b));
    v.clear();
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
