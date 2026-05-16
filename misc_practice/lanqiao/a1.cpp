#include <bits/stdc++.h>
using namespace std;
const int maxn = 31650;
bool vis[maxn];
#define int long long
signed main() {
	int a, c;
	cin >> a >> c;
	vector<int>v;
	for (int i = 2; i <= maxn; i++)if (!vis[i]) {
			v.push_back(i);
			for (int j = i * i; j <= maxn; j += i) {
				vis[j] = true;
			}
		}
	int base = 100000;
	int l = a;
	int cnt = 0;
	while (1) {
		vector<int>ok(base, 1);
		int s = l + base - 1;
		for (int x : v) {
			for (int k = max(x,(l - 1) / x + 1); k <= s / x; k++) {
				ok[k * x - l] = 0;
			}
			if (l == 1) {
				ok[0] = 0;
			}
			// 请在此处编写代码...
		}
		for (int i = 0; i < base; i++)if (ok[i]) {
				cnt++;
				if (cnt == c) {
					cout << l + i;
					return 0;
				}
			}
		l=s+1;
	}
}
