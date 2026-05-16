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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n & 1) {
      if (n < 27)
        cout << -1 << "\n";
      else {
        cout << 1 << " ";
        for (int i = 2; i <= 5; i++)
          cout << i << " " << i << " ";
        cout << 1 << " ";
        cout << 6 << " ";
        for (int i = 7; i <= 13; i++)
          cout << i << " " << i << " ";
        cout << 1 << " ";
        cout << 6 << " ";
        for (int i = 1; i <= n / 2 - 13; i++)
          cout << i + 13 << " " << i + 13 << " ";
        cout << "\n";
      }
    } else {
      for (int i = 1; i <= n / 2; i++) {
        cout << i << " " << i << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}