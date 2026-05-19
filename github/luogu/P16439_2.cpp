#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 505;
char a[maxn][maxn];
bool solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m - 1; j++) {
      int t = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
      if (t == '1' + '1' + '1' + '0' || t == '0' + '0' + '0' + '1')
        return false;
    }
  return true;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    if (solve())
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}