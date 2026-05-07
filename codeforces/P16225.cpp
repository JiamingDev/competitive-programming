#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, c, w;
int solve() {
  if (w == 0)
    return 0;
  if (w % c)
    return -1;
  w /= c;
  if (w > (1 + n) * n / 2)
    return -1;
  unordered_set<int> s;
  s.insert(0);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
    if (s.count(sum - w))
      return 1;
    s.insert(sum);
  }
  return 2;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> c >> w;
    cout << solve() << "\n";
  }
  return 0;
}