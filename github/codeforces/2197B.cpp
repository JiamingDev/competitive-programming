#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
      int t;
      cin >> t;
      pos[t] = i;
    }
    vector<int> a;
    for (int i = 1; i <= n; i++) {
      int t;
      cin >> t;
      if (a.empty() || pos[t] != a.back())
        a.push_back(pos[t]);
    }
    if (is_sorted(a.begin(), a.end()) && a[0] != 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}