#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
int b[100005],pos[100005],p[100005];
ll cnt;
void merge(int l,int r){if(l>=r)return;int mid=l+(r-l)/2;
merge(l,mid);merge(mid+1,r);
int i=l,j=mid+1,k=l;
while(i<=mid&&j<=r)if(p[i]<=p[j])b[k++]=p[i++];
else b[k++]=p[j++],cnt+=mid-i+1;
while(i<=mid)b[k++]=p[i++];
while(j<=r)b[k++]=p[j++];
copy(b+l,b+k,p+l);
}
int main( )
{int n;cin>>n;
for(int i=0;i<n;i++){int t;cin>>t;pos[t]=i;
}
for(int i=0;i<n;i++){int t;cin>>t;p[i]=pos[t];
} 
merge(0,n-1);
cout<<cnt<<"\n";
    return 0;
}
