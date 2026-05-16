#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {
	pair<int,int> a[3];
	for(int i=0; i<3; i++) {
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a,a+3);
	int res;
	if(a[0]==a[1]||a[1]==a[2]||a[1].second==1)res=0;
	else {
		res=min(a[1].first-a[0].first,a[2].first-a[1].first);
	}
	cout<<res<<"\n";
	return 0;
}
