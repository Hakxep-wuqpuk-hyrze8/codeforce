#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

ll bit[mxN][2];
int mx[mxN], my[mxN];

void update(int x, int val, int t) {
    while (x<mxN) {
        bit[x][t]+=val;
        x += x & -x;
    }
}

ll query(int x, int t) {
    ll res=0;
    while (x) {
        res += bit[x][t];
        x -= x & -x;
    }
    return res;
}

void solve () {
    int n, q;
    cin >> n >> q;

    int t, x, y, xx, yy;
    while (q--) {
        cin >> t;
        if (t==1) {
            cin >> x >> y;
            if (!mx[x])
                update(x, 1, 0);
            if (!my[y])
                update(y, 1, 1);
            mx[x]++; my[y]++;
        }
        if (t==2) {
            cin >> x >> y;
            if (mx[x]==1)
                update(x, -1, 0);
            if (my[y]==1)
                update(y, -1, 1);
            mx[x]--; my[y]--;
        }
        if (t==3) {
            cin >> x >> y >> xx >> yy;
            puts((query(xx, 0)-query(x-1, 0) == xx-x+1)||(query(yy, 1)-query(y-1, 1) == yy-y+1)? "YES" : "NO" );
        }
    }
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
