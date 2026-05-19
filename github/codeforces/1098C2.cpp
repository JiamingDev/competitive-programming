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
    vi b(n);
    for (int i = 0; i < n; i++)
      cin >> b[i];
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    int mn = b.front(), mx = b.back();
    vi cands;
    string pre, s = to_string(a);
    if (s.size() > 1)
      cands.pb(stoll(string(s.size() - 1, mx + '0')));
    if (s.size() < 18) {
      string top;
      for (auto x : b)
        if (x) {
          top = x + '0';
          break;
        }
      if (top.size()) {
        cands.pb(stoll(top + string(s.size(), mn + '0')));
      }
    }
    bool equal = true;
    for (int i = 0; i < s.size(); i++) {
      auto it = upper_bound(all(b), s[i] - '0');
      if (it != b.end())
        cands.pb(stoll(pre + to_string(*it) + string(s.size() - i - 1, mn + '0')));
      it = lower_bound(all(b), s[i] - '0');
      if (it != b.begin()) {
        it--;
        cands.pb(stoll(pre + to_string(*it) + string(s.size() - i - 1, mx + '0')));
      }
      if (binary_search(all(b), s[i] - '0'))
        pre += s[i];
      else {
        equal = false;
        break;
      }
    }
    if (equal)
      cands.push_back(a);
    int ans = 1e18;
    for (int x : cands)
      ans = min(ans, abs(a - x));
    cout << ans << "\n";
  }
  return 0;
}