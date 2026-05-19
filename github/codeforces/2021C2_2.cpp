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
    vi pos(n + 1), b(m + 1), first(n + 1);
    for (int i = 1; i <= n; i++) {
      int t;
      cin >> t;
      pos[t] = i;
    }
    vector<set<int>> occ(n + 1);
    for (int i = 1; i <= m; i++) {
      int t;
      cin >> t;
      b[i] = pos[t];
      occ[b[i]].insert(i);
    }
    for (int i = 1; i <= n; i++)
      first[i] = occ[i].empty() ? m + 1 : *occ[i].begin();
    int bad = 0;
    auto isbad = [&](int i) {
      if (i <= 0 || i >= n)
        return false;
      return first[i] > first[i + 1];
    };
    for (int i = 1; i < n; i++)
      bad += isbad(i);
    cout << (bad ? "TIDAK\n" : "YA\n");
    for (int i = 0; i < q; i++) {
      int s, t;
      cin >> s >> t;
      t = pos[t];
      set<int> p;
      p.insert({t, t - 1, b[s], b[s] - 1});
      for (int x : p)
        bad -= isbad(x);
      occ[b[s]].erase(s);
      occ[t].insert(s);
      first[b[s]] = occ[b[s]].empty() ? m + 1 : *occ[b[s]].begin();
      first[t] = occ[t].empty() ? m + 1 : *occ[t].begin();
      for (int x : p)
        bad += isbad(x);
      cout << (bad ? "TIDAK\n" : "YA\n");
      b[s] = t;
    }
  }
  return 0;
}