#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1005;
struct circle {
	int x,y,r;
	bool operator<(const circle&b)const {
		return y+r<b.y+b.r;
	};
} c[maxn];

int main( ) {int ans=0;
	int n,w,h;
	cin>>n>>w>>h;
	for(int i=0; i<n; i++)cin>>c[i].x>>c[i].y>>c[i].r;
	sort(c,c+n);
int k=2;while(k--){	for(int i=0; i<n; i++) {
		int x=c[i].x-c[i].r;
		priority_queue<int ,vector<int>,greater<int>>pq;
		for(int j=0; j<n; j++)if(c[j].x+c[j].r<=x+w&&c[j].x-c[j].r>=x&&c[j].r*2<=h) {
				while(!pq.empty()) {
					int t=pq.top();
					if(c[j].y+c[j].r-h>t)pq.pop();
					else break;
				}
				pq.push(c[j].y-c[j].r);ans=max(ans,(int)pq.size());
			}
	}
	swap(w,h);
}
cout<<ans<<"\n";
	return 0;
}
