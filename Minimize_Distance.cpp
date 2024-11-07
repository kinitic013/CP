#include<bits/stdc++.h>
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
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

void  solve()
{
    ll n,k;cin>>n>>k;input
    sort(arr.begin(),arr.end());
    ll count=0;
    vi right;
    vi left;
    REP(i,0,n)
    {
        if(arr[i]>0)
        {
            right.pb(arr[i]);
        }
        else
        {
            left.pb(-arr[i]);
        }
    }
	if(!left.empty())
	{
		reverse(left.begin(),left.end());
	}
	ll maxi=0;
	if(!left.empty())
	{
		ll i=left.size()-1;
		while (i>=0)
		{
			count+=abs(2*left[i]);
			i-=k;
		}
		maxi=max(maxi,left[left.size()-1]);
	}
	if(!right.empty())
	{
		ll i=right.size()-1;
		while (i>=0)
		{
			count+=abs(2*right[i]);
			i-=k;
		}
	}
	if(!right.empty())
	{
		if(*(--right.end())>maxi)
		{
			count-=(*(--right.end()));
		}
		else
		{
			count-=maxi;
		}
	}
	else
	{
		count-=maxi;
	}
	cout<<count;
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
