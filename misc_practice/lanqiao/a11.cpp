#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {
	int n;
	cin>>n;
	vector<int>v1(n),v2;
	for(int i=0; i<n; i++)cin>>v1[i];
	sort(v1.begin(),v1.end());
	ll res=0;
	for(int i=0; i<n; i++) {
		int t;
		cin>>t;
		int l=i,r=n;
		while(l<r){int mid=r+l>>1;
		if(v1[mid]>t)r=mid;
		else l=mid+1; 
		}
	
		res+=n-l;
	}
	cout<<res<<"\n";
	return 0;
}
