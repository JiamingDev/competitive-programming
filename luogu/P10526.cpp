#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
char str[N], op[5 * N];
int t[N][26], fa[5 * N], id[5 * N], sz[N], nxt[5 * N], idx, cur;
void add(char s[], int x) {
  int p = 0;
  for (int i = 0; s[i]; i++) {
    int j = s[i] - 'a';
    if (!t[p][j]) {
      t[p][j] = ++idx;
      sz[p]++;
      fa[idx] = p;
    }
    p = t[p][j];
  }
  id[p] = x;
}
void dfs(int u) {
  nxt[u] = u;
  if (sz[u] == 1) {
    for (int i = 0; i < 26; i++)
      if (t[u][i]) {
        dfs(t[u][i]);
        if (!id[u])
          nxt[u] = nxt[t[u][i]];
      }
  } else if (sz[u] >= 2) {
    for (int i = 0; i < 26; i++)
      if (t[u][i]) {
        dfs(t[u][i]);
      }
  }
}
signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> str;
    add(str, i);
  }
  dfs(0);
  cin >> op;
  for (int i = 0; op[i]; i++) {
    char c = op[i];
    if (c == 'E') {
      cout << (id[cur] ? id[cur] : -1) << " ";
      cur = 0;
    } else if (c == 'T') {
      if (nxt[cur])
        cur = nxt[cur];
    } else if (c == 'B') {
      cur = fa[cur];
    } else {
      if (cur > idx) {
        fa[cur + 1] = cur;
        cur++;
      } else if (t[cur][c - 'a']) {
        cur = t[cur][c - 'a'];
      } else {
        fa[idx + 1] = cur;
        cur = idx + 1;
      }
    }
  }
  return 0;
}