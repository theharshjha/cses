// author: imtheonly1
// time: 2024-02-29 22:20:41
//
// Problem: Edit Distance
// URL: https://cses.fi/problemset/task/1639
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

int dp[5001][5001] = {};
int hmm(string &a, string &b, int i, int j) {
    if (i == sz(a)) {
        return abs(sz(b) - j);
    }
    if (j == sz(b)) {
        return abs(sz(a) - i);
    }
    if (dp[i][j]) {
        return dp[i][j];
    }
    if (a[i] != b[j]) {
        int mn = INT_MAX;
        mn = min(mn, 1 + hmm(a, b, i, j + 1));
        mn = min(mn, 1 + hmm(a, b, i + 1, j));
        mn = min(mn, 1 + hmm(a, b, i + 1, j + 1));
        dp[i][j] = mn;
    } else {
        dp[i][j] = hmm(a, b, i + 1, j + 1);
    }
    return dp[i][j];
}
void solve() {
    string a, b;
    cin >> a >> b;
    cout << hmm(a, b, 0, 0);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
