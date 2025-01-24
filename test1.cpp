#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long n, m, d, D;
	cin >> n >> m >> d >> D;
	long long max = n * n;

	if((m<(d*n)) || (m>(D*n)) || (m>max) || (d>n)){
		cout << -1 << endl;
		return;
	}
	vector<vector<long long>> adj(n+1);
	vector<long long> degree(n+1,0);
	long long x = -1;
	while (m>0)
	{
		x++;

		for (long long i = 1; i <= n; i++)
		{
			if (m <= 0) {break; }
			if (i == n)
			{
				adj[i].push_back(x + 1);
				degree[i]++;
				m--;
				continue;
			}
			else{
				adj[i].push_back(i + x);
			degree[i]++;
			m--;   }

		}
		if (m == 0) {break;}
		if(x==n) {break;}
	}

	bool flag = false;
	for(long long i=1;i<=n;i++){
		if((degree[i]>D)|| degree[i]<d){
			cout<<-1<<endl;
			return;
		}
	} 
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<degree[i];j++){
			cout<<i<<" "<<adj[i][j]<<endl;
		}
	}
	return;
}

int main() {

    long long t;
    cin >> t;
    while (t--) {
		solve();
		cout<<endl;
    }
    return 0;
}
    