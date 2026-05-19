#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int pre[100005],zero[100005];
int main( ) {
	vector<ll>v;
	int T;
	cin>>T;int last=-1;
	while(T--) {
		int o;
		cin>>o;
		
		if(o==1) {
			ll t;
			cin>>t;
			v.push_back(t);
			zero[v.size()]=zero[v.size()-1]+(t==0?1:0);
			if(t!=1) {
				pre[v.size()-1]=last;
				last=v.size()-1;
			}
		} else if(o==2){if(!v.empty()){v.pop_back();if(last==v.size())last=pre[last];
		} 
		}
		else {
			int y;
			cin>>y;
			if(v.size()<y) {
				cout<<"ERROR\n";
				continue;
			}
			if(zero[v.size()]-zero[v.size()-y]>0){cout<<0<<"\n";continue;
			}
			ll sum=1;int tlast=last;
			while(1) {
				if(v.size()-tlast<=y) {
					sum*=v[tlast];
					if(sum==0) {
						cout<<sum<<"\n";
						break;
					}
					if(sum>=1ll<<32) {
						cout<<"OVERFLOW\n";
						break;
					}
				} else {
					cout<<sum<<"\n";
					break;
				}
				tlast=pre[tlast];
			}
		}
	}
	return 0;
}
