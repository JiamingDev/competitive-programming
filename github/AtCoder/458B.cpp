#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
int a[55][55];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int nr = i + dr[k], nc = j + dc[k];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m)
          cnt++;
      }
      a[i][j] = cnt;
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << a[i][j] << " ";
    cout << "\n";
  }
  return 0;
}