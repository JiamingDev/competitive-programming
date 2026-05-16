#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
int main( )
{int n,m,x;
cin>>n>>m>>x;
int cnt=0;
for(int i=0;i<n;i++){int t;cin>>t;x=((x+t)%m+m)%m;if(x==0)cnt++;
}
cout<<cnt<<"\n"; 
    return 0;
}
