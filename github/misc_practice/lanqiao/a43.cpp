#include<bits/stdc++.h>
using namespace std;
using i128=__int128;
const int maxn=100000;
using ll=long long;
ll cnt[maxn+5],f[maxn+5];
i128 cal(ll cn) {
	return cn*(cn-1);
}
void print(i128 t) {
	if(t==0) {
		cout<<"0\n";
		return;
	}
	string s;
	while(t) {
		s+='0'+t%10;
		t/=10;
	}
	reverse(s.begin(),s.end());
	cout<<s<<"\n";
}
int main( ) {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {int t;
		cin>>t;
		cnt[t]++;
	}
	i128 ans=0,sum=0;
	for(int i=1; i<=maxn; i++)if(cnt[i]) {
			for(int j=i*2; j<=maxn; j+=i)if(cnt[j]) {
					f[j]+=cnt[i];
					f[i]+=cnt[j];
					sum+=cnt[i]*cnt[j];
				}
			sum+=cnt[i]*(cnt[i]-1);
		}
	for(int i=1; i<=maxn; i++)if(cnt[i]) {
			if(cnt[i]>=2)ans+=cnt[i]*(cnt[i]-1)*(sum-(cal(cnt[i])-cal(cnt[i]-2))-f[i]*2);
			for(int j=i*2; j<=maxn; j+=i)if(cnt[j])ans+=cnt[i]*cnt[j]*(sum-2*(cnt[j]-1)-2*(cnt[i]-1)-f[i]-f[j]+1);
		}
	print(ans);
	return 0;
}
