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
  string tt;
  for (int i = 0; i < 26; i++)
    tt += string(cntt[i], i + 'a');
  int l = 0, r = 0;
  while (l < s.size() && r < tt.size()) {
    if (s[l] <= tt[r])
      cout << s[l++];
    else
      cout << tt[r++];
  }
  while (l < s.size())
    cout << s[l++];
  while (r < tt.size())
    cout << tt[r++];
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