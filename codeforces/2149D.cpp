#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = count(s.begin(), s.end(), 'a');
    int cntb = n - cnt;
    int ranka = (cnt + 1) / 2, rankb = cntb + 1 >> 1;
    long long posa = -1, posb = -1, needa = 0, needb = 0;
    for (int i = 0; i < n; i++)
      if (s[i] == 'a') {
        ranka--;
        if (!ranka)
          posa = i;
      } else {
        rankb--;
        if (!rankb)
          posb = i;
      }
    if (posa != -1) {
      cnt = 0;
      for (int i = posa - 1; i >= 0; i--)
        if (s[i] == 'a') {
          needa += abs(posa - i) - 1 - cnt;
          cnt++;
        }
      cnt = 0;
      for (int i = posa + 1; i < n; i++)
        if (s[i] == 'a') {
          needa += abs(posa - i) - 1 - cnt;
          cnt++;
        }
    }
    if (posb != -1) {
      cnt = 0;
      for (int i = posb - 1; i >= 0; i--)
        if (s[i] == 'b') {
          needb += abs(posb - i) - 1 - cnt;
          cnt++;
        }
      cnt = 0;
      for (int i = posb + 1; i < n; i++)
        if (s[i] == 'b') {
          needb += abs(posb - i) - 1 - cnt;
          cnt++;
        }
    }
    cout << min(needa, needb) << "\n";
  }
  return 0;
}