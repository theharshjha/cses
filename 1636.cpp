// author: imtheonly1
// time: 2023-11-17 18:57:10
// URL: https://cses.fi/problemset/task/1636
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
    int dp[m + 1] = {1};
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i] <= j) {
                dp[j] = (dp[j] + dp[j - c[i]]) % ((int)1e9 + 7);
            }
        }
    }
    cout << dp[m];
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