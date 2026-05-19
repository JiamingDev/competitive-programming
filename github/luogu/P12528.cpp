#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  vector<double> pp(n);
  for (int i = 0; i < 1 << n; i++) {
    double a, b, p;
    cin >> a >> b;
    p = a * a + b * b;
    for (int j = 0; j < n; j++)
      if (1 << j & i)
        pp[j] += p;
  }
  for (int i = 0; i < n; i++)
    printf("%.8f %.8f\n", 1 - pp[i], pp[i]);
  return 0;
}