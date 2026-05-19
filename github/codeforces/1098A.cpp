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
    int ans = 0;
    int n;
    cin >> n;
    vi cnt(4);
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (cnt[3 - t]) {
        cnt[3 - t]--;
        ans++;
      } else if (t == 0)
        ans++;
      else
        cnt[t]++;
    }
    ans += cnt[1] / 3 + cnt[2] / 3;
    cout << ans << "\n";
  }
  return 0;
}