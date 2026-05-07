#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int t, last = -1;
    int cnt = 0, st;
    for (int i = 0; i < n; i++) {
      cin >> t;
      if (t > last + 1 || t <= st) {
        st = t;
        cnt++;
      }
      last = t;
    }
    cout << cnt << "\n";
  }
  return 0;
}