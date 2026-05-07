#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
struct node {
  int v, idx;
  bool operator<(const node &b) const {
    return tuple{v, -idx} > tuple{b.v, -b.idx};
  }
};
signed main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      int pos = i, mx = 0;
      for (int j = i; j < min((int)s.size(), i + 10); j++)
        if (s[j] - '0' - (j - i) > mx) {
          mx = s[j] - '0' - (j - i);
          pos = j;
        }
      while (pos > i) {
        s[pos]--;
        swap(s[pos], s[pos - 1]);
        pos--;
      }
    }
    cout << s << "\n";
  }
  return 0;
}