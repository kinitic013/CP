#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		long long x,k,p;cin>>x>>k>>p;
		long long a[x+1],ans=0,sum=0;
		priority_queue<long long>q;
		for(int i=1;i<=x;i++){
			cin>>a[i];
			if(a[i]<0)continue;
			q.push(-a[i]);sum+=a[i];
			while(q.size()>k){
				sum+=q.top();q.pop();
			}
			ans=max(ans,sum-i*p);
		}
		cout<<ans<<"\n";
	}
	return 0;
}