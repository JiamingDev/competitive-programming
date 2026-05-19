#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vi c(n);
    int ans = 0, lef = 0, cnt = 0, wait = 0;
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      if (c[i] >= 2) {
        cnt++;
        ans += c[i];
        lef += (c[i] - 2) / 2;
      } else
        wait++;
    }
    if (ans) {
      if (cnt == 1)
        ans += min(lef + 1, wait);
      else {
        ans += min(wait, lef);
      }
    }
    cout << (ans >= 3 ? ans : 0) << "\n";
  }
  return 0;
}