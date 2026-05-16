#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {ll cnt=0;
	for(int a=1; a<(1<<5)-1; a++)
		for(int b=1; b<(1<<5)-1; b++)
			for(int c=1; c<(1<<5)-1; c++)
				for(int d=1; d<(1<<5)-1; d++)
					for(int e=1; e<(1<<5)-1; e++) {
						if(__builtin_popcount(a)+__builtin_popcount(b)+__builtin_popcount(c)+__builtin_popcount(d)+__builtin_popcount(e)!=12)continue;
						if((a>>4&b>>3&c>>2&d>>1&e&1)==1||((a>>4|b>>3|c>>2|d>>1|e)&1)!=1||(a&b>>1&c>>2&d>>3&e>>4&1)==1||((a|b>>1|c>>2|d>>3|e>>4)&1)!=1)continue;
						bool ok=true;
						for(int i=0; i<5; i++)if((a>>i&b>>i&c>>i&d>>i&e>>i&1)==1||((a>>i|b>>i|c>>i|d>>i|e>>i)&1)!=1) {
								ok=false;
								break;
							}
						if(ok)cnt++;
					}
					cout<<cnt;
	return 0;
}
