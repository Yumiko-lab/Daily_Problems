#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<vector<int>>> cnt(3, vector<vector<int>>(n, vector<int>(n)));

    int ans = 0;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (++cnt[0][x][y] == n) {
            ans++;
        }
        if (++cnt[1][y][z] == n) {
            ans++;
        }
        if (++cnt[2][x][z] == n) {
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}