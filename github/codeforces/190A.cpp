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
    int n, a, b;
    cin >> n >> a >> b;
    if (3 * a <= b)
      cout << a * n << "\n";
    else {
      int ans = n / 3 * b;
      n -= n / 3 * 3;
      if (n * a <= b)
        ans += n * a;
      else
        ans += b;
      cout << ans << "\n";
    }
  }
  return 0;
}