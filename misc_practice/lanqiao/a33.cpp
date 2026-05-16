#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,T;
int a[100005],b[100005];
bool check(int t0) {
	int cnt=0,t=0;
	for(int i=0; i<T; i++) {
		int sumt=0;
		for(int i=cnt; i<n; i++) {
			if(sumt+t+a[i]>t0) {
				t=max(t-(t0-sumt),0);
				break;
			}
			sumt+=t+a[i];
			t=b[i];
			cnt++;
		}
	}
	if(cnt==n)return true;
	return false;
}
int main( ) {
	cin>>n>>T;
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=0; i<n; i++)cin>>b[i];
	int l=1,r=3601;
	while(l<r) {
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(r==3601)cout<<-1<<"\n";
	else
	cout<<l<<"\n";
	return 0;
}
