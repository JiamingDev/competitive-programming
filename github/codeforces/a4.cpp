#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  list<int> l;
  vector<list<int>::iterator> v(n + 1);
  v[0] = l.insert(l.end(), 0);
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    v[i] = l.insert(next(v[t]), i); // 会破坏原来的v数组中指针的指向吗
  }
  for (int x : l) {
    if (x)
      cout << x << " ";
  }
  return 0;
}