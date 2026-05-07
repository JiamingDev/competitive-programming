#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int a[maxn];
int n;
bool check(int x) {
  x--;
  int pos1 = find(a, a + 2 * n, x) - a, pos2 = find(a + pos1 + 1, a + 2 * n, x) - a;
  vector<bool> vis(n + 1);
  int k;
  bool ok = 1;
  for (k = 1; pos1 + k <= pos2 - k && a[pos1 + k] == a[pos2 - k]; k++)
    vis[a[pos1 + k]] = 1;
  if (pos1 + k < pos2 - k)
    ok = 0;
  if (ok) {
    for (int i = 1; pos1 - i >= 0 && pos2 + i < 2 * n && a[pos1 - i] == a[pos2 + i]; i++)
      vis[a[pos1 - i]] = 1;
    for (int i = 0; i < x; i++)
      if (!vis[i]) {
        ok = 0;
        break;
      }
    if (ok)
      return true;
  }
  fill(vis.begin(), vis.end(), 0);
  for (int i = 1; pos1 - i >= 0 && pos1 + i < 2 * n && a[pos1 - i] == a[pos1 + i]; i++)
    vis[a[pos1 - i]] = 1;
  ok = 1;
  for (int i = 0; i < x; i++)
    if (!vis[i]) {
      ok = 0;
      break;
    }
  if (ok)
    return true;
  fill(vis.begin(), vis.end(), 0);
  for (int i = 1; pos2 - i >= 0 && pos2 + i < 2 * n && a[pos2 - i] == a[pos2 + i]; i++)
    vis[a[pos2 - i]] = 1;
  ok = 1;
  for (int i = 0; i < x; i++)
    if (!vis[i]) {
      ok = 0;
      break;
    }
  if (ok)
    return true;
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
      cin >> a[i];
    int l = 1, r = n;
    while (l < r) {
      int x = l + (r - l - 1 + 2) / 2;
      if (check(x)) {
        l = x;
      } else
        r = x - 1;
    }
    cout << l << "\n";
  }
  return 0;
}