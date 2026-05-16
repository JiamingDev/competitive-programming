#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1500;
int T = 1401, S = 1400;
struct edge {
  int u, v, c, ne;
} e[1000000];
int h[maxn], tot, match[maxn], vis[maxn];
bool dfs(int u) {
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (!vis[v]) {
      vis[v] = true;
      if (match[v] == -1 || dfs(match[v])) {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
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
      if (__builtin_popcount(x) % 2) {
        for (auto y : se) {
          if (__builtin_popcount(x ^ y) == 1)
            add(x, y);
        }
      }
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for (auto x : se)
      if (__builtin_popcount(x) % 2) {
        memset(vis, 0, sizeof(vis));
        if (dfs(x))
          cnt++;
      }
    cout << se.size() - cnt << "\n";
  }
  return 0;
}