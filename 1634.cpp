// author: imtheonly1
// time: 2023-11-17 18:40:30
// URL: https://cses.fi/problemset/task/1634
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    ll dp[m + 1] = {};
    for (int i = 1; i <= m; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (c[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - c[j]]);
            }
        }
    }
    cout << (dp[m] == INT_MAX ? -1 : dp[m]);
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