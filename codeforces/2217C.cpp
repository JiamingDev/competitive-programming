#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (gcd(n, a) == 1 && gcd(m, b) == 1 && gcd(m, n) <= 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}