#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 55;
const double eps = 1e-9;
int n, idx, idx2;
struct point {
  double x, y, z, vx, vy, vz;
  void read() {
    cin >> x >> y >> z >> vx >> vy >> vz;
  }
} p[maxn];
struct segment {
  double a, b, c;
  int u, v;
  bool operator<(const segment &b) const {
    return c < b.c;
  }
} seg[maxn * maxn];
struct event {
  double t;
  int olds, news;
  bool operator<(const event &b) const {
    return t < b.t;
  }
} eve[maxn * maxn * maxn * maxn / 4];
double sqr(double x) {
  return x * x;
}
void makesegments() {
  idx = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      seg[idx].a = sqr(p[i].vx - p[j].vx) + sqr(p[i].vy - p[j].vy) + sqr(p[i].vz - p[j].vz);
      seg[idx].b = 2 * ((p[i].vx - p[j].vx) * (p[i].x - p[j].x) + (p[i].vy - p[j].vy) * (p[i].y - p[j].y) + (p[i].vz - p[j].vz) * (p[i].z - p[j].z));
      seg[idx].c = sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y) + sqr(p[i].z - p[j].z);
      seg[idx].u = i, seg[idx].v = j;
      idx++;
    }
  sort(seg, seg + idx);
}
void makeevents() {
  idx2 = 0;
  for (int i = 0; i < idx; i++)
    for (int j = i + 1; j < idx; j++) {
      int s1 = i, s2 = j;
      double a = seg[i].a - seg[j].a, b = seg[i].b - seg[j].b, c = seg[i].c - seg[j].c;
      if (abs(a) < eps) {
        if (abs(b) < eps)
          continue;
        if (b < 0) {
          swap(s1, s2);
          b = -b, c = -c;
        }
        if (c > -eps)
          continue;
        eve[idx2++] = {-c / b, s1, s2};
      } else {
        if (a < 0) {
          swap(s1, s2);
          a = -a;
          b = -b;
          c = -c;
        }
        double delta = sqr(b) - 4 * a * c;
        if (delta < eps)
          continue;
        double t1 = (-b - sqrt(delta)) / (2 * a), t2 = (-b + sqrt(delta)) / (2 * a);
        if (t1 > 0)
          eve[idx2++] = {t1, s2, s1};
        if (t2 > 0)
          eve[idx2++] = {t2, s1, s2};
      }
    }
  sort(eve, eve + idx2);
}
int ans, fa[maxn];
int findset(int u) {
  return fa[u] == u ? u : fa[u] = findset(fa[u]);
}
void init() {
  for (int i = 0; i < n; i++)
    fa[i] = i;
}
int e[maxn], pos[maxn * maxn];
void solve() {
  ans = 1;
  int cnt = 0;
  memset(pos, 0, sizeof(pos));
  init();
  for (int i = 0; i < idx; i++) {
    int u = findset(seg[i].u), v = findset(seg[i].v);
    if (u != v) {
      fa[u] = v;
      e[++cnt] = i;
      pos[i] = cnt;
      if (cnt == n - 1)
        break;
    }
  }
  for (int i = 0; i < idx2; i++) {
    int sega = eve[i].olds, segb = eve[i].news;
    if (pos[sega] && !pos[segb]) {
      init();
      int oldpos = pos[sega];
      for (int j = 1; j <= n - 1; j++)
        if (j != oldpos) {
          int u = findset(seg[e[j]].u), v = findset(seg[e[j]].v);
          fa[u] = v;
        }
      int u = findset(seg[segb].u), v = findset(seg[segb].v);
      if (u != v) {
        ans++;
        e[oldpos] = segb;
        pos[segb] = oldpos;
        pos[sega] = 0;
      }
    }
  }
}
int main() {
  int kase = 0;
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      p[i].read();
    makesegments();
    makeevents();
    solve();
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}