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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
    }
    int cnt = 0;
    if (n > 1 && a[0] / gcd(a[0], a[1]) != 1)
      cnt++;
    if (n > 1 && a[n - 1] / gcd(a[n - 1], a[n - 2]) != 1)
      cnt++;
    for (int i = 1; i < n - 1; i++) {
      ll g1 = gcd(a[i - 1], a[i]), g2 = gcd(a[i], a[i + 1]);
      if (a[i] > g1 * g2 / gcd(g1, g2))
        cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}