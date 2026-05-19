#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], vis[maxn];
int n, k;
bool solve() {
  for (int i = 0; i < n - k; i++)
    if (b[i] != -1 && b[i] != a[i])
      return false;
  for (int i = k; i < n; i++)
    if (b[i] != -1 && b[i] != a[i])
      return false;
  memset(vis, 0, sizeof(vis));
  for (int i = n - k; i < k; i++)
    vis[a[i]] = 1;
  for (int i = n - k; i < k; i++)
    if (b[i] != -1 && !vis[b[i]])
      return false;
    else if (b[i] != -1)
      vis[b[i]] = 0;
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}