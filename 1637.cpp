// author: imtheonly1
// time: 2023-11-17 19:01:59
// URL: https://cses.fi/problemset/task/1637
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1e8;
        for (int j = i; j; j /= 10) {
            dp[i] = min(dp[i], 1 + dp[i - (j % 10)]);
        }
    }
    cout << dp[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}