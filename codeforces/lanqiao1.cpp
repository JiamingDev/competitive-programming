#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
int n = 2026202620262026;
signed main() {
  int up = (1ll << 51) | (1ll << 25) - 1, down = (1ll << 50) - 1 ^ (1ll << 25) - 1;
  cout << (up - n > n - down ? down : up);
  return 0;
}