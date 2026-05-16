#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[1005][1005],d[1005][1005];
int main( ) {
	int T;
	cin>>T;
	while(T--) {
		memset(d,0x3f,sizeof(d));
		int n;
		cin>>n;
		for(int i=1; i<=n; i++)for(int j=1; j<=n; j++) {
				int t;
				cin>>t;
				a[i][j]=t%2==0?0:1;
			}
		d[1][1]=(a[1][1]==0)*n;
		for(int i=1; i<=n; i++)for(int j=1; j<=n; j++) {
				d[i][j]=min(d[i][j],d[i-1][j]+(a[i][j]==0)*n);
				if(a[i][j-1]==a[i][j])d[i][j]=min(d[i][j],d[i][j-1]);
			}
			if(d[n][n]==0x3f3f3f3f)cout<<"No!\n";
			else cout<<d[n][n]<<"\n";
	}
	return 0;
}
