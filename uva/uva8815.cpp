#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int idx;
struct Node {
  bool is_var;
  int var;
  char op;
  int lef = -1, righ = -1;
};
vector<Node> tree;
int new_node() {
  tree.push_back({});
  return tree.size() - 1;
}
int pe();
int pt();
int pf();
int pe() {
  int node = pt();
  while (idx < s.size() && s[idx] == '|') {
    int pa = new_node();
    tree[pa].op = s[idx++];
    tree[pa].lef = node;
    int righ = pt();
    tree[pa].righ = righ;
    node = pa;
  }
  return node;
}
int pt() {
  int node = pf();
  while (idx < s.size() && s[idx] == '&') {
    int pa = new_node();
    tree[pa].op = s[idx++];
    tree[pa].lef = node;
    int righ = pf();
    tree[pa].righ = righ;
    node = pa;
  }
  return node;
}
int pf() {
  if (s[idx] == '(') {
    idx++;
    int node = pe();
    idx++;
    return node;
  } else {
    int pa = new_node();
    tree[pa].is_var = true;
    tree[pa].var = s[idx++] - '0';
    return pa;
  }
}
int ansd, ansr;
int eval(int u) {
  if (tree[u].is_var)
    return tree[u].var;
  char op = tree[u].op;
  int val = eval(tree[u].lef);
  if (val == 0 && op == '&') {
    ansd++;
    return 0;
  }
  if (val == 1 && op == '|') {
    ansr++;
    return 1;
  }
  if (op == '|')
    return val | eval(tree[u].righ);
  else
    return val & eval(tree[u].righ);
}
int main() {
  cin >> s;
  int root = pe();
  cout << eval(root) << "\n";
  cout << ansd << " " << ansr << "\n";
  return 0;
}