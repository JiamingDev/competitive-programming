#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    if (n & 1 || count(s.begin(), s.end(), '(') != n / 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}