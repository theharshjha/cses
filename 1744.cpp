// author: imtheonly1
// time: 2024-02-29 22:44:26
//
// Problem: Rectangle Cutting
// URL: https://cses.fi/problemset/task/1744
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
int dp[501][501] = {};
int hmm(int a, int b) {
    if (a == b) {
        return 0;
    }
    if (dp[a][b]) {
        return dp[a][b];
    }
    int mn = INT_MAX;
    for (int i = 1; (i << 1) <= a; i++) {
        mn = min(mn, 1 + hmm(i, b) + hmm(a - i, b));
    }
    for (int j = 1; (j << 1) <= b; j++) {
        mn = min(mn, 1 + hmm(a, j) + hmm(a, b - j));
    }
    dp[a][b] = mn;
    return dp[a][b];
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << hmm(a, b);
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
