#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> pos(N);
    for (int i = 0; i < a.size(); i++)
      pos[a[i]] = i;
    for (int i = 1; i < N; i++)
      if (!pos[i])
        pos[i] = pos[i - 1];
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
      for (int j = i + 1; j < a.size(); j++) {
        int lim = a.back() - (a[i] + a[j]);
        if (lim + 1 > a[i] + a[j] - 1)
          continue;
        int l = j;
        if (lim > 0)
          l = max(j, pos[lim]);
        int r = pos.back();
        if (a[i] + a[j] - 1 < N)
          r = pos[a[i] + a[j] - 1];
        sum += r - l;
      }
    cout << sum << "\n";
  }
  return 0;
}