#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n , sum_b , a[N] , b[N], sum_a[N];
vector<int>G[2];
signed main(){
    G[0].push_back(-1);
    G[1].push_back(-1);
    G[0].push_back(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i] , sum_a[i] = sum_a[i - 1] + a[i];
    for(int i = 1 ; i <= n ; i ++) {
        cin >> b[i] , sum_b ^= b[i];
        G[sum_b].push_back(i);
    }
    G[0].push_back(n + 1);
    G[1].push_back(n + 1);
    int ans = -1;

    for(int i = 2 ; i < G[0].size() - 1 ; i ++) {
      
        int L = 1 , R = i , res = 0;
        while(L <= R) {
            int mid = (L + R) >> 1;
            int F = sum_a[G[0][i]] - sum_a[G[0][mid]];
            if(F <= 1) R = mid - 1 , res = G[0][i] - G[0][mid];
            else L = mid + 1;
        }
        ans = max(ans , res);
      
        L = 1 , R = lower_bound(G[1].begin(), G[1].end(), G[0][i]) - G[1].begin() - 1 , res = 0;
        while(L <= R) {
          int mid = (L + R) >> 1;
          int F = sum_a[G[0][i]] - sum_a[G[1][mid]];
          if(F <= 2) {
            R = mid - 1;
            if(F == 2) res = G[0][i] - G[1][mid]; 
          } else L = mid + 1;
        }
        ans = max(ans , res);

    }
    for(int i = 1 ; i < G[1].size() - 1 ; i ++) {

        int L = 1 , R = i , res = 0;
        while(L <= R) {
            int mid = (L + R) >> 1;
            if(sum_a[G[1][i]] - sum_a[G[1][mid]] <= 1) R = mid - 1 , res = G[1][i] - G[1][mid];
            else L = mid + 1;
        }
        ans = max(ans , res);

        L = 1 , R = lower_bound(G[0].begin(), G[0].end(), G[1][i]) - G[0].begin() - 1 , res = 0;
        while(L <= R) {
          int mid = (L + R) >> 1;
          int F = sum_a[G[1][i]] - sum_a[G[0][mid]];
          if(F <= 2) {
            R = mid - 1;
            if(F == 2) res = G[1][i] - G[0][mid]; 
          } else L = mid + 1;
        }
        ans = max(ans , res);
    }
    cout << ans << '\n';
    return 0;
}
