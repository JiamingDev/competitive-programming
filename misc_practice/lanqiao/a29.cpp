#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int d[100005][2];
int main( ) {
	int n;
	cin>>n;
	vector<int>a(n+1),b(n+1),suma(n+1),sumb(n+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		suma[i]=suma[i-1]+a[i];
	}

	memset(d,-1,sizeof(d));
	d[0][0]=0;
	for(int i=1; i<=n; i++) {
		cin>>b[i];
		sumb[i]=sumb[i-1]^b[i];
		if(d[suma[i]][sumb[i]]==-1)d[suma[i]][sumb[i]]=i;
	}
	int res=0;
	for(int i=1; i<=n; i++) {
		int idx=d[suma[i]][sumb[i]];
		if(idx!=-1&&idx<=i)res=max(res,i-idx);
		if(suma[i]) {
			idx=d[suma[i]-1][sumb[i]];
			if(idx!=-1&&idx<=i)res=max(res,i-idx);
		}
		if(suma[i]>=2) {
			idx=d[suma[i]-2][sumb[i]^1];
			if(idx!=-1&&idx<=i)res=max(res,i-idx);
		}
	}
	
	cout<<res<<"\n";
	return 0;
}
