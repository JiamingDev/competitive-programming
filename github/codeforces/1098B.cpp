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
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    int ans;
    if (n == 2 || n == 3) {
      ans = 1;
    } else {
      if (x1 > x2)
        swap(x1, x2);
      ans = k + min(x2 - x1, x1 - x2 + n);
    }
    cout << ans << "\n";
  }
  return 0;
}