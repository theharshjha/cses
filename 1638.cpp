// author: imtheonly1
// time: 2023-11-17 19:09:54
// URL: https://cses.fi/problemset/task/1638
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int dp[n + 1][n + 1] = {};
    dp[1][1] = (s[0][0] == '.');
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1][j - 1] == '.') {
                dp[i][j] =
                    (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % ((int)1e9 + 7);
            }
        }
    }
    cout << dp[n][n];
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