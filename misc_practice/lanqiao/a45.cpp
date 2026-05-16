#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int g[6][6];
bool check(int m) {set<string>sr,sc;
	for(int i=0; i<6; i++)for(int j=0; j<6; j++)g[i][j]=1ll<<(6*(5-i)+j);
	for(int i=0; i<6; i++) {string r,c;
		int suma=0,sumb=0;
		for(int j=0; j<6; j++) {r+='0'+g[i][j];c+='0'+g[j][i];
			suma+=g[i][j];
			sumb+=g[j][i];
			if(j<4&&(g[i][j]+g[i][j+1]+g[i][j+2]==3||g[i][j]+g[i][j+1]+g[i][j+2]==0))return false;
			if(i<4&&(g[i][j]+g[i+1][j]+g[i+2][j]==3||g[i][j]+g[i+1][j]+g[i+2][j]==0))return false;
		}
		if(sr.count(r))return false;
		else sr.insert(r);
		if(sc.count(c))return false;
		else sc.insert(c);
		if(suma!=3||sumb!=3)return false;
	}
	return true;
}
int main( ) {
	for(ll i=0; i<1ll<<36; i++)if(__builtin_popcount(i)==18&&check(i)) {
			cout<<i;
			return 0;
		}
	return 0;
}
