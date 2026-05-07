#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int T;
  cin >> T;
  vector<int> pm;
  int m = 1e6;
  vector<bool> vis(m + 1);
  for (int i = 2; i <= m; i++)
    if (!vis[i]) {
      pm.push_back(i);
      for (int j = i * i; j <= m; j += i)
        vis[j] = 1;
    }
  while (T--) {
    int n;
    cin >> n;
    int cur = 1;
    for (int i = 0; i < n; i++) {
      cout << pm[i] * pm[i + 1] << " ";
    }
    cout << "\n";
  }
  return 0;
}