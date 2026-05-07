#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll maxs = 0, sum = 0;
    int t;
    for (int i = 0; i < n; i++) {
      cin >> t;
      if (t)
        maxs++;
      sum += t;
    }
    cout << min(maxs, sum - n + 1) << "\n";
  }
  return 0;
}