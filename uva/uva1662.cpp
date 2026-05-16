#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node {
  char op;
  bool is_var;
  char var;
  int lef = -1;
  int righ = -1;
};
vector<Node> tree;
int new_node() {
  tree.push_back({});
  return tree.size() - 1;
}
string s;
int idx;
int pe();
int pt();
int pf();
int pe() {
  int node = pt();
  while (idx < s.size() && (s[idx] == '+' || s[idx] == '-')) {
    int parent = new_node();
    tree[parent].op = s[idx++];
    tree[parent].lef = node;
    int righnode = pt();
    tree[parent].righ = righnode;
    node = parent;
  }
  return node;
}
int pt() {
  int node = pf();
  while (idx < s.size() && (s[idx] == '*' || s[idx] == '/')) {
    int parent = new_node();
    tree[parent].op = s[idx++];
    tree[parent].lef = node;
    int righnode = pf();
    tree[parent].righ = righnode;
    node = parent;
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
    int node = new_node();
    tree[node].is_var = true;
    tree[node].var = s[idx++];
    return node;
  }
}
void print(int u, bool flipe, bool flipt, char parent_op) {
  if (tree[u].is_var) {
    cout << tree[u].var;
    return;
  }
  char op = tree[u].op;
  bool need = false;
  if ((op == '+' || op == '-') && (parent_op == '*' || parent_op == '/'))
    need = true;
  if (need) {
    cout << '(';
    print(tree[u].lef, false, false, op);
    cout << tree[u].op;
    print(tree[u].righ, op == '-', op == '/', tree[u].op);
    cout << ")";
  } else {
    char out = op;
    if (op == '-' && flipe)
      out = '+';
    else if (op == '+' && flipe)
      out = '-';
    else if (op == '*' && flipt)
      out = '/';
    else if (op == '/' && flipt)
      out = '*';
    print(tree[u].lef, flipe, flipt, op);
    cout << out;
    bool nexflipe = (op == '-' ? !flipe : flipe);
    bool nexflipt = (op == '/' ? !flipt : flipt);
    print(tree[u].righ, nexflipe, nexflipt, op);
  }
}
int main() {
  while (cin >> s) {
    tree.clear();
    idx = 0;
    int root = pe();
    print(root, false, false, 0);
    cout << "\n";
  }
  return 0;
}