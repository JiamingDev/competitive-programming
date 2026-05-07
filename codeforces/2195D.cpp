#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 300005;
ll a[maxn], f[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> f[i];
    for (int i = 1; i < n - 1; i++)
      a[i] = (f[i - 1] + f[i + 1] - 2 * f[i]) / 2;
    ll sum = 0;
    for (int i = 1; i < n - 1; i++)
      sum += i * a[i];
    a[n - 1] = (f[0] - sum) / (n - 1);
    sum = 0;
    for (int i = 1; i < n - 1; i++)
      sum += a[i] * (n - 1 - i);
    a[0] = (f[n - 1] - sum) / (n - 1);
    for (int i = 0; i < n; i++)
      cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
  return 0;
}