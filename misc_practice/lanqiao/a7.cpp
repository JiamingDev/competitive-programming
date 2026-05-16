#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<int,pair<int,int>>mp;
int main( ) {
	int n;
	cin>>n;
	int last=0,cnt=0;
	for(int i=0; i<=n; i++) {
		int t;
		if(i<n)cin>>t;
		else t=0;
		if(t!=last) {
			auto&temp=mp[last];
			int &a=temp.first,&b=temp.second;
			if(a<cnt) {
				b=a;
				a=cnt;
			} else if(b<cnt)b=cnt;
			cnt=1;
			last=t;
		} else cnt++;
	}
	int ans=0;
	for(auto&temp:mp){int a=temp.first;pair<int,int>b=temp.second;ans=max(ans,a*(b.first+b.second));
	}
	cout<<ans<<"\n"; 
	return 0;
}
