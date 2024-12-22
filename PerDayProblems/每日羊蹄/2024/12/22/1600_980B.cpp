#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (k != 2 || k != n - 2) {
        cout << "NO\n";
        return 0;
    }

    vector<string> g(4, string(n, '.'));

    if (k == 2) {
        g[1][1] = g[2][1] = '#';
    } else {
        for (int i = 1; i < n - 1; i++) {
            g[1][i] = '#';
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}