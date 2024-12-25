#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            p.push_back(i);
        }
    }
    if (p.back() != n - 1) {
        int ned = n - 1 - p.back();
        if (k > ned) {
            swap(s[p.back()], s[n - 1]);
            k -= ned;
        }
    }
    if (p.front() != 0) {
        int ned = p.front(); // p.front() - 0
        if (k > ned) {
            swap(s[0], s[p.front()]);
            k -= ned;
        }
    }
    int ans = (s[0] - '0') * 10 + (s[n - 1] - '0');
    for (int i = 1; i < n - 1; i++) {
        ans += (s[i] - '0') * 11;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}