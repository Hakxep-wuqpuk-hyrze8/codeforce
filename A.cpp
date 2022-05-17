#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void answer(int n) {
    cout << n << '\n';
}

void solve() {
    string s; cin >> s;

    int n=(int)s.size();
    int dp[n+5]={0};
    if (s[0]=='0')dp[0]=1;
    for (int i=1; i<n; i++) {
        if (s[i]=='0')
            dp[i]++;
        dp[i]+=dp[i-1];
    }
    vector<int> one;
    for (int i=0; i<n; i++)
        if (s[i]=='1')
            one.pb(i);

    int bl=-1, br=one.size(), sz=one.size();
    while (br-bl>1) {
        int mid=(bl+br)/2;
        bool ok=0;
        for (int i=0; i<=mid; i++) {
            int L=one[i]; int R=one[sz-mid+i-1];
            if (dp[R]-dp[L] <= mid)
                ok=1;
        }
        if (ok)
            br=mid;
        else
            bl=mid;
    }

    answer(br);
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
