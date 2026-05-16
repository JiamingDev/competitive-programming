#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int idx;
int pf() {
  int val = 0;
  while (idx < s.size() && isdigit(s[idx]))
    val = (val * 10 + s[idx++] - '0') % 10000;
  return val;
}
int pt() {
  int val = pf();
  while (idx < s.size() && s[idx] == '*') {
    idx++;
    val = val * pf() % 10000;
  }
  return val;
}
int pe() {
  int val = pt();
  while (s[idx] == '+') {
    idx++;
    val = (val + pt()) % 10000;
  }
  return val;
}
int main() {
  cin >> s;
  cout << pe();
  return 0;
}