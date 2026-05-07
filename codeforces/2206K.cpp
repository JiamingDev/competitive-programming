#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = n / 4;
    vector<int> temp;
    while (l < r) {
      int mid = (l + r - 1 + 2) >> 1;
      temp = cnt;
      int sum = s.size();
      int cnt1 = min(temp[0], temp[3]), lef = mid;
      if (cnt1 >= mid)
        temp[0] -= mid, temp[3] -= mid, sum -= 2 * mid;
      else {
        temp[0] -= cnt1, temp[3] -= cnt1, lef -= cnt1, sum -= 2 * cnt1;
        int cnt4 = min(temp[0], temp[2]);
        if (cnt4 >= lef)
          temp[0] -= lef, temp[2] -= lef, sum -= 2 * lef, lef = 0;
        else {
          temp[0] -= cnt4, temp[2] -= cnt4, lef -= cnt4, sum -= 2 * cnt4;
          int cnt2 = min(temp[0], temp[1]);
          if (cnt2 >= lef)
            temp[0] -= lef, temp[1] -= lef, sum -= 2 * lef, lef = 0;
          else {
            temp[0] -= cnt2, temp[1] -= cnt2, lef -= cnt2, sum -= 2 * cnt2;
            if (temp[0]) {
              int cnt3 = temp[0] / 2;
              if (cnt3 >= lef)
                temp[0] -= 2 * lef, sum -= 2 * lef, lef = 0;
            } else if (temp[1]) {
              int cnt3 = temp[1] / 2;
              if (cnt3 >= lef)
                temp[1] -= 2 * lef, sum -= 2 * lef, lef = 0;
            }
            if (lef) {
              r = mid - 1;
              continue;
            }
          }
        }
      }
      if (sum - temp[3] < mid || sum / 2 < mid)
        r = mid - 1;
      else
        l = mid;
    }
    cout << l << "\n";
  }
  return 0;
}