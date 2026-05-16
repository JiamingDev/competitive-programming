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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vi a(n);
    set<int> s;
    s.insert(0);
    int cnt = 0, sum = 0;
    for (int &x : a) {
      cin >> x;
      sum += x;
      if (s.count(sum)) {
        cnt++;
        s.clear();
        sum = 0;
        s.insert(0);
      } else
        s.insert(sum);
    }
    cout << cnt << "\n";
  }
  return 0;
}