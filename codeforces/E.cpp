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
    vector<ll> suf_min(n);
    ll suma = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      suma += a[i];
    }
    ll cnt = 0, ans = 0, sums;
    sums = suf_min[n - 1] = a[n - 1];
    cnt++;
    for (int i = n - 2; i >= 0; i--) {
      suf_min[i] = min(a[i], suf_min[i + 1]);
      sums += suf_min[i];
      if (suf_min[i] != suf_min[i + 1]) {
        ans = max(ans, cnt);
        cnt = 0;
      }
      cnt++;
    }
    ans = max(ans, cnt);
    cout << suma - sums + ans - 1 << "\n";
  }
  return 0;
}