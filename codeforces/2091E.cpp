#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  int N = 1e7 + 5;
  vector<int> vis(N + 1);
  for (int i = 2; i <= N; i++)
    if (!vis[i]) {
      for (int j = i; j <= N; j += i)
        vis[j]++;
    }
  for (int i = 2; i <= N; i++)
    vis[i] += vis[i - 1];
  while (T--) {
    int n;
    cin >> n;
    cout << vis[n] << "\n";
  }
  return 0;
}