#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1500;
int T = 1401, S = 1400;
struct edge {
  int u, v, c, ne;
} e[1000000];
int h[maxn], tot, mf[maxn], pre[maxn];
bool flow() {
  memset(mf, 0, sizeof(mf));
  mf[S] = 1e9;
  queue<int> q;
  q.push(S);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (e[i].c && mf[v] == 0) {
        mf[v] = min(mf[u], e[i].c);
        pre[v] = i;
        if (v == T)
          return true;
        q.push(v);
      }
    }
  }
  return false;
}
int maxf() {
  int ans = 0;
  while (flow()) {
    int v = T;
    while (v != S) {
      int i = pre[v];
      e[i].c -= mf[T];
      e[i ^ 1].c += mf[T];
      v = e[i ^ 1].v;
    }
    ans += mf[T];
  }
  return ans;
}
void add(int u, int v) {
  e[++tot] = {u, v, 1, h[u]};
  h[u] = tot;
  e[++tot] = {v, u, 0, h[v]};
  h[v] = tot;
}
int main() {
  int n, m;
  set<int> se;
  while (cin >> n >> m && n) {
    memset(h, 0, sizeof(h));
    tot = 1;
    se.clear();
    string s;
    for (int i = 0; i < m; i++) {
      cin >> s;
      size_t pos = s.find('*');
      if (pos == string::npos) {
        se.insert(stoi(s, 0, 2));
        continue;
      }
      s[pos] = '1';
      se.insert(stoi(s, 0, 2));
      s[pos] = '0';
      se.insert(stoi(s, 0, 2));
    }
    for (auto x : se)
      if (__builtin_popcount(x) % 2 == 0)
        add(x, T);
      else {
        add(S, x);
        for (auto y : se) {
          if (__builtin_popcount(x ^ y) == 1)
            add(x, y);
        }
      }
    cout << se.size() - maxf() << "\n";
  }
  return 0;
}