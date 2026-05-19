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
    int n, x;
    cin >> n >> x;
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      sum += t;
      mx = max(mx, t);
    }
    cout << max(mx, (sum - 1 + x) / x) << "\n";
  }
  return 0;
}