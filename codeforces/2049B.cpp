#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1 = count(s.begin(), s.begin() + n - 1, 'p'), cnt2 = count(s.begin() + 1, s.end(), 's');
    if (cnt1 && cnt2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}