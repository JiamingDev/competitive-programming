#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long
using pii = pair<int, int>;
using vi = vector<int>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int n;
  cin >> s >> n;
  for (int i = n; i < s.size() - n; i++)
    cout << s[i];
  return 0;
}