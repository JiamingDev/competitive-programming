#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
int main( )
{int n;cin>>n;vector<int>v(n);ll res=0;
for(int i=0;i<n;i++){cin>>v[i];res+=v[i];
}
sort(v.begin(),v.end(),greater<int>());
for(int i=2;i<n;i+=3)res-=v[i];
cout<<res<<"\n";
    return 0;
}
