#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  vector<int> vis(31), pm;
  for (int i = 2; i <= 30; i++)
    if (!vis[i]) {
      pm.push_back(i);
      for (int j = i * i; j <= 30; j += i)
        vis[j] = 1;
    }
  while (T--) {
    int n, k;
    cin >> n >> k;
    int g;
    for (int x : pm)
      if (k % x) {
        g = x;
        break;
      }
    forn(i, n) {
      int t;
      cin >> t;
      forn(j, g) if ((t + j * k) % g == 0) {
        cout << t + j * k << " ";
        break;
      }
    }
    cout << "\n";
  }
  return 0;
}