#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;

int main( ) {
	int T;
	cin>>T;
	while(T--) {
		ll ans=0;
		ll L,R;
		cin>>L>>R;
		ll r=R-R%8,l=L+8-L%8,cn=max(0ll,(r-l)/8),cnt[8]={0};
		if(r>=l)
		{for(ll i=L; i<l; i++)cnt[i%8]++;
		for(ll i=r+1; i<=R; i++)cnt[i%8]++;
		}
		for(int i=1; i<8; i+=2)if((cnt[i]+cn)%2==0)ans=(ans+(cnt[i]+cn)/2%mod*((cnt[i]+cn-1)%mod))%mod;
		else ans=(ans+(cnt[i]+cn)%mod*((cnt[i]+cn-1)/2%mod))%mod;
		if(L<=2) {
			ans=(ans+R/4%mod)%mod;
			L=4;
		}
		if(L&1)L++;
		if(R&1)R--;
		if(((R-L)/2+1)%2==0)
		ans=(ans+((R-L)/2+1)/2%mod*((R-L)/2%mod)%mod)%mod;
		else ans=(ans+((R-L)/2+1)%mod*((R-L)/4%mod)%mod)%mod;
		cout<<ans<<"\n";
	}
	return 0;
}
