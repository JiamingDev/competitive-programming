#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ex, in;
    for (int i = 1; i <= n; i++) {
      int t;
      cin >> t;
      if (i <= x || i > y)
        ex.push_back(t);
      else
        in.push_back(t);
    }
    int pos = min_element(in.begin(), in.end()) - in.begin();
    if (ex.empty()) {
      for (int j = pos, k = 0; k < in.size(); j = (j + 1) % in.size(), k++)
        cout << in[j] << " ";
      cout << "\n";
      continue;
    } else if (in.empty()) {
      for (int x : ex)
        cout << x << " ";
      cout << "\n";
      continue;
    }
    bool ok = 0;
    for (int i = 0; i < ex.size(); i++) {
      if (!ok && ex[i] > in[pos]) {
        for (int j = pos, k = 0; k < in.size(); j = (j + 1) % in.size(), k++)
          cout << in[j] << " ";
        ok = 1;
      }
      cout << ex[i] << " ";
    }
    if (!ok) {
      for (int j = pos, k = 0; k < in.size(); j = (j + 1) % in.size(), k++)
        cout << in[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}