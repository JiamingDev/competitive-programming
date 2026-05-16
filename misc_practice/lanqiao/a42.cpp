#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>temp,v,p2,sum;
int k,T;
bool check(int n) {
	temp.resize(n+1);
	p2.resize(n+1);
	sum.resize(n+1);
	copy(v.begin(),v.begin()+n+1,temp.begin());
	sort(temp.begin()+1,temp.end());
	for(int i=1; i<temp.size(); i++) {
		p2[i]=p2[i-1]+temp[i]*temp[i];
		sum[i]=sum[i-1]+temp[i];
	}
	for(int i=k; i<temp.size(); i++)if((__int128)(p2[i]-p2[i-k])*k-(__int128)(sum[i]-sum[i-k])*(sum[i]-sum[i-k])<(__int128)T*k*k)return true;
	return false;
}
signed main( ) {
	int n;
	cin>>n>>k>>T;
	v.resize(n+1);
	for(int i=1; i<=n; i++)cin>>v[i];
	int l=1,r=n+1;
	while(l<r) {
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l==n+1) {
		cout<<-1;
		return 0;
	} else cout<<l;
	return 0;
}
