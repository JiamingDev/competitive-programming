#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=200005;
int a[maxn],b[maxn];
int ans=0;
vector<pair<int,int>>g1[maxn],g2[maxn];
void dfs(int u,int v,int fu,int fv,int dep) {
	ans=max(ans,dep);
	int i=0,j=0;
	while(i<g1[u].size()&&j<g2[v].size()) {
		int val1=g1[u][i].first,val2=g2[v][j].first,idx1=g1[u][i].second,idx2=g2[v][j].second;
		if(idx1==fu) {
			i++;
			continue;
		}
		if(idx2==fv) {
			j++;
			continue;
		}
		if(val1==val2){dfs(idx1,idx2,u,v,dep+1);i++;j++;
		}
		else if(val1<val2)i++;
		else j++;
	}
}
int main( ) {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=m; i++)cin>>b[i];
	for(int i=0; i<n-1; i++) {
		int u,v;
		cin>>u>>v;
		g1[u].push_back({a[v],v});
		g1[v].push_back({a[u],u});
	}
	for(int i=0; i<m-1; i++) {
		int u,v;
		cin>>u>>v;
		g2[u].push_back({b[v],v});
		g2[v].push_back({b[u],u});
	}
	for(int i=1; i<=n; i++)sort(g1[i].begin(),g1[i].end());
	for(int i=1; i<=m; i++)sort(g2[i].begin(),g2[i].end());
	if(a[1]!=b[1]) {
		cout<<"0\n";
		return 0;
	}
	dfs(1,1,0,0,1);
	cout<<ans<<"\n";
	return 0;
}
