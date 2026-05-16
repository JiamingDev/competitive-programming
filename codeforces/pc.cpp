#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
bool solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int flag = 1;
  for (int i = 0; i < n; i++)
    if (s1[i] != s2[i]) {
      if (flag) {
        s1[i] = '(';
        s2[i] = ')';
      } else {
        s2[i] = '(';
        s1[i] = ')';
      }
      flag ^= 1;
    }
  int t1 = 0, t2 = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '(')
      t1++;
    else
      t1--;
    if (s2[i] == '(')
      t2++;
    else
      t2--;
    if (t1 < 0 || t2 < 0)
      return false;
  }
  if (t1 || t2)
    return false;
  return true;
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}