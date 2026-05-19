#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> st;
    st.push_back(a.back());
    for (int i = n - 2; i >= 0; i--) {
      while (st.size() && a[i] + 1 == st.back())
        st.pop_back();
      st.push_back(a[i]);
    }
    cout << st.size() << "\n";
  }
  return 0;
}