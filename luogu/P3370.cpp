#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ull = unsigned long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353, N = 5e5 + 5;
ull get(char *s) {
  int n = strlen(s);
  ull h = 0, p = 131;
  for (int i = 0; i < n; i++)
    h = h * p + s[i];
  return h;
}
char s[1500];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> s;
    v[i] = get(s);
  }
  sort(all(v));
  cout << unique(v.begin(), v.end()) - v.begin();
  return 0;
}