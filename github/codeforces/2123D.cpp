#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), '1') <= k || n < 2 * k) {
      cout << "Alice\n";
    } else
      cout << "Bob\n";
  }
  return 0;
}