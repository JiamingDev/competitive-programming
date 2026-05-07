#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
double c[maxn];
double p[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> c[i] >> p[i];
      p[i] /= 100;
    }
    double ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans = max(ans, c[i] + (1 - p[i]) * ans);
    }
    cout << fixed << setprecision(8) << ans << "\n";
  }
  return 0;
}