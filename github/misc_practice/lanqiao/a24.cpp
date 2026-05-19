#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {
	int T;
	cin>>T>>ws;
	int pos=0;
	string res;
	while(T--) {
		string o;
	getline(cin,o);
		if(isdigit(o[0])) {
			int idx=o.find_first_of("hl");
			int d=stoi(o.substr(0,idx));
			if(o[idx]=='h')pos=max(0,pos-d);
			else pos=min((int)res.size(),pos+d);
		} else if(o[0]=='i') {
			string tar=o.substr(8,o.size()-9);
	
			res=res.substr(0,pos)+tar+res.substr(pos);
			pos+=tar.size();
		} else {
			int cnt=stoi(o.substr(1,o.size()-2));
			if(o.back()=='h') {
				res=res.substr(0,max(0,pos-cnt))+res.substr(pos);
				pos=max(0,pos-cnt);
			} else {
				res=res.substr(0,pos)+res.substr(min((int)res.size(),pos+cnt));
				
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}
