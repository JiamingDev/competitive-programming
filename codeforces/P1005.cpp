#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
void print(i128 n) {
  if (n == 0) {
    cout << 0 << "\n";
    return;
  }
  string s;
  while (n) {
    s.push_back('0' + n % 10);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s << "\n";
}
int main() {
  int n, m;
  cin >> n >> m;
  i128 ans = 0;
  vector<ll> v(m);
  vector<vector<i128>> d(m, vector<i128>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[j];
      d[j][j] = v[j] * ((i128)1 << m);
    }
    for (int len = 1; len < m; len++)
      for (int l = 0; l < m - len; l++)
        d[l][l + len] = max(d[l + 1][l + len] + v[l] * ((i128)1 << (m - len)), d[l][l + len - 1] + v[l + len] * ((i128)1 << (m - len)));
    ans += d[0][m - 1];
  }
  print(ans);
  return 0;
}