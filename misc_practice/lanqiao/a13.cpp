#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
int main( )
{int n,k;cin>>n>>k;

vector<int>v(n);
for(int i=0;i<n;i++){cin>>v[i];v[i]%=k;
}
sort(v.begin(),v.end());
int minv=v[n-1]-v[0];
for(int i=0;i<n-1;i++)minv=min(minv,v[i]+k-v[i+1]);
cout<<minv;
    return 0;
}
