#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> a;
int maxa, mina;
int n;
bool check(int k) {
  int l1 = mina, l2 = mina + k, r1 = maxa - k, r2 = maxa;
  vector<int> v, v2(n);
  for (int i = 0; i < a.size(); i++) {
    int x = a[i];
    if (x >= l1 && x <= r1 || x >= l2 && x <= r2)
      v.push_back(x);
    else
      v2[i] = x;
  }
  sort(v.begin(), v.end());
  int idx = 0;
  for (int i = 0; i < n; i++)
    if (!v2[i])
      v2[i] = v[idx++];
  if (is_sorted(v2.begin(), v2.end()))
    return true;
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    if (is_sorted(a.begin(), a.end())) {
      cout << "-1\n";
      continue;
    }
    maxa = *max_element(a.begin(), a.end()), mina = *min_element(a.begin(), a.end());
    int l = 1, r = 1e9;
    int ans = 0;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (check(mid)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}