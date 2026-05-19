#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
const int m = 998244353;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 2e6 + 5;
  vi inv(n);
  inv[1] = 1;
  for (int i = 2; i < n; i++)
    inv[i] = (m - m / i) * inv[m % i] % m;
  int x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  vi fac(n);
  fac[0] = fac[1] = 1;
  for (int i = 2; i < n; i++)
    fac[i] = fac[i - 1] * i % m;
  vi inv_fac(n);
  inv_fac[0] = inv_fac[1] = 1;
  for (int i = 2; i < n; i++)
    inv_fac[i] = inv_fac[i - 1] * inv[i] % m;
  int ans = 0;
  auto C = [&](int n, int k) {
    return fac[n] * inv_fac[k] % m * inv_fac[n - k] % m;
  };
  for (int k = 1; k <= min(x1, x2); k++)
    ans = (ans + C(x2 + 1, k) * C(x1 - 1, k - 1) % m * C(x2 + x3 - k, x2 - k) % m) % m;
  cout << ans;
  return 0;
}