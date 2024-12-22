

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    auto print = [&](auto& a) {
        int r = 4, c = n;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    };

    vector<string> g(4, string(n, '.'));

    for (int i = 1; i < n - 1; i++) {
        g[1][i] = '#';
    }
    g[1][1] = '.';

    print(g);

    vector f1(4, vector<int>(n));
    vector f2(4, vector<int>(n));


    auto calc1 = [&]() {
        int r = 4, c = n;
        for (int i = 0; i < r; i++) {
            f1[i][0] = 1;
        }
        for (int i = 0; i < c; i++) {
            f1[0][i] = 1;
        }
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (g[i][j] != '#') {
                    f1[i][j] = f1[i - 1][j] + f1[i][j - 1];
                }
            }
        }
    };

    auto calc2 = [&]() {
        int r = 4, c = n;
        for (int i = 0; i < r; i++) {
            f2[i][0] = 1;
        }
        for (int i = 0; i < c; i++) {
            f2[r - 1][i] = 1;
        }
        for (int i = r - 2; i >= 0; i--) {
            for (int j = 1; j < c; j++) {
                if (g[i][j] != '#') {
                    f2[i][j] = f2[i][j - 1] + f2[i + 1][j];
                }
            }
        }
    };
    
    calc1();
    calc2();
    print(f1);
    print(f2);

    return 0;
}
```