#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {
	int T;
	cin>>T;
	while(T--) {int n,k;
		cin>>n>>k;
		if(k==1)cout<<n<<"\n";
		else cout<<(1<<(32-__builtin_clz(n)))-1<<"\n";
	}
	return 0;
}
