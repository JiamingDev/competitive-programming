#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int more;
char m;
bool check(int len) {
  int l = 0, r = 0, t = more;
  while (l < n && s[l] != m) {
    l++;
    r++;
  }
  while (l <= r && r < n) {
    if (s[r] == m)
      t--;
    else
      t++;
    if (r - l + 1 > len) {
      l++;
      t++;
      while (l < n && s[l] != m) {
        l++;
        t--;
      }
      if (l == n)
        return false;
      else if (l > r) {
        r = l;
        t = more - 1;
      }
    }
    if (t == 0)
      return true;
    r++;
  }
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s;
    int cnt = count(s.begin(), s.end(), 'a');
    more = cnt - (n - cnt);
    if (more == 0) {
      cout << 0 << "\n";
      continue;
    } else if (more > 0)
      m = 'a';
    else
      m = 'b';
    more = abs(more);
    int l = 1, r = n;
    int ans = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    if (ans == n)
      cout << -1 << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}