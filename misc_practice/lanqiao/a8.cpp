#include<bits/stdc++.h>
using namespace std;
using ll= unsigned long long;
ll f[100];
const ll maxn=1e18;
int main( ) {
	ll x;
	cin>>x;

	if(x==1) {
		cout<<"0\n";
		return 0;
	}
	ll L=1,R=64;
	while(L<R) {
		ll mid=L+(R-L-1)/2+1;
		if(((mid-1)*1ull<<mid)+2>x)R=mid-1;
		else L=mid;
	}
	x-=((L-1)*1ull<<L)+2;
	ll cnt=L*(1ull<<(L-1)),len=L+1,n=x/len,a=(1ull<<L)+n;
	x-=n*len;

	if(n>0) {n--;
		ll m=__builtin_popcountll(n);
		ll w=1;
		for( w=1; w<=m; w++) {
			int pos=64-__builtin_clzll(n)-1;
			n^=1ull<<pos;
			cnt+=w*(1ull<<pos)+pos*(1ull<<(pos-1));
		}
		cnt+=w;
	}
	cnt+=__builtin_popcountll(a>>len-x);
	cout<<cnt<<"\n";
	return 0;
}
