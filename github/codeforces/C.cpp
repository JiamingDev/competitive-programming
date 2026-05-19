#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<int> mid, lef, righ, fron;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (t % 6 == 0)
        fron.push_back(t);
      else if (t % 2 == 0)
        lef.push_back(t);
      else if (t % 3 == 0)
        righ.push_back(t);
      else
        mid.push_back(t);
    }
    int cnt = 0;
    for (int x : fron) {
      cout << x << (++cnt == n ? "\n" : " ");
    }
    for (int x : lef) {
      cout << x << (++cnt == n ? "\n" : " ");
    }
    for (int x : mid) {
      cout << x << (++cnt == n ? "\n" : " ");
    }
    for (int x : righ) {
      cout << x << (++cnt == n ? "\n" : " ");
    }
  }
  return 0;
}