#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int cnt[]= {13,1,2,3,5,4,4,2,2,2};
int day[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main( ) {int bas=0,book=0;
	for(int i=2000; i<=2024;i++)for(int j=1; j<=12;j++) {if(i==2024&&j>4)break;
			int t=0;
			int temp[13];
			copy(day,day+13,temp);
			if((i%4==0&&i%100!=0)||i%400==0)temp[2]++;
			for(int d=1; d<=temp[j]; d++) {if(i==2024&&j==4&&d>13)break;
				int sum=0;
				int y=i;
				while(y) {
					sum+=cnt[y%10];
					y/=10;
				}
				int mon=j;
				for(int k=0; k<2; k++) {
					sum+=cnt[mon%10];
					mon/=10;
				}
				int dd=d;
					for(int k=0; k<2; k++) {
					sum+=cnt[dd%10];
					dd/=10;
				}
				if(sum>50)bas++;
				else book++;
			}
		}
		cout<<bas<<" "<<book;
	return 0;
}
