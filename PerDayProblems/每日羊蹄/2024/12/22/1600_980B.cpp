#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if ((~k & 1) || k == n - 2) {
        cout << "YES\n";
        vector<string> g(4, string(n, '.'));

        if (~k & 1) {
            for (int i = 1, j = 0; j < k / 2; i++, j++) {
                g[1][i] = g[2][i] = '#';
            }
        } else {
            for (int i = 1; i < n - 1; i++) {
                g[1][i] = '#';
            }
        }
        for (int i = 0; i < 4; i++) {
            cout << g[i] << '\n';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}