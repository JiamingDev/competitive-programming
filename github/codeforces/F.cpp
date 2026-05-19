#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
ll a[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> h(n + 1);
    ll sum0 = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      h[a[i]] += 1;
      sum0 += a[i] * i;
    }
    sum += (2 * n - h[n] - 1) * h[n] / 2;
    for (int i = n - 1; i >= 1; i--) {
      h[i] += h[i + 1];
      sum += (2 * n - h[i] - 1) * h[i] / 2;
    }
    ll diata = 0;
    for (int i = 0; i < n; i++)
      diata = max(diata, h[a[i]] - n + i);
    cout << sum - sum0 + diata << "\n";
  }
  return 0;
}