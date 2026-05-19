#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
bool solve() {
  int n;
  cin >> n;
  vi a(n);
  bool have_even = 0, have_odd = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1)
      have_odd = 1;
    else
      have_even = 1;
  }
  if (have_even && have_odd)
    return false;
  cout << (have_even ? 31 : 30) << "\n";
  for (int i = 29; i >= 0; i--)
    cout << (1 << i) << " ";
  if (have_even)
    cout << 1 << " ";
  cout << "\n";
  return true;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    if (!solve())
      cout << "-1\n";
  }
  return 0;
}