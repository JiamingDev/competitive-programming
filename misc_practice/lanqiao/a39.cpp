#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[1000005];
int main( ) {
	ll n,s;
	cin>>n>>s;
	ll sum=0;
	int maxc=0;
	for(int i=0; i<n; i++) {
		int p,c;
		cin>>p>>c;
		a[c]+=p;
		sum+=p;
		maxc=max(c,maxc);
	}
	ll res=0;
	for(int i=1; i<=maxc; i++) {
		res+=min(s,sum);
		if(a[i]!=0)sum-=a[i];
	}
	cout<<res<<"\n";
	return 0;
}
