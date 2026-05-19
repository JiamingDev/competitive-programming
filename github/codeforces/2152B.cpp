#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, rk, ck, rd, cd, mr, mc;
    cin >> n >> rk >> ck >> rd >> cd;
    if (rk > rd)
      mr = n - rd;
    else if (rk == rd)
      mr = 0;
    else
      mr = rd;
    if (ck > cd)
      mc = n - cd;
    else if (ck == cd)
      mc = 0;
    else
      mc = cd;
    cout << max(mr, mc) << "\n";
  }
  return 0;
}