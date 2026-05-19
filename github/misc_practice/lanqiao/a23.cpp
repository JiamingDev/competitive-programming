#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=505;
#define int ll
struct dot {
	int x,y;
} u[maxn],v[maxn];

signed main( ) {
	set<pair<int,int>>s;
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>u[i].x>>u[i].y>>v[i].x>>v[i].y;
		if(u[i].x>v[i].x)swap(u[i],v[i]);
	}
	for(int i=0; i<n; i++)for(int j=i+1; j<n; j++) {
			int x1=u[i].x,y1=u[i].y,x2=v[i].x,y2=v[i].y,_x1=u[j].x,_y1=u[j].y,_x2=v[j].x,_y2=v[j].y;
			int num=x1*(y1-y2)*(_x1-_x2)+(_y1-y1)*(x1-x2)*(_x1-_x2)-_x1*(_y1-_y2)*(x1-x2),den=(_x1-_x2)*(y1-y2)-(x1-x2)*(_y1-_y2);
			if(den==0) {
				if((x1-_x1)*(y1-y2)-(x1-x2)*(y1-_y1)!=0)continue;
				int xx1=max(x1,_x1),xx2=min(x2,_x2),kn=y2-y1,kd=x2-x1;
				int gc=__gcd(abs(kn),kd);
				kd/=gc;
				kn/=gc;
				int yy1;
				int d;
				if(kd==0) {
					if(y1>y2)swap(y1,y2);
					if(_y1>_y2)swap(_y1,_y2);
					d=min(y2,_y2)-max(y1,_y1);
					yy1=max(y1,_y1);
					kn=1;
				} else {
					d=(xx2-xx1)/kd;
					if(xx1==x1)yy1=y1;
					else yy1=_y1;
				}
				for(int i=0; i<=d; i++)s.insert({xx1+i*kd,yy1+i*kn});
			} else {
				if(num%den!=0)continue;
				int x=num/den,num2,den2;
				if(x1!=x2) {
					num2=(y1-y2)*(x-x1)+y1*(x1-x2);
					den2=x1-x2;
				} else {
					num2=(_y1-_y2)*(x-_x1)+_y1*(_x1-_x2);
					den2=_x1-_x2;
				}
				if(num2%den2!=0)continue;
				int y=num2/den2;
				if(y1>y2)swap(y1,y2);
				if(_y1>_y2)swap(_y1,_y2);
				if(x>=max(x1,_x1)&&x<=min(x2,_x2)&&y>=max(y1,_y1)&&y<=min(y2,_y2))
					s.insert({x,y});
			}
		}
	cout<<s.size()<<"\n";
	return 0;
}
