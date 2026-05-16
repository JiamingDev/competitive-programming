#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
const int N = 2e5 + 5;
vi num[N];
int solve() {
  int n, m, L;
  cin >> n >> m >> L;
  vector<pii> hurdle(n);
  for (int i = 0; i < n; i++) {
    cin >> hurdle[i].fi >> hurdle[i].se;
  }
  vector<pii> power(m);
  for (int i = 0; i < m; i++) {
    cin >> power[i].fi >> power[i].se;
  }
  priority_queue<int> pq;
  int sum = 0, cnt = 0, j = 0;
  for (int i = 0; i < n; i++) {
    int need = hurdle[i].se - hurdle[i].fi + 1;
    while (j < m && power[j].fi < hurdle[i].fi) {
      pq.push(power[j++].se);
    }
    while (pq.size() && sum < need) {
      sum += pq.top();
      pq.pop();
      cnt++;
    }
    if (sum < need)
      return -1;
  }
  return cnt;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << solve() << "\n";
  }
  return 0;
}