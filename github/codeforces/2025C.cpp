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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(all(a));
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      j = max(i, j);
      while (j + 1 < n && a[j + 1] - a[j] <= 1 && a[j + 1] - a[i] < k)
        j++;
      ans = max(ans, j - i + 1);
    }
    cout << ans << "\n";
  }
  return 0;
}