
## CF1506D

非常经典的题目，考察一个经典性质：

> [!NOTE]
> n 类物品，两两不同种类的物品进行配对，当且仅当某一类的数量的最大值小于总数的一半时，可以完全配对，否则会剩余 $2 \times mx - n$ 个元素无法配对 (且都是数量最多的一类)。

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, ++cnt[x]);
    }
    if (2 * mx <= n) {
        cout << (n & 1) << '\n';
    } else {
        cout << 2 * mx - n << '\n';
    }
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
```