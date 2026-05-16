#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
const int maxn=1e6+1;
char s[maxn];
int main( )
{cin>>s;int n=strlen(s);
int cnt=0,res=n;vector<int>pos;
for(int i=0;i<n;i++)if(s[i]=='B'){pos.push_back(i);cnt++;
}
for(int i=0;i<pos[cnt-1];i++)if(s[i]=='A'){res-=2;cnt--;
}
cout<<res<<"\n";
    return 0;
}
