#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vi v(4);
  for (int i = 0; i < 4; i++)
    cin >> v[i];
  sort(all(v));
  int last = 1;
  for (int x : v)
    if (x != last++) {
      cout << last - 1;
      return 0;
    }
  cout << 5;
  return 0;
}