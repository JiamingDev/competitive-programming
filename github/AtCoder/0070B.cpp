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
  int n;
  cin >> n;
  int sum;
  cin >> sum;
  int cnt = 1;
  for (int i = 0; i < n - 1; i++) {
    int t;
    cin >> t;
    sum += t;
    if ((i + 2) * t >= sum)
      cnt++;
  }
  cout << cnt;
  return 0;
}