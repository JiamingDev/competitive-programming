#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> b = a;
    int mx = *max_element(a.begin(), a.end()), mn = *min_element(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
      cout << "-1\n";
      continue;
    }
    int k = 1e9;
    for (int i = 0; i < n; i++)
      if (a[i] != b[i])
        k = min(k, max(a[i] - mn, mx - a[i]));
    cout << k << "\n";
  }
  return 0;
}