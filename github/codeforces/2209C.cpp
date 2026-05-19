#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
int query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int res;
  cin >> res;
  return res;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    bool ok = 0;
    for (int i = 3; i <= 2 * n; i += 2)
      if (query(i, i + 1) == 1) {
        cout << "! " << i << endl;
        ok = 1;
        break;
      }
    if (ok)
      continue;
    ok = 0;
    for (int i = 3; i <= 4; i++)
      if (query(1, i) == 1) {
        cout << "! " << 1 << endl;
        ok = 1;
        break;
      }
    if (ok)
      continue;
    cout << "! " << 2 << endl;
  }
  return 0;
}