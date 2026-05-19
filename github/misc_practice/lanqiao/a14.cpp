#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int d[32][2][32],one;
int a[32];
int dp(int len,int limit,int cnt) {
	if(len==0)return cnt==one;
	if(~d[len][limit][cnt])return d[len][limit][cnt];
	int res=0;
	int up=limit?a[len]:1;
	for(int i=0; i<=up; i++)res=(res+dp(len-1,limit&&i==a[len],cnt+i))%mod;
	return d[len][limit][cnt]=res;
}
ll ksm(int a,int b) {
	ll res=1;
	while(b) {
		if(b&1)res=res*a%mod;
		b>>=1;
		a=1ll*a*a%mod;
	}return res;
}
int main( ) {
	int n,k;
	cin>>n>>k;
	int len=32-__builtin_clz(k);
	int t=0;
	while(k) {
		a[++t]=k%2;
		k/=2;
	}
	ll ans=0;
	for(int i=0; i<=len; i++) {
		one=i;
		memset(d,-1,sizeof(d));
		ans=(ans+1ll*dp(len,1,0)*ksm(n,i))%mod;
	}cout<<ans<<"\n";
	return 0;
}
