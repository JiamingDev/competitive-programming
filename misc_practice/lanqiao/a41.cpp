#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=200005;
int a[maxn],b[maxn];
int ans=0;
map<int,int>g1[maxn],g2[maxn];
void dfs(int u,int v,int fu,int fv,int dep) {
	ans=max(ans,dep);
	for(auto x:g1[u])if(x.second!=fu&&g2[v].count(x.first)&&g2[v][x.first]!=fv)dfs(x.second,g2[v][x.first],u,v,dep+1);
}
int main( ) {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=m; i++)cin>>b[i];
	if(a[1]!=b[1]) {
		cout<<"0\n";
		return 0;
	}
	for(int i=0; i<n-1; i++) {
		int u,v;
		cin>>u>>v;
		g1[u][a[v]]=v;
		g1[v][a[u]]=u;
	}
	for(int i=0; i<m-1; i++) {
		int u,v;
		cin>>u>>v;
		g2[u][b[v]]=v;
		g2[v][b[u]]=u;
	}
	dfs(1,1,0,0,1);
	cout<<ans<<"\n";
	return 0;
}
