#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=300005;
struct edge {
	int to;
	int k,w;
};
double a[maxn];
vector<edge>e[maxn];
vector<edge>self[maxn];
double cost[maxn];
int main( ) {
	int n,m;cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	fill(cost+1,cost+n+1,1e15);
	for(int i=0; i<m; i++) {
		int  x,y, k,w;
		cin>>x>>y>>k>>w;
		if(k==0)cost[y]=min(1.0/w,cost[y]);
		else if(x==y)self[x].push_back({x,k,w});
		else e[x].push_back({y,k,w});
	}
	for(int i=1; i<=n; i++)if(cost[i]!=1e15) {
			for(auto t:self[i])if(t.w>t.k) {
					cost[i]=min(cost[i],1.0/(t.w-t.k));
				}
			for(auto x:e[i]) {
				int k=x.k,w=x.w;
				cost[x.to]=min(cost[x.to],1.0/w+(double)k/w*cost[i]);
			}
		}
	double ans=0;
	for(int i=1; i<=n; i++)ans=max(ans,a[i]/cost[i]);
	cout<<fixed<<setprecision(2)<<ans<<"\n";
	return 0;
}
