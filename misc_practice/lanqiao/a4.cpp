#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int>g[1005];
int W[1005];
bool dp[1005][1005];
void dfs(int u,int f) {	dp[u][0]=true;
	if(g[u].size()==1&&g[u][0]==f) {
	dp[u][W[u]]=true;
		return ;
	}

	for(int v:g[u])if(v!=f) {
			dfs(v,u);
			for(int w=W[u]; w>=0; w--)if(dp[u][w])
					for(int w2=0; w2+w<=W[u]; w2++)if(dp[v][w2])dp[u][w+w2]=true;
		}
}
int main( ) {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)cin>>W[i];
	for(int i=0; i<n-1; i++) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int w=W[1]; w>=0; w--)if(dp[1][w]) {
			cout<<w<<"\n";
			break;
		}
	return 0;
}
