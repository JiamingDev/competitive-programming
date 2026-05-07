#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> st;
    for (int i = 0; i < m; i++) {
      int t;
      cin >> t;
      st.insert(t);
    }
    int cur = 1;
    for (char c : s) {
      if (c == 'A')
        st.insert(++cur);
      else {
        auto it = st.upper_bound(cur);
        while (it != st.end() && *it == cur + 1) {
          it++;
          cur++;
        }
        st.insert(++cur);
        while (it != st.end() && *it == cur + 1) {
          it++;
          cur++;
        }
        cur++;
      }
    }
    cout << st.size() << "\n";
    for (auto x : st)
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}