#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<queue<int>> q(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      int t;
      cin >> t;
      q[t].push(i);
      while (q[t].size() > t)
        q[t].pop();
      if (q[t].size() == t)
        dp[i] = max(dp[i - 1], dp[q[t].front() - 1] + t);
      else
        dp[i] = dp[i - 1];
    }
    cout << dp[n] << "\n";
  }
  return 0;
}