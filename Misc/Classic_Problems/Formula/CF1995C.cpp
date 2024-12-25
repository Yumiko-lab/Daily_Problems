#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr double eps = 1e-9;

void solve() {
    int n, last;
    cin >> n >> last;
    i64 ans = 0;
    int sum = 0;
    bool ok = true;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (last != 1 && x == 1) {
            ok = false;
        }
        sum += max(-1.0 * sum, ceil(log2(log2(last) / log2(x)) - eps)); // why -1.0 * sum, why - eps ??
        ans += sum;
        last = x;
    }
    if (!ok) {
        ans = -1;
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