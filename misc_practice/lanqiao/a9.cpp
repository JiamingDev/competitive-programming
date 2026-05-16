#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
int main( )
{string s;cin>>s;sort(s.begin(),s.end());
int pos=lower_bound(s.begin(),s.end(),s.back())-s.begin();
 cout<<s.substr(pos)<<"\n";
    return 0;
}
