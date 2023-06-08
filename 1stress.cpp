
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
#define pb push_back
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define ll long long
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}

#define viip vector<pair<ll,ll>>
const ll mod = 998244353;
#define fore(i, l, r) for(ll i = ll(l); i < ll(r); i++)
ll min(ll a,ll b)
{
	return a<b?a:b;
}
struct testcase{
    ll n,m;
    string str1,str2;
};
ll randomNumber(ll a,ll b){
    ll random = a + (rand() % b);
    return random;
}
testcase generateTestCase(){
    testcase randomTest;
    randomTest.n = randomNumber(1,5);
    randomTest.m=randomNumber(1,5);
    for(ll i=0;i<randomTest.n;i++)
    {
        ll ele=randomNumber(0,25);
        randomTest.str1.pb(ele+'a');
    }    
    for(ll i=0;i<randomTest.m;i++)
    {
        ll ele=randomNumber(0,25);
        randomTest.str2.pb(ele+'a');
    }
    return randomTest;
}

ll bruteForce(testcase T)
{
   {
  string a, b;
  a=T.str1;
  b=T.str2;
  int na = a.size(), nb = b.size();
  vector<vector<int>> dp(na+1, vector<int>(nb+1,1e9));
  dp[0][0] = 0;
  for (int i = 0; i <= na; i++) {
    for (int j = 0; j <= nb; j++) {
      if (i) {
	dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
      }
      if (j) {
	dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
      }
      if (i && j) {
	dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1] != b[j-1]));
      }
    }
  }
  return dp[na][nb];
}
}
ll optimizedSolution(testcase T)
{
    vector<vector<ll>> dp(5000,vector<ll>(5000,0));
    {
    string arr;
    string aim;
    aim=T.str1;
    arr=T.str2;
    ll n=aim.size();
    ll m=arr.size();
    // j goes of aim "arr"
    // i goes over from may "aim"s
    ll right=-1,down=-1,downright=-1;
    ll extra=0;
    if(arr[m-1]!=aim[n-1])
    {
        dp[m-1][n-1]=1;
    }
    for(ll i=m-2;i>=0;i--)
    {
        if(arr[i]!=aim[n-1])
        {
            dp[i][n-1]=dp[i+1][n-1]+1;
        }
        else
        {
            dp[i][n-1]=m-i-1;
        }
    }
    for(ll i=n-2;i>=0;i--)
    {
        if(arr[m-1]!=aim[i])
        {
            dp[m-1][i]=dp[m-1][i+1]+1;
        }
        else
        {
            dp[m-1][i]=n-i-1;
        }
    }

    for(ll j=n-2;j>=0;j--)
    {
        right=LONG_LONG_MAX;
        down=LONG_LONG_MAX;
        downright=LONG_LONG_MAX;
        extra=0;
        for(ll i=m-2;i>=0;i--)
        {
            if(j+1<n)
            right=dp[i][j+1];
            if(i+1<m)
            down=dp[i+1][j];
            if(i+1<m && j+1<n)
            downright=dp[i+1][j+1];
 
            if(arr[i]!=aim[j])
            extra=1;
            else
            extra=0;
 
            dp[i][j]=min(right,min(down,downright))+extra;
        }
    }
    return dp[0][0];
}
}

bool debugger(){
    testcase random = generateTestCase();
    ll ans1 = bruteForce(random);
    ll ans2 = optimizedSolution(random);
    
    cout<<"Correct ANS : "<<ans1<<endl<<"Wrong ANS: "<<ans2<<endl;
    cout<<random.str1<<endl;
    cout<<random.str2<<endl;
        cout<<endl<<endl<<endl<<endl;
    if(ans1 != ans2) {
        return true;
    }
    return false;
}


void solve()
{
    while(1)
    {
        if(debugger())
        break;
    }
}
int main()
{
    solve();
    return 0;
}




