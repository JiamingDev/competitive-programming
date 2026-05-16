#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[100005];
int main( ) {
	int n;
	cin>>n;
	int res=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(a[i]==0&&((i-1>=0&&a[i-1]==0)||(i-2>=0&&a[i-2]==0))) {
			a[i]=1;
			res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}
