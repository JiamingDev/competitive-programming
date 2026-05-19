#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
int solve() {
  int n, k, ans = 0;
  cin >> n >> k;
  vector<int> a(n), cnt(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++)
    if (cnt[i] % k != 0)
      return 0;
    else
      cnt[i] /= k;
  int l = 0, r = 0;
  vector<int> cn(n + 1);
  while (r < n) {
    ++cn[a[r]];
    while (cn[a[r]] > cnt[a[r]])
      cn[a[l++]]--;
    ans += r - l + 1;
    r++;
  }
  return ans;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    cout << solve() << "\n";
  }
  return 0;
}