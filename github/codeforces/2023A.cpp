#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
struct node {
  int a, b;
  bool operator<(const node &o) const {
    return a + b < o.a + o.b;
  }
};
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].a >> v[i].b;
    }
    sort(all(v));
    for (auto [a, b] : v)
      cout << a << " " << b << " ";
    cout << "\n";
  }
  return 0;
}