#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 5005;
const ll mod = 1000000000 + 7;
char s[5005];
ll c[maxn][maxn];
int main() {
  ll n;
  cin >> n;
  vector<int> pos;
  cin >> (s + 1);
  ll cnt = 0;
  for (int i = 1; s[i] != '\0'; i++)
    if (s[i] == '1') {
      cnt++;
      pos.push_back(i);
    }
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  ll ans = 0;
  for (int i = 0; i < pos.size(); i++) {
    int p = pos[i];
    for (int j = 1; j <= n - cnt + i + 1; j++) {
      ans =
          (ans + (c[p - 1][i] + c[n - p][n - i - 1]) % mod * abs(j - p) % mod) %
          mod;
    }
  }
  cout << ans;
  return 0;
}