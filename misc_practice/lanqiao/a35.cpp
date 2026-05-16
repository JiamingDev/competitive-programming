#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
ll d[15][2024][2],cnt[2024];
int main( ) {
	ll x,y;
	cin>>x>>y;
	d[0][0][1]=1;
	string s=to_string(x);
	int n=s.size();
	for(int i=0; i<n; i++)for(int j=0; j<2024; j++)for(int limit=0; limit<2; limit++) {
				if(d[i][j][limit]==0)continue;
				int up=limit?s[i]-'0':9;
				for(int k=0;k<=up;k++)if(k!=2&&k!=4){int nj=(j*10+k)%2024,nlim=limit&&k==up;
				d[i+1][nj][nlim]+=d[i][j][limit];
				}
			}
			
	for(int i=0; i<2024;i++)cnt[i]=(d[n][i][0]+d[n][i][1])%mod;
	cnt[0]=(cnt[0]-1+mod)%mod;
	ll res=0;
	ll inv2=500000004,inv6=166666668;
	for(int i=0;i<2024;i++)for(int j=i;j<2024;j++){ll k=((y-i-j)%2024+2024)%2024;if(k<j)continue;
	if(i<j&&j<k)res=(res+cnt[i]*cnt[j]%mod*cnt[k]%mod)%mod;
	else if(i==j&&j<k&&cnt[i]>1)res=(res+cnt[i]*(cnt[i]-1)%mod*inv2%mod*cnt[k])%mod;
	else if(i<j&&j==k&&cnt[j]>1)res=(res+cnt[j]*(cnt[j]-1)%mod*inv2%mod*cnt[i])%mod;
	else if(cnt[i]>2)res=(res+cnt[j]*(cnt[j]-1)%mod*(cnt[j]-2)%mod*inv6)%mod;
	}cout<<res<<"\n";
		return 0;
}
