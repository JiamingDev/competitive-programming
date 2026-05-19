#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n & 1)
      cout << n - 1 << " ";
    else
      cout << n << " ";
    for (int i = 2; i <= n - 1; i++)
      cout << (i ^ 1) << " ";
    cout << 1 << "\n";
  }
  return 0;
}