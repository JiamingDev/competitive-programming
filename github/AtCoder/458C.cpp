#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == 'C')
      ans += min(i, (int)s.size() - i - 1) + 1;
  cout << ans;
  return 0;
}