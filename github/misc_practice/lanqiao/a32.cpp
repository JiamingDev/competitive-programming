#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3005;
char a[maxn][maxn];
int L[maxn][maxn],R[maxn][maxn],U[maxn][maxn],D[maxn][maxn];
void print(__int128 t) {
	if(t==0) {
		cout<<"0\n";
		return ;
	}
	vector<int>v;
	while(t) {
		v.push_back(t%10);
		t/=10;
	}
	for(int i=v.size()-1; i>=0; i--)cout<<v[i];
	cout<<"\n";
}
int main( ) {
	ll n,m;
	cin>>n>>m;
	__int128 cnt1=0,cnth=0,cntv=0,cnthv=0,cnt=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i]+1;
		a[i][0]=a[i][m+1]='0';
	}
	for(int j=0; j<=m+1; j++)a[n+1][j]='0';
	for(int i=1; i<=n+1; i++)for(int j=1; j<=m+1; j++)if(a[i][j]=='1') {
				cnt1++;
				L[i][j]=L[i][j-1]+1;
				U[i][j]=U[i-1][j]+1;
			} else {
				if(a[i][j-1]=='1') {
					ll l=1ll*(L[i][j-1]+1)*(L[i][j-1])/2;
					cnt+=l;
					ll LL=L[i][j-1];
					cnth+=l*l-(LL+2)*(LL+1)*LL*(LL-1)/12;
				}
				if(a[i-1][j]=='1') {
					ll u=1ll*(U[i-1][j]+1)*U[i-1][j]/2;
					cnt+=u;
					ll uu=U[i-1][j];
					cntv+=u*u-(uu+2)*(uu+1)*uu*(uu-1)/12;
				}
			}
	cnt-=cnt1;
	for(int i=n; i>=0; i--)for(int j=m; j>=0; j--)if(a[i][j]=='1') {
				R[i][j]=R[i][j+1]+1;
				D[i][j]=D[i+1][j]+1;
			}
	for(int i=1; i<=n; i++ )for(int j=1; j<=m; j++)if(a[i][j]=='1')cnthv+=2ll*(L[i][j]*R[i][j]-1)*(U[i][j]*D[i][j]-1);
	print(cnt*cnt-cnth-cntv-cnthv+cnt1);
	return 0;
}
