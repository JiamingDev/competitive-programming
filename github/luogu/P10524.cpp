#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = (1 << 20) + 5;
int a[maxn], XOR[maxn], AND[maxn], OR[maxn];
signed main() {
  int n;
  cin >> n;
  for (int i = 0; i < 1 << n; i++) {
    cin >> a[i];
    XOR[0] += a[i] ^ i;
    AND[0] += a[i] & i;
    OR[0] += a[i] | i;
  }
  int mod = 1 << n;
  for (int k = 0; k < n; k++) {
    for (int i = 1; i <= 1 << k + 1; i++) {
      for (int j = 0; j < 1 << n - k; j++) {
        int t = (a[((j * (1 << k) - i) % mod + mod) % mod] >> k) & 1;
        int flag = j & 1;
        XOR[i] += ((t ^ flag) - (t ^ !flag)) * (1 << k);
        AND[i] += ((t & flag) - (t & !flag)) * (1 << k);
        OR[i] += ((t | flag) - (t | !flag)) * (1 << k);
      }
      for (int m = 1; m <= (1 << n - k - 1) - 1; m++) {
        int pos = (i + m * (1 << k + 1)) % mod;
        if (pos == 0)
          continue;
        XOR[pos] = XOR[i];
        AND[pos] = AND[i];
        OR[pos] = OR[i];
      }
    }
  }
  for (int i = 1; i < 1 << n; i++) {
    XOR[i] += XOR[i - 1];
    AND[i] += AND[i - 1];
    OR[i] += OR[i - 1];
  }
  int ansx = 0, ansa = 0, anso = 0;
  for (int i = 0; i < 1 << n; i++) {
    ansx = max(ansx, XOR[i]);
    ansa = max(ansa, AND[i]);
    anso = max(anso, OR[i]);
  }
  cout << ansx << " " << ansa << " " << anso;
  return 0;
}