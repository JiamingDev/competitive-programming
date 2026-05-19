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
    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      mx = max(mx + t, abs(mn + t));
      mn = mn + t;
    }
    cout << mx << "\n";
  }
  return 0;
}