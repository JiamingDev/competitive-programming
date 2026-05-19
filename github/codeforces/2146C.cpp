#include <bits/stdc++.h>
using namespace std;
vector<int> p;
bool solve() {
  int n;
  cin >> n;
  p.resize(n);
  string s;
  cin >> s;
  int last = 0;
  for (int i = 0; i < n; i++)
    p[i] = i + 1;
  for (int i = 0; i < n; i++)
    if (s[i] == '1') {
      if (i - last == 1)
        return false;
      reverse(p.begin() + last, p.begin() + i);
      last = i + 1;
    }
  if (n - last == 1)
    return false;
  reverse(p.begin() + last, p.end());
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    if (solve()) {
      cout << "YES\n";
      for (int x : p)
        cout << x << " ";
      cout << "\n";
    } else
      cout << "NO\n";
  }
  return 0;
}