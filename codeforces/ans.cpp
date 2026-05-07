#include <bits/stdc++.h>
using namespace std;
#define ll long long
void read(auto &x) {
  char ch = getchar();
  x = 0;
  ll f = 1;
  while (isdigit(ch) == 0 && ch != '-')
    ch = getchar();
  if (ch == '-')
    f = -1, ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
int a[200005];
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    swap(a[1], a[n]);
    sort(a + 2, a + 1 + n);
    vector<int> v1, v2;
    for (int i = 2; i <= n; i++) {
      if (v1.size() && v1.back() == a[i])
        v2.push_back(a[i]);
      else
        v1.push_back(a[i]);
    }
    int t = 1;
    for (int i = 0; i < v1.size(); i++)
      a[++t] = v1[i];
    for (int i = 0; i < v2.size(); i++)
      a[++t] = v2[i];
    ll ans = 0;
    mp.clear();
    int nw = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
      mp[a[i]]++;
      mx = max(mx, a[i]);
      while (mp[nw])
        ++nw;
      ans += mx + nw;
    }
    cout << ans << '\n';
  }
  return 0;
}