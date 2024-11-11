// author: imtheonly1
// time: 2024-04-18 22:16:02
//
// Problem: Labyrinth
// URL: https://cses.fi/problemset/task/1193
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
string s = "";
string ans = "";
int N = 1e9;
int n, m;
vector<string> a;
vector<vector<int>> v;
void hmm(int i, int j) {

    if (i < 0 || i == n) {
        return;
    }
    if (j < 0 || j == m) {
        return;
    }
    if (a[i][j] == '#') {
        return;
    }
    if (a[i][j] == 'B') {
        if (sz(s) < N) {
            ans = s;
            N = sz(s);
        }
        return;
    }
    if (v[i][j]) {
        return;
    }
    v[i][j] = 1;
    s.push_back('D');
    hmm(i + 1, j);
    s.pop_back();

    s.push_back('U');
    hmm(i - 1, j);
    s.pop_back();

    s.push_back('L');
    hmm(i, j - 1);
    s.pop_back();

    s.push_back('R');
    hmm(i, j + 1);
    s.pop_back();
    v[i][j] = 0;
}
void solve() {
    cin >> n >> m;
    a.resize(n);
    v.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                hmm(i, j);
                break;
            }
        }
    }
    if (sz(ans)) {
        cout << "YES" << '\n' << sz(ans) << '\n' << ans;
    } else {
        cout << "NO";
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
