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
    int cnt = __builtin_popcountll(n);
    if (cnt > 1) {
      cout << cnt + 1 << "\n";
      for (int i = 62; i >= 0; i--)
        if (1ll << i & n) {
          cout << (n ^ 1ll << i) << " ";
        }
    } else
      cout << 1 << "\n";
    cout << n << "\n";
  }
  return 0;
}