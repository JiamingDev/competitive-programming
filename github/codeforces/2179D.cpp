#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << ((1 << n) - 1) << " ";
    for (int k = n - 1; k >= 0; k--)
      for (int m = 0; m < 1 << (n - k - 1); m++)
        cout << ((m << (k + 1)) | ((1 << k) - 1)) << " ";
    cout << "\n";
  }
  return 0;
}