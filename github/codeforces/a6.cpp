#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  priority_queue<int> pq;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    pq.push(t);
  }
  while (pq.size()) {
    int w = pq.top();
    pq.pop();
    if (pq.empty()) {
      cout << w;
      return 0;
    }
    int w2 = pq.top();
    pq.pop();
    pq.push(w - w2);
  }
  return 0;
}