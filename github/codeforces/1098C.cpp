#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
#define i128 __int128
using pii = pair<int, int>;
using vi = vector<int>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, n;
    cin >> a >> n;
    int b1, b2;
    cin >> b1 >> b2;
    if (b1 > b2)
      swap(b1, b2);
    int ans = 1e18;
    string t = to_string(a);
    vi mx(20), mn(20);
    for (int i = 0; i < t.size(); i++) {
      int res = 0;
      for (int j = i + 1; j < t.size(); j++)
        res = res * 10 + b1;
      mn[i] = res;
      res = 0;
      for (int j = i + 1; j < t.size(); j++)
        res = res * 10 + b2;
      mx[i] = res;
    }
    int pos = -1;
    vi pw(19);
    pw[0] = 1;
    for (int i = 1; i < 19; i++)
      pw[i] = pw[i - 1] * 10;
    for (int i = 0; i < t.size(); i++)
      if (t[i] > b1 + '0' && t[i] < b2 + '0') {
        ans = min(ans, abs(b2 * pw[t.size() - i - 1] + mn[i] - a % pw[t.size() - i]));
        ans = min(ans, abs(a % pw[t.size() - i] - (b1 * pw[t.size() - i - 1] + mx[i])));
        pos = i;
        break;
      } else if (t[i] > b2 + '0') {
        ans = min(ans, abs(b2 * pw[t.size() - i - 1] + mx[i] - a % pw[t.size() - i]));
        pos = i;
        break;
      } else if (t[i] < b1 + '0') {
        ans = min(ans, abs(b1 * pw[t.size() - i - 1] + mn[i] - a % pw[t.size() - i]));
        pos = i;
        break;
      }
    if (pos == -1)
      ans = 0;
    else {
      for (int i = 0; i < pos; i++)
        if (t[i] < b2 + '0')
          ans = min(ans, abs(b2 * pw[t.size() - i - 1] + mn[i] - a % pw[t.size() - i]));
        else if (t[i] > b1 + '0')
          ans = min(ans, abs(b1 * pw[t.size() - i - 1] + mx[i] - a % pw[t.size() - i]));
      if (t.size() < 18) {
        if (b1 == 0)
          ans = min(ans, abs(b2 * pw[t.size()] + b1 * pw[t.size() - 1] + mn[0] - a));
        else
          ans = min(ans, abs(b1 * pw[t.size()] + b1 * pw[t.size() - 1] + mn[0] - a));
      }
      if (t.size() > 1)
        ans = min(ans, abs(mx[0] - a));
    }
    cout << ans << "\n";
  }
  return 0;
}