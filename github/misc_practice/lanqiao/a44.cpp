#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+5;
vector<int>g[maxn];
int fa[maxn][20],dep[maxn],d[maxn][20],c[maxn];
void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	d[u][0]=1<<(c[u]-1);
	for(int i=1; i<=19; i++) {
		fa[u][i]=fa[fa[u][i-1]][i-1];
		d[u][i]=d[u][i-1]|d[fa[u][i-1]][i-1];
	}
	for(auto v:g[u])if(v!=f)dfs(v,u);
}
int lca(int u,int v) {
	int res=0;
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19; i>=0; i--)if(dep[fa[u][i]]>=dep[v]) {
			res|=d[u][i];
			u=fa[u][i];
		}
	if(u==v)return __builtin_popcount(res|d[v][0]);
	for(int i=19; i>=0; i--)if(fa[u][i]!=fa[v][i]) {
			res|=d[u][i];
			res|=d[v][i];
			u=fa[u][i];
			v=fa[v][i];
		}
	return __builtin_popcount(res|d[u][0]|d[v][0]|d[fa[u][0]][0]);
}

int main( ) {
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)cin>>c[i];

	for(int i=0;i<n-1;i++){int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);
	}
		dfs(1,0);
	for(int i=0;i<q;i++){int u,v;cin>>u>>v;cout<<lca(u,v)<<"\n";
	}
	return 0;
}
