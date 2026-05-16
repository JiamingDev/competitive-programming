#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool check(int n) {
	int g[5][5]= {0};
	for(int i=0; i<5; i++)for(int j=0; j<5; j++)g[i][j]=n>>5*i+j&1;
	for(int i=0; i<5; i++) {
		int sumr=0,sumc=0;
		for(int j=0; j<5; j++) {
			sumr+=g[i][j];
			sumc+=g[j][i];
		}
		if(sumr==0||sumr==5||sumc==0||sumc==5)return false;
	}
	int c1=0,c2=0;
	for(int i=0;i<5;i++){c1+=g[i][i];c2+=g[i][4-i];
	}if(c1==0||c1==5||c2==0||c2==5)return false;
	return true;
}
int main( ) {
	ll cnt=0;
	for(int i=0; i<1<<25; i++)if(__builtin_popcount(i)==13&&check(i))cnt++;
	cout<<cnt;
	return 0;
}
