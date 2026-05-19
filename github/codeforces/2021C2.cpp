#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, q;
    cin >> n >> m >> q;
    vi b(m + 1), a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    vector<set<int>> occ(n + 1);
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
      occ[b[i]].insert(i);
    }
    vi first(n + 1);
    for (int i = 1; i <= n; i++)
      first[i] = occ[i].empty() ? m + 1 : *occ[i].begin();
    int bad = 0;
    auto isbad = [&](int i) {
      if (i < 1 || i >= n)
        return false;
      return first[a[i]] > first[a[i + 1]];
    };
    for (int i = 1; i < n; i++)
      bad += isbad(i);
    cout << (bad ? "TIDAK\n" : "YA\n");
    for (int i = 0; i < q; i++) {
      int s, t;
      cin >> s >> t;
      if (b[s] != t) {
        bad -= isbad(pos[b[s]]) + isbad(pos[b[s]] - 1);
        if (pos[t] - 1 != pos[b[s]])
          bad -= isbad(pos[t] - 1);
        if (pos[t] != pos[b[s]] - 1)
          bad -= isbad(pos[t]);
        occ[b[s]].erase(s);
        first[b[s]] = occ[b[s]].empty() ? m + 1 : *occ[b[s]].begin();
        occ[t].insert(s);
        first[t] = occ[t].empty() ? m + 1 : *occ[t].begin();
        bad += isbad(pos[b[s]]) + isbad(pos[b[s]] - 1);
        if (pos[t] - 1 != pos[b[s]])
          bad += isbad(pos[t] - 1);
        if (pos[t] != pos[b[s]] - 1)
          bad += isbad(pos[t]);
        b[s] = t;
      }
      cout << (bad ? "TIDAK\n" : "YA\n");
    }
  }
  return 0;
}