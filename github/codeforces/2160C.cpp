#include <bits/stdc++.h>
using namespace std;
bool solve(int n) {
  if (n == 0) {
    return 1;
  }
  if (__builtin_popcount(n) & 1)
    return false;
  int lz = __builtin_clz(n), tz = __builtin_ctz(n);
  int pos = 31 - lz;
  for (int i = tz; i < pos; i++, pos--)
    if ((n >> i & 1) != (n >> pos & 1))
      return false;
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (solve(n))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}