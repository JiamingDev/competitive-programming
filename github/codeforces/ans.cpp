#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
i128 strTo128(const string &s) {
  i128 x = 0;
  for (char c : s) {
    x = x * 10 + (c - '0');
  }
  return x;
}
void print128(i128 x) {
  if (x == 0) {
    cout << 0;
    return;
  }
  if (x < 0) {
    cout << '-';
    x = -x;
  }
  string s;
  while (x > 0) {
    s.push_back(char('0' + x % 10));
    x /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long a;
    int n;
    cin >> a >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
      cin >> d[i];
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    string S = to_string(a);
    int L = S.size();
    vector<i128> cands;
    auto addCandidate = [&](const string &s) {
      if (s.empty())
        return;
      // 多位数不能有前导 0
      if ((int)s.size() > 1 && s[0] == '0')
        return;
      cands.push_back(strTo128(s));
    };
    int minDigit = d.front();
    int maxDigit = d.back();
    // 1. 如果 0 是合法数字，那么 0 本身是一个候选
    if (binary_search(d.begin(), d.end(), 0)) {
      addCandidate("0");
    }
    // 2. 构造比 a 位数更短的最大合法数
    // 例如 a 是 4 位，那么 3 位最大合法数也可能是答案
    for (int len = 1; len < L; len++) {
      string s(len, char(maxDigit + '0'));
      addCandidate(s);
    }
    // 3. 构造比 a 位数更长的最小合法数
    // 第一位不能是 0，所以找最小的非零数字放第一位
    int minNonZero = -1;
    for (int x : d) {
      if (x != 0) {
        minNonZero = x;
        break;
      }
    }
    if (minNonZero != -1) {
      string s;
      s.push_back(char(minNonZero + '0'));
      // 后面全部填最小数字
      s += string(L, char(minDigit + '0'));
      addCandidate(s);
    }
    // 4. 枚举和 a 同位数的情况
    //
    // prefix 表示：目前为止和 a 完全相同的合法前缀
    string prefix;
    bool samePossible = true;
    for (int i = 0; i < L; i++) {
      int cur = S[i] - '0';
      // 情况 A：
      // 第 i 位第一次变大
      // 前面保持 prefix
      // 当前位选一个 > cur 的最小合法数字
      // 后面全部填最小合法数字
      auto itUp = upper_bound(d.begin(), d.end(), cur);
      if (itUp != d.end()) {
        int bigger = *itUp;
        string s = prefix;
        s.push_back(char(bigger + '0'));
        s += string(L - 1 - i, char(minDigit + '0'));
        addCandidate(s);
      }
      // 情况 B：
      // 第 i 位第一次变小
      // 前面保持 prefix
      // 当前位选一个 < cur 的最大合法数字
      // 后面全部填最大合法数字
      auto itLow = lower_bound(d.begin(), d.end(), cur);
      if (itLow != d.begin()) {
        --itLow;
        int smaller = *itLow;
        string s = prefix;
        s.push_back(char(smaller + '0'));
        s += string(L - 1 - i, char(maxDigit + '0'));
        addCandidate(s);
      }
      // 如果当前位 cur 本身合法，那么可以继续保持相等
      if (binary_search(d.begin(), d.end(), cur)) {
        prefix.push_back(char(cur + '0'));
      } else {
        // 当前位没法相等，后面不可能继续保持前缀相等了
        samePossible = false;
        break;
      }
    }
    // 如果 a 本身每一位都合法，那么 a 也是候选，答案可能是 0
    if (samePossible) {
      addCandidate(prefix);
    }
    // 5. 在所有候选数里找离 a 最近的
    i128 A = a;
    i128 ans = -1;
    for (i128 x : cands) {
      i128 diff = x > A ? x - A : A - x;
      if (ans == -1 || diff < ans) {
        ans = diff;
      }
    }
    print128(ans);
    cout << '\n';
  }
  return 0;
}