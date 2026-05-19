#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    int n;
    cin >> n;
    cin >> s;
    if (is_sorted(s.begin(), s.end()))
      cout << "Bob\n";
    else {
      cout << "Alice\n";
      int cnt1 = count(s.begin(), s.end(), '1'), cnt0 = 0;
      vector<int> v;
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
          cnt0++;
          v.push_back(i + 1);
        } else
          cnt1--;
        if (cnt0 >= cnt1) {
          for (int j = i - 1; j >= 0; j--)
            if (s[j] == '1')
              v.push_back(j + 1);
          break;
        }
      }
      cout << v.size() << "\n";
      for (int i = (int)v.size() - 1; i >= 0; i--)
        cout << v[i] << " \n"[i == 0];
    }
  }
  return 0;
}