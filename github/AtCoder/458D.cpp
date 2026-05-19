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
  int x, n;
  cin >> x >> n;
  multiset<int> s;
  auto it = s.insert(x);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    s.insert(a);
    s.insert(b);
    if (a < *it && *it <= b) {
    } else if (*it <= a) {
      it++;
    } else if (*it > b) {
      it--;
    }
    cout << *it << "\n";
  }
  return 0;
}