#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll sum = 0, diata = -1, mn = 0;
    for (ll i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      diata = max(diata, i * i + i - sum - mn);
      mn = min(i * i + i - sum, mn);
    }
    if (diata < 0)
      diata = 0;
    cout << sum + diata << "\n";
  }
  return 0;
}