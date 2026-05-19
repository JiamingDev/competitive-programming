#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {
	int a,b,c;
	cin>>a>>b>>c;

	
	int cnt=b/c-(a-1+c)/c+1,last=b/c*c,fir=(a-1+c)/c*c;

	int res=0;

	if(cnt) {
		res+=(fir-1-a-1+2)/2;
		res+=(cnt-1)*((c-2-1+2)/2);
		res+=cnt;
		res+=(b-last-1-1+2)/2;
	}
	else res+=(b-a-1+2)/2;
	cout<<res<<"\n";
	return 0;
}

