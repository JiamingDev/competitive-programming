#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[4000];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < i; j++)
        ans = max(a[i] ^ a[j], ans);
    }
    cout << ans << "\n";
  }
  return 0;
}