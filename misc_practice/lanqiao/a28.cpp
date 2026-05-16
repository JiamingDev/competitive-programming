#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+5;
ll a[maxn],b[maxn];
pair<ll,ll>c[5*maxn];
int n,m,idx;
bool check(ll mid) {
	vector<int>diff(m+3);
	for(int i=1; i<=n; i++) {
		if(a[i]==0) {
			if(b[i]>=mid)diff[1]++;
		} else if(a[i]>0) {
			int l=1,r=m+1;
			while(l<r) {
				int mid2=l+r>>1;
				if(mid-b[i]<=a[i]*c[mid2].first)r=mid2;
				else l=mid2+1;
			}
			if(l<=m)
				diff[l]++;
		} else {
			int l=0,r=m;
			while(l<r) {
				int mid2=l+(r-l-1+2)/2;
				if(mid-b[i]<=a[i]*c[mid2].first)l=mid2;
				else r=mid2-1;
			}
			if(l>=1) {
				diff[1]++;
				diff[l+1]--;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		diff[i]+=diff[i-1];
		if(diff[i]>=n/2+1) {
			idx=c[i].second;
			return true;
		}
	}
	return false;
}
int main( ) {
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i]>>b[i];
	cin>>m;
	for(int i=1; i<=m; i++) {
		cin>>c[i].first;
		c[i].second=i;
	}
	sort(c+1,c+m+1);
	c[m+1].first=c[m].first+1;
	c[0].first=c[1].first-1;
	ll l=-2e18,r=2e18;
	while(l<r) {
		ll mid=l+(r-l-1+2)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<idx<<" "<<l<<"\n";
	return 0;
}
