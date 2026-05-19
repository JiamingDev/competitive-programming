#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
int power2(int n) {
  int res = 1;
  while (n--)
    res *= 2;
  return res;
}
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
    int len = r - l;
    ++cn[a[r]];
    int t = 0;
    while (cn[a[r]] > cnt[a[r]]) {
      cn[a[l++]]--;
      t++;
    }
    ans += t * (len - t) + (t + 1) * t / 2;
    r++;
  }
  ans += (r - l + 1) * (r - l) / 2;
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