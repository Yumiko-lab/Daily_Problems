

## CF1995C

$$
\begin{align}
a_i^{2^{k_i}} &= a_{i - 1}^{2^{k_{i - 1}}} \\
2^{k_i} & = \log_{a_i}a_{i - 1}^{(2^{k_{i - 1}})} = 2^{k_{i - 1}} \cdot \log_{a_i}a_{i - 1} \\
k_i & = \log_2(2^{k_{i - 1}} \cdot \log_{a_i}a_{i - 1}) = \log_2{2^{k_{i - 1}}} + \log_2 \log_{a_i}a_{i - 1} = k_{i - 1} + \log_2 \log_{a_i}a_{i - 1}\\
k_i & = k_{i - 1} + \log_2 \frac {\lg a_{i - 1}}{\lg a_i} \\
\end{align}
$$

答案就是 $k_i$ 的前缀和的和。

> [!NOTE]
> 遇到非常多这种题，需要满足单调性的条件下，贪心从前往后，或者从后往前，然后一般会爆范围 (越来越大)，或者卡精度 (越来越小)，一般做法都是推公式或者用

```cpp
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
```