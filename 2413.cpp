// Author: imtheonly1
// Time: 2024-01-22 00:13:09
//
// Problem: Counting Towers
// URL: https://cses.fi/problemset/task/2413
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
#define MOD ((int)1e9 + 7)
void solve() {
    int tc;
    cin >> tc;
    int n = 1000000;
    vector dp(n + 1, vector<ll>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (((dp[i - 1][0] << 2) + dp[i - 1][1])) % MOD;
        dp[i][1] = ((dp[i - 1][1] << 1) + dp[i - 1][0]) % MOD;
    }
    while (tc--) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
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