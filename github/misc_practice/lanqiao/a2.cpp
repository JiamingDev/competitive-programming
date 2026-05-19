#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct bigint {
	vector<int>v= {1};
	static const int base=1e9;
	bigint operator*(ll a)const {
		bigint res=*this;
		ll c=0;
		for(int i=0; i<res.v.size()||c; i++) {
			if(i==res.v.size())res.v.push_back(0);
			ll temp=res.v[i]*a+c;
			c=temp/base;
			res.v[i]=temp%base;
		}
		while(res.v.size()>1&&res.v.back()==0)res.v.pop_back();
		return res;
	}
	 
	bool operator<=(const bigint&b)const {
		if(v.size()!=b.v.size())return v.size()<b.v.size();
		for(int i=(int)v.size()-1; i>=0; i--)if(v[i]!=b.v[i])return v[i]<b.v[i];
		return true;
	}

	ll operator /(const bigint&b)const {
		ll L=0,R=1ll<<32;
		while(L<R) {
			ll mid=L+(R-L)/2;
			if(*this<=b*mid)R=mid;
			else L=mid+1;
		}
		return L;
	}
} sum[100005];
int main() {
	int cnt = 0;
	int T;
	cin >> T;
	while (T--) {
		int o;
		ll x;
		cin >> o;
		if (o == 1) {
			cin >> x;
			cnt++;
			sum[cnt]=sum[cnt-1]*x;
		} else if(o==2){if(cnt>0)cnt--;
		}
		else {
			cin>>x;
			if(cnt<x)cout<<"ERROR\n";
			else if(sum[cnt-x]*(1ll<<32)<=sum[cnt])cout<<"OVERFLOW\n";
			else cout<<sum[cnt]/sum[cnt-x]<<"\n";
		}
	}
	// 请在此处编写代码...
	return 0;
}
