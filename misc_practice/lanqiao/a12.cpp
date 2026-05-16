#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
int main( )
{int n,m;cin>>n>>m;int s=1;ll res=0;
for(int i=0;i<n;i++){int l,r;cin>>l>>r;if(l>s){res+=l-s;s=l;
}else if(r<s){res+=s-r;s=r;
}
}cout<<res<<"\n";
    return 0;
}
