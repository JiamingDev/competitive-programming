#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
struct poly {
  int k, b;
  poly operator+(const poly &o) const {
    return {k + o.k, b + o.b};
  }
  poly operator-(const poly &o) const {
    return {k - o.k, b - o.b};
  }
  poly operator*(const poly &o) const {
    return {k * o.b + o.k * b, b * o.b};
  }
};
struct frac {
  poly n, d;
  frac operator+(const frac &b) const {
    return {n * b.d + b.n * d, d * b.d};
  }
  frac operator-(const frac &b) const {
    return {n * b.d - b.n * d, d * b.d};
  }
  frac operator*(const frac &b) const {
    return {n * b.n, d * b.d};
  }
  frac operator/(const frac &b) const {
    return {n * b.d, d * b.n};
  }
};
signed main() {
  string s;
  stack<frac> st;
  while (getline(cin, s)) {
    stringstream ss(s);
    if (s.empty())
      continue;
    char c;
    vector<poly> history;
    while (ss >> c) {
      if (isdigit(c))
        st.push({{0, c - '0'}, {0, 1}});
      else if (c == 'X')
        st.push({{1, 0}, {0, 1}});
      else {
        frac b = st.top();
        st.pop();
        frac a = st.top();
        st.pop();
        if (c == '+')
          st.push(a + b);
        else if (c == '-')
          st.push(a - b);
        else if (c == '*')
          st.push(a * b);
        else {
          st.push(a / b);
          history.push_back(b.n);
        }
      }
    }
    frac ans = st.top();
    poly n = ans.n, d = ans.d;
    st.pop();
    int k1 = n.k, b1 = n.b;
    if (k1 == 0) {
      if (b1 != 0)
        cout << "NONE\n";
      else
        cout << "MULTIPLE\n";
      continue;
    } else {
      bool error = false;
      for (auto x : history) {
        int b2 = x.b, k2 = x.k;
        if (-b1 * k2 + k1 * b2 == 0) {
          error = true;
          break;
        }
      }
      if (error) {
        cout << "NONE\n";
        continue;
      }
      b1 = -b1;
      if (k1 < 0) {
        k1 = -k1;
        b1 = -b1;
      }
      int g = __gcd(abs(b1), abs(k1));
      b1 /= g;
      k1 /= g;
      cout << "X = " << b1 << "/" << k1 << "\n";
    }
  }
  return 0;
}