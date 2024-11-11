// author: imtheonly1
// time: 2024-10-22 21:38:22
//
// Problem: Money Sums
// URL: https://cses.fi/problemset/task/1745
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            dp[j] |= dp[j - a[i]];
        }
    }
    vector<int> ans;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            ans.push_back(i);
        }
    }
    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << " \n"[i == sz(ans) - 1];
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
