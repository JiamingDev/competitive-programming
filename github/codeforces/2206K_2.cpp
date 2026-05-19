#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[4];
string s;
bool check(int a, int b) {
  int lef[4], sum = s.size();
  memcpy(lef, cnt, sizeof(cnt));
  if (lef[0] < a)
    return false;
  lef[0] -= a;
  sum -= a;
  if (lef[0] + lef[1] < 2 * b)
    return false;
  sum -= 2 * b;
  if (lef[2] + lef[1] + lef[0] - 2 * b < a + b)
    return false;
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    cin >> s;
    for (char c : s) {
      if (c == '0')
        cnt[0]++;
      else if (c == '1')
        cnt[1]++;
      else if (c < '6')
        cnt[2]++;
      else
        cnt[3]++;
    }
    int ans = 0;
    for (int a = 0; a <= s.size() / 4; a++) {
      int l = -1, r = s.size() / 4 - a;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(a, mid)) {
          l = mid;
        } else
          r = mid - 1;
      }
      if (l > -1) {
        ans = max(ans, a + l);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}