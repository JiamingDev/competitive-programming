#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> pre, all;
    int cost;
    for (int i = 1; i <= n; i++) {
      int t;
      cin >> t;
      if (i < p)
        pre.push_back(t);
      if (i != p)
        all.push_back(t);
      else
        cost = t;
    }
    sort(pre.begin(), pre.end());
    sort(all.begin(), all.end());
    int cnt = 0;
    if (p <= k) {
      if (m >= cost) {
        cnt++;
        m -= cost;
      } else {
        cout << 0 << "\n";
        continue;
      }
    } else {
      for (int i = 0; i < p - k; i++)
        m -= pre[i];
      if (m < cost) {
        cout << 0 << "\n";
        continue;
      }
      cnt++;
      m -= cost;
    }
    int need = 0;
    for (int i = 0; i < n - k; i++)
      need += all[i];
    need += cost;
    cnt += m / need;
    cout << cnt << "\n";
  }
  return 0;
}