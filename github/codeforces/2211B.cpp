#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  vector<int> pm;
  int m = 2e5;
  vector<int> vis(m + 1);
  for (ll i = 2; i <= m; i++)
    if (!vis[i]) {
      pm.push_back(i);
      for (ll j = i * i; j <= m; j += i)
        vis[j] = 1;
    }
  while (T--) {
    int x, y;
    cin >> x >> y;
    int res = 1;
    int n = abs(x - y);
    if (n)
      for (int i = 0; i < pm.size(); i++)
        if (n % pm[i] == 0) {
          int cnt = 0;
          while (n % pm[i] == 0) {
            n /= pm[i];
            cnt++;
          }
          res *= cnt + 1;
          if (n == 1)
            break;
        }
    cout << res << "\n";
    for (int i = 0; i < x; i++)
      cout << 1 << " ";
    for (int i = 0; i < y; i++)
      cout << -1 << " ";
    cout << "\n";
  }
  return 0;
}