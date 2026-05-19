#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int cnt[30], cnt2[maxn][30];
string s[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < s[i].size(); j++) {
      cnt[s[i][j] - 'A']++;
      cnt2[i][s[i][j] - 'A']++;
    }
  }
  for (int i = 0; i < n; i++) {
    int need = 0;
    bool ok = 1;
    for (int j = 0; j < 26; j++)
      if (cnt2[i][j]) {
        int cn = cnt[j] - cnt2[i][j];
        if (cn == 0 || (cnt2[i][j] - 1 + cn) / cn > m) {
          cout << -1 << " ";
          ok = 0;
          break;
        } else
          need = max(need, (cnt2[i][j] - 1 + cn) / cn);
      }
    if (ok)
      cout << m - need << " ";
  }
  return 0;
}