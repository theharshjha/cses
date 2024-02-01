// author: imtheonly1
// time: 2024-02-01 12:14:29
//
// Problem: Dice Combinations
// URL: https://cses.fi/problemset/task/1633
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
#define mod 1000000007

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    cout << dp[n];
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