#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int a[4];
struct Matrix {
  int c[6][6];
  Matrix() {
    memset(c, 0, sizeof(c));
  }
} res, t[4], cirt;
Matrix operator*(Matrix &a, Matrix &b) {
  Matrix t;
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      for (int k = 0; k < 6; k++) {
        t.c[i][j] = (t.c[i][j] + a.c[i][k] * b.c[k][j]) % mod;
      }
  return t;
}
void ksm(int k) {
  while (k) {
    if (k & 1)
      res = res * cirt;
    cirt = cirt * cirt;
    k >>= 1;
  }
}
signed main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < 5; i++)
    t[1].c[i][i + 1] = 1;
  t[1].c[5][5] = 1;
  for (int i = 1; i < 6; i++)
    t[2].c[i][i - 1] = 1;
  t[2].c[0][1] = 1;
  for (int i = 1; i < 5; i++)
    t[3].c[i + 1][i] = t[3].c[i - 1][i] = 1;
  t[3].c[1][0] = t[3].c[4][5] = t[3].c[5][5] = 1;
  for (int i = 0; i < 6; i++)
    cirt.c[i][i] = 1;
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
    cirt = cirt * t[a[i]];
  }
  res.c[0][k] = 1;
  ksm(n / 4);
  for (int i = 0; i < n - n / 4 * 4; i++)
    res = res * t[a[i]];
  int ans = 0;
  for (int i = 0; i < 6; i++)
    ans = (ans + res.c[0][i]) % mod;
  cout << ans << "\n";
  return 0;
}