#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node {
	int x,y,r;
} a[5005];
double d[5005];
bool vis[5005];
double getd(int u,int v) {
	return max(0.0,sqrt((a[u].x-a[v].x)*(a[u].x-a[v].x)+(a[u].y-a[v].y)*(a[u].y-a[v].y))-a[u].r-a[v].r);
}
int main( ) {
	int n;
	cin>>n;
	for(int i=0; i<n; i++)cin>>a[i].x>>a[i].y>>a[i].r;
	fill(d,d+n,1e10);
	d[0]=0;
	
	double ans=0;
	for(int i=0; i<n; i++) {
		int u=-1;
		for(int j=0; j<n; j++)if(!vis[j]&&(u==-1||d[j]<d[u]))u=j;
		ans+=d[u];
		vis[u]=true;
		for(int v=0; v<n; v++)if(!vis[v]) {
				double t=getd(u,v);
				if(t<d[v])d[v]=t;
			}
	}
	cout<<fixed<<setprecision(2)<<ans<<"\n";
	return 0;
}
