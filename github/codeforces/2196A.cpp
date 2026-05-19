#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    ll p, q;
    cin >> p >> q;
    if (2 * q <= 3 * p && q > p)
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
  return 0;
}