#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=100005,mod=1e9+7;
ll a[maxn],fac[maxn],inv[maxn];
ll ksm(ll a,ll b) {
	ll res=1;
	while(b) {
		if(b&1)res=(res*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}
void init(int n) {
	fac[0]=1;
	for(int i=1; i<=n; i++)fac[i]=(fac[i-1]*i)%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1; i>=0; i--)inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll n,ll m) {
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main( ) {
	int n;
	cin>>n;
	init(n);
	ll cnt=0;
	for(int i=0; i<n-1; i++) {
		int u,v;
		cin>>u>>v;
		a[u]++;
		a[v]++;
	}
	ll L,R;
	cin>>L>>R;
	if(L==1)cnt+=n;
	if(L<=2&&R>=2)cnt+=n-1;
	for(int i=1; i<=n; i++)for(int j=max(2ll,L-1); j<=min(R-1,a[i]); j++)cnt=(cnt+C(a[i],j))%mod;
	cout<<cnt<<"\n";
	return 0;
}
