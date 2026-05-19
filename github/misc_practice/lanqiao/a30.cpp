#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int>G[2];
int main( ) {
	int n;
	cin>>n;
	vector<int>a(n+1),b(n+1),suma(n+1),sumb(n+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		suma[i]=suma[i-1]+a[i];
	}
	G[0].push_back(0);

	for(int i=1; i<=n; i++) {
		cin>>b[i];
		sumb[i]=sumb[i-1]^b[i];
		G[sumb[i]].push_back(i);
	}
	int res=0;
	for(int i=1; i<G[0].size(); i++) {
		int l=0,r=i;
		
		while(l<r) {
			int mid=l+(r-l)/2;
			if(suma[G[0][i]]-suma[G[0][mid]]>1)l=mid+1;
			else r=mid;
			}
			res=max(res,G[0][i]-G[0][l]);
		l=0,r=lower_bound(G[1].begin(),G[1].end(),G[0][i])-G[1].begin()-1;
		if(r<0)continue;
		while(l<r){int mid=l+r>>1;if(suma[G[0][i]]-suma[G[1][mid]]>2)l=mid+1;else r=mid;
		}
		if(suma[G[0][i]]-suma[G[1][l]]==2)
		res=max(res,G[0][i]-G[1][l]);
	}
	for(int i=1; i<G[1].size(); i++) {
		int l=0,r=i;
		
		while(l<r) {
			int mid=l+(r-l)/2;
			if(suma[G[1][i]]-suma[G[1][mid]]>1)l=mid+1;
			else r=mid;
			}
			res=max(res,G[1][i]-G[1][l]);
		l=0,r=lower_bound(G[0].begin(),G[0].end(),G[1][i])-G[0].begin()-1;
		if(r<0)continue;
		while(l<r){int mid=l+r>>1;if(suma[G[1][i]]-suma[G[0][mid]]>2)l=mid+1;else r=mid;
		}
		if(suma[G[1][i]]-suma[G[0][l]]==2)
		res=max(res,G[1][i]-G[0][l]);
	}
	cout<<res<<"\n";
	return 0;
}
