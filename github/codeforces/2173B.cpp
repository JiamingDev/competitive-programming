#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll mn = 0, mx = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++) {
      ll t;
      cin >> t;
      ll tm = mn;
      mn = min(mn - a[i], t - mx);
      mx = max(mx - a[i], t - tm);
    }
    cout << mx << "\n";
  }
  return 0;
}