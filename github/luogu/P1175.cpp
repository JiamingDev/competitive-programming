#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int idx;
struct Node {
  bool is_val;
  ll val;
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
int pp();
int pf();
int pe() {
  int node = pt();
  while (idx < s.size() && (s[idx] == '+' || s[idx] == '-')) {
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
  int node = pp();
  while (idx < s.size() && (s[idx] == '*' || s[idx] == '/')) {
    int pa = new_node();
    tree[pa].op = s[idx++];
    tree[pa].lef = node;
    int righ = pp();
    tree[pa].righ = righ;
    node = pa;
  }
  return node;
}
int pp() {
  int node = pf();
  if (idx < s.size() && s[idx] == '^') {
    int pa = new_node();
    tree[pa].op = s[idx++];
    tree[pa].lef = node;
    int righ = pp();
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
    tree[pa].is_val = true;
    tree[pa].val = s[idx++] - '0';
    return pa;
  }
}
struct token {
  bool is_val;
  ll val;
  char op;
};
vector<token> order;
void p_order(int u) {
  if (u == -1)
    return;
  p_order(tree[u].lef);
  p_order(tree[u].righ);
  if (tree[u].is_val)
    order.push_back({true, tree[u].val});
  else
    order.push_back({false, 0, tree[u].op});
}
void print() {
  for (int i = 0; i < order.size(); i++) {
    auto x = order[i];
    if (x.is_val)
      cout << x.val;
    else
      cout << x.op;
    if (i + 1 != order.size())
      cout << " ";
  }
  cout << "\n";
}
ll power(ll a, ll b) {
  ll res = 1;
  for (int i = 0; i < b; i++)
    res *= a;
  return res;
}
void action() {
  print();
  int i = 0;
  while (order.size() > 1) {
    for (; i < order.size(); i++)
      if (!order[i].is_val) {
        char op = order[i].op;
        ll a = order[i - 2].val, b = order[i - 1].val, res = 0;
        if (op == '+')
          res = a + b;
        else if (op == '-')
          res = a - b;
        else if (op == '*')
          res = a * b;
        else if (op == '/')
          res = a / b;
        else if (op == '^')
          res = power(a, b);
        order[i - 2].val = res;
        order.erase(order.begin() + i - 1, order.begin() + i + 1);
        i = i - 1;
        break;
      }
    print();
  }
}
int main() {
  cin >> s;
  int root = pe();
  p_order(root);
  action();
  return 0;
}