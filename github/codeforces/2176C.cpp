#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (t & 1)
        odd.push_back(t);
      else
        even.push_back(t);
    }
    int mx, cnt = odd.size();
    if (!odd.empty())
      mx = *max_element(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    reverse(even.begin(), even.end());
    vector<int> sume(even.size() + 1);
    for (int i = 0; i < even.size(); i++)
      sume[i + 1] = sume[i] + even[i];
    int x = even.size();
    if (cnt == 0)
      for (int k = 1; k <= n; k++)
        cout << "0 ";
    else {
      for (int k = 1; k <= n; k++)
        if (x + 1 >= k)
          cout << mx + sume[k - 1] << " ";
        else {
          int tk = k;
          if ((cnt - 1) / 2 * 2 >= tk - x - 1) {
            if ((tk - x - 1) % 2 == 0)
              tk = x + 1;
            else
              tk = x;
            if (tk)
              cout << mx + sume[tk - 1] << " ";
            else
              cout << "0 ";
          } else
            cout << "0 ";
        }
    }
    cout << "\n";
  }
  return 0;
}