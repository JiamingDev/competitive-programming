#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353, maxn = 5e5 + 5;
struct edge {
  int v, w, ne;
} e[2 * maxn];
int tot = 1, h[maxn], t = 1, flag[maxn], mx = 0, s = 1, dep[maxn];
map<int, int> mp[maxn];
vi seq;
void add(int u, int v, int w) {
  e[++tot] = {v, w, h[u]};
  h[u] = tot;
  e[++tot] = {u, w, h[v]};
  h[v] = tot;
}
void dfs(int u, int f, int sum) {
  mp[u][sum] = u;
  dep[u] = dep[f] + 1;
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v != f) {
      dfs(v, u, sum ^ e[i].w);
      if (mp[v].size() > mp[u].size())
        swap(mp[u], mp[v]);
      for (auto [val, id] : mp[v]) {
        if (mp[u].count(val)) {
          int id2 = mp[u][val];
          int d1 = dep[id2] + dep[id] - 2 * dep[u];
          if (d1 > mx) {
            mx = d1;
            s = id;
            t = mp[u][val];
          }
          if (dep[id] > dep[mp[u][val]])
            mp[u][val] = id;
        } else
          mp[u][val] = id;
      }
      mp[v].clear();
    }
  }
}
void dfs2(int u, int f) {
  if (u == t) {
    flag[u] = 1;
    return;
  }
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v != f) {
      dfs2(v, u);
      if (flag[v])
        flag[u] = 1;
    }
  }
}
void dfs3(int u, int f) {
  seq.pb(u);
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v != f && !flag[v]) {
      dfs3(v, u);
      seq.pb(u);
    }
  }
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v != f && flag[v]) {
      dfs3(v, u);
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
  }
  dfs(1, 0, 0);
  dfs2(s, 0);
  dfs3(s, 0);
  cout << seq.size() << "\n";
  for (int x : seq)
    cout << x << " ";
  return 0;
}