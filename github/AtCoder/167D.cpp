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
  int n, k;
  cin >> n >> k;
  vi vis(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int cur = 1;
  vi seq;
  while (1) {
    seq.pb(cur);
    vis[cur] = 1;
    if (vis[a[cur]])
      break;
    cur = a[cur];
  }
  int pos = find(all(seq), a[cur]) - seq.begin();
  if (k < pos)
    cout << seq[k];
  else {
    k -= pos;
    cout << seq[pos + k % (seq.size() - pos)];
  }
  return 0;
}