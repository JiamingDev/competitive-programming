#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
struct Matrix {
  int c[101][101];
  Matrix() {
    memset(c, 0, sizeof(c));
  }
} A, res;
int n;
Matrix operator*(Matrix &a, Matrix &b) {
  Matrix t;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        t.c[i][j] = (t.c[i][j] + a.c[i][k] * b.c[k][j]) % mod;
  return t;
}
void quick_pow(int k) {
  for (int i = 1; i <= n; i++)
    res.c[i][i] = 1;
  while (k) {
    if (k & 1)
      res = res * A;
    A = A * A;
    k >>= 1;
  }
}
signed main() {
  int k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cin >> A.c[i][j];
  }
  quick_pow(k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cout << res.c[i][j] << " ";
    cout << "\n";
  }
  return 0;
}