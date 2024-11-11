// author: imtheonly1
// time: 2024-10-22 23:08:39
//
// Problem: Removal Game
// URL: https://cses.fi/problemset/task/1097
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
using namespace std;
int hmm(vector<int> &a, int i, int j, int flag) {
    if (i > j) {
        return 0;
    }
    if (flag) {
        return max(a[i] + hmm(a, i + 1, j, !flag),
                   a[j] + hmm(a, i, j - 1, !flag));
    } else {
        return max(hmm(a, i + 1, j, !flag), hmm(a, i, j - 1, !flag));
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << hmm(a, 0, n - 1, 0);
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
