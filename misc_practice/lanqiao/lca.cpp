#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+5;
vector<int>g[maxn];
int fa[maxn][20],dep[maxn];
void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1; i<=19; i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:g[u])if(v!=f)dfs(v,u);
}
int lca(int u,int v) {
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19; i>=0; i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return v;
	for(int i=19; i>=0; i--)if(fa[u][i]!=fa[v][i]) {
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
int main( ) {ios::sync_with_stdio(0);cin.tie(0);
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=0; i<n-1; i++) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(s,0);
	for(int i=0; i<m; i++) {
		int u,v;
		cin>>u>>v;
		cout<<lca(u,v)<<"\n";
	}
	return 0;
}
