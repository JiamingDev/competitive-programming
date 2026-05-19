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
    int i = 0, cnt = 0;
    while (i < n - 1) {
      if (a[i] + a[i + 1] == 7 || a[i] == a[i + 1]) {
        cnt++;
        i += 2;
      } else
        i++;
    }
    cout << cnt << "\n";
  }
  return 0;
}