#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 50005;
int mask[maxn], ansmask[maxn];
int n;
bool check(int d) {
  fill(ansmask, ansmask + d, -1);
  for (int i = 0; i < d; i++) {
    for (int k = 0; i + k * d < n; k++)
      ansmask[i] &= mask[i + k * d];
    if (!ansmask[i])
      return false;
  }
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(mask, 0, sizeof(mask));
    int k;
    cin >> n >> k;
    string s;
    for (int i = 0; i < k; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++)
        mask[j] |= 1 << (s[j] - 'a');
    }
    for (int d = 1; d <= n; d++)
      if (n % d == 0 && check(d)) {
        string ans;
        for (int i = 0; i < d; i++)
          ans += 'a' + __builtin_ctz(ansmask[i]);
        for (int i = 0; i < n / d; i++)
          cout << ans;
        cout << "\n";
        break;
      }
  }
  return 0;
}