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
  vector<double> a[3];
  int t;
  for (int i = 0; i < 3; i++) {
    int cnt[7] = {0};
    a[i].resize(3);
    for (int j = 0; j < 6; j++) {
      cin >> t;
      cnt[t]++;
    }
    for (int k = 0; k < 3; k++)
      a[i][k] = (double)cnt[4 + k] / 6.0;
  }
  vi v = {0, 1, 2};
  double ans = 0;
  do {
    ans += a[0][v[0]] * a[1][v[1]] * a[2][v[2]];
  } while (next_permutation(v.begin(), v.end()));
  printf("%.8f", ans);
  return 0;
}