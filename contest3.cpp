#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc;
	cin >> tc;
	for(int i=0;i<tc;i++) {
		int m,n,x,y,u,v;
		cin >> m >> n >> x >> y >> u >> v;
		int d=u-x,t=(d+1)/2;
		if(d<=0) {
			cout << "Draw" << endl;
		}
		else if((d&1) && (abs(y-v)<2 || (y>v && y-1<=t) || (y<v && n-y<=t))) {
			cout << "Alice" << endl;
		}
		else if(!(d&1) && (y==v || (v>y && v-1<=t) || (v<y && n-v<=t))) {
			cout << "Bob" << endl;
		}
		else {
			cout << "Draw" << endl;
		}
	}
	return 0;
}