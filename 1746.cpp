// Author: imtheonly1
// Time: 2024-01-21 19:08:07
//
// Problem: Array Description
// URL: https://cses.fi/problemset/task/1746
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define MOD ((int)(1e9) + 7)
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(m + 2);
    if (a[0]) {
        dp[a[0]] = 1;
    } else {
        for (int i = 1; i <= m; i++) {
            dp[i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i]) {
            int temp = (0ll + dp[a[i]] + dp[a[i] - 1] + dp[a[i] + 1]) % MOD;
            for (int j = 1; j <= m; j++) {
                dp[j] = 0;
            }
            dp[a[i]] = temp;
        } else {
            int prev = 0, temp;
            for (int j = 1; j <= m; j++) {
                temp = dp[j];
                dp[j] = (0ll + dp[j] + prev + dp[j + 1]) % MOD;
                prev = temp;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans;
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