#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> v = {0};
    while (n) {
      v.push_back(n % 10);
      n /= 10;
    }
    reverse(v.begin() + 1, v.end());
    vector<int> vj, vk;
    for (int i = 1; i <= max(j, k); i++) {
      if (j == i)
        vj = v;
      if (k == i)
        vk = v;
      next_permutation(v.begin() + 1, v.end());
    }
    int cnt = 0;
    for (int i = 1; i < v.size(); i++)
      if (vj[i] == vk[i])
        cnt++;
    cout << cnt << "A" << v.size() - 1 - cnt << "B\n";
  }
  return 0;
}