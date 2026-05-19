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
  int N = 2e5 + 5;
  int T;
  vi sum(N);
  int t = 1;
  for (int i = 0; t < N; i++, t *= 3) {
    for (int j = t; j < N && j < t * 3; j++)
      sum[j] = i + 1;
  }
  vi cnt = sum;
  for (int j = 1; j < N; j++)
    sum[j] += sum[j - 1];
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    cout << cnt[l] + sum[r] - sum[l - 1] << "\n";
  }
  return 0;
}