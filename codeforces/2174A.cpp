#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  string s, t, temp;
  cin >> s >> t;
  vector<int> cnts(26), cntt(26);
  for (char c : s) {
    cnts[c - 'a']++;
  }
  for (char c : t)
    cntt[c - 'a']++;
  for (int i = 0; i < 26; i++)
    if (cnts[i] > cntt[i]) {
      cout << "Impossible\n";
      return;
    } else
      cntt[i] -= cnts[i];
  int idx = 0;
  for (int i = 0; i < 26; i++) {
    if (s[idx] - 'a' == i) {
      while (idx < (int)s.size() && s[idx] - 'a' <= i) {
        cout << s[idx++];
      }
    }
    while (cntt[i]--)
      cout << char('a' + i);
  }
  cout << "\n";
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}