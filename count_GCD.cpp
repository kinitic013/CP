#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
vi primeFactors(int n)
{
    vi result;
    // Print the number of 2s that divide n
    if(n%2==0)
    {
        result.pb(2);
    }
    while (n % 2 == 0)
    {
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        if(n%i==0)
        {
            result.pb(i);
        }
        while (n % i == 0)
        {
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        result.pb(n);

    return result;
}
void helper(vi arr,vector<vector<ll>> &result,int i)
{
    int n=arr.size();
    if(i==n)
    {
        return;
    }
    vector<vector<ll>> temp;
	if(result.empty())
	{
		vi seq;
		result.pb(seq);
		seq.pb(arr[i]);
		result.pb(seq);
		helper(arr,result,i+1);
		return;
	}
    REP(j,0,result.size())
    {
        temp.pb(result[j]);
    }
    REP(j,0,result.size())
    {
        result[j].pb(arr[i]);
        temp.pb(result[j]);
    }
    result=temp;
    helper(arr,result,i+1);
	return;
}
vector<vector<ll>> subset(vi arr)
{
    vector<vector<ll>> result;
    int n=arr.size();
    helper(arr,result,0);
    return result;
}

void  solve()
{
    ll n,m;cin>>n>>m;input
    ll count=1;

    REP(i,1,n)
    {
        ll val=__gcd(arr[i-1],arr[i]);
        if(val!=arr[i])
        {
            cout<<0;
            return;
        }
        else
        {
            vi factor=primeFactors(arr[i-1]/arr[i]);
            vector<vi> set=subset(factor);
            ll total=m/arr[i];
            ll j=total;
            REP(k,1,set.size())
            {
                ll sum=1;
                REP(p,0,set[k].size())
                {
                    sum*=set[k][p];
                }
                if(set[k].size()&1)//odd then removing useless factors
                {
                    j-=(total/sum);
                }
                else
                {
                    j+=(total/sum);
                }
            }
            count=(count*j)%998244353;
        }
    }
    cout<<count%998244353;
    return ;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}


