#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int main( ) {
	int n;
	cin>>n;
	ll ans=1;
	int cnt=0;
	for(int i=0; i<n; i++) {int t;
		cin>>t;
		cnt+=t;
	}
	if(cnt&1) {
		ans=ans*(cnt+1)/2%mod;
		cnt--;
	}
	int k=cnt;
	for(int i=0; i<k; i++) {
		ans=ans*((cnt-1+2)/2)%mod;
		cnt--;
	}
	cout<<ans<<"\n";
	return 0;
}
