#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, f;
    string s;
    cin >> n >> f >> s;

    set<string> ans;
    map<string, int> cnt;

    for (int i = 0; i + 2 < n; i++) {
        string t = s.substr(i, 3);
        cnt[t] += 1;
    }

    for (int i = 0; i + 2 < n; i++) {
        if (i - 1 >= 2) {
            cnt[s.substr(i - 3, 3)] += 1;
        }
        string t = s.substr(i, 3);
        // for (int j = max(0, i - 2); j < min(n, i + 2); j++) {
        //     cnt[s.substr(j, 3)] -= 1;
        // }
        for (int j = 0; j < 3; j++) {
            for (int k = max(0, i + j - 2); k < i + j; k++) {
                cnt[s.substr(k, 3)] -= 1;
            }
            for (char c = 'a'; c <= 'z'; c++) {
                // 修改 i + j 位置的字符
                t[j] = c;
                if (t[0] != t[1] && t[1] == t[2] && cnt[t] == f - 1) {
                    ans.insert(t);
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto s : ans) {
        cout << s << '\n';
    }

    return 0;
}

/*

Debugging: ...


*/