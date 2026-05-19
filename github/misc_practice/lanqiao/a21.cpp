#include <bits/stdc++.h>
using namespace std;

int main() {
	int n=11,h=0,eat=0;
	while(n||(h==2&&eat%2==0)) {
		if(eat&&eat%2==0)h++;
		if(h&&h%3==0) {
			h=0;
			n++;
		} 
		eat++;
		n--;
	}
	cout<<eat<<"\n";
	// 请在此处编写代码...
	return 0;
}
