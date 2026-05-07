#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
int n, k;
vector<int> a;
bool check(int len) {
  int cnt = 0;
  for (int x : a) {
    cnt += x / len;
    if (x % len == 0)
      cnt--;
    if (cnt > k)
      return false;
  }
  return true;
}
signed main() {
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int l = 1, r = *max_element(a.begin(), a.end()), ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << "\n";
  return 0;
}