#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
      int u = i - 1, v = i;
      if (u == r)
        u = l - 1;
      if (v == r)
        v = l - 1;
      cout << (u ^ v) << " ";
    }
    cout << "\n";
  }
  return 0;
}