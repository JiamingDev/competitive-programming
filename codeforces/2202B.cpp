#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  string s;
  while (T--) {
    int n;
    cin >> n;
    cin >> s;
    if ((n & 1) && s[0] == 'b') {
      cout << "no\n";
      continue;
    }
    int st = 0;
    if (n & 1)
      st = 1;
    bool ok = 1;
    for (int i = st; i < s.size(); i += 2)
      if (s[i] == s[i + 1] && s[i] != '?') {
        cout << "no\n";
        ok = 0;
        break;
      }
    if (ok)
      cout << "yes\n";
  }
  return 0;
}