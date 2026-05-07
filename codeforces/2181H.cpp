#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int w, h, d;
  cin >> w >> h >> d;
  int n;
  cin >> n;
  int w1 = gcd(n, w);
  n /= w1;
  int h1 = gcd(n, h);
  n /= h1;
  int d1 = gcd(n, d);
  n /= d1;
  if (n != 1)
    cout << -1 << "\n";
  else
    cout << w1 - 1 << " " << h1 - 1 << " " << d1 - 1 << "\n";
  return 0;
}