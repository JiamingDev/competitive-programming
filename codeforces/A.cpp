#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    if (x & 1 && y & 1) {
      cout << "no\n";
      continue;
    }
    cout << "yes\n";
  }
  return 0;
}