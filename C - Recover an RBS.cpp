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

string s;

bool check () {
    int len = s.length();
    int open = 0, close = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') open++;
        if (s[i] == ')') close++;
        if (close > open) return false;
    }

    return true;
}

void solve() {
    cin >> s;
    int len = s.length();
    int open = 0, close = 0, q = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') open++;
        else if (s[i] == ')') close++;
        else q++;
    }
    if (q <= 1) {
        cout << "YES\n";
        return;
    }

    int qopen;
    if (open >= close) {
        qopen = (len - open - close - (open - close)) / 2;
    }
    else {
        qopen = close - open;
        qopen += (len - open - close - (qopen)) / 2;
    }

    int Ropen = -1, Lclose = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '?') {
            if (qopen == 1) {
                Ropen = i;
            }
            if (qopen == 0) {
                Lclose = i;
            }

            if (qopen > 0) {
                qopen--;
                s[i] = '(';
            }
            else {
                qopen--;
                s[i] = ')';
            }
        }
    }

    if (Ropen == -1 || Lclose == -1) {
        cout << "YES\n";
        return;
    }

    s[Ropen] = ')'; s[Lclose] = '(';

    if (!check()) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
