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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
int find(vi arr,int key)
{
    REP(j,0,arr.size())
    {
        if(arr[j]==key)
        {
            return j;
        }
    }
    return -1;
}
void Rshift(vi &arr, int key,int times)
{
    ll idx=times-1;
    int n=arr.size();
    times=times%key;
    vi temp;
    //shifted part
    REP(i,idx+1,key)
    {
        temp.pb(arr[i]);
    }
    REP(i,0,times)
    {
        temp.pb(arr[i]);
    }
    REP(i,key+1,n)
    {
        temp.pb(arr[i]);
    }
    arr=temp;
    return;

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

ll sqrtt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}

vector<vector<ll>> subset(vi arr)
{
    vector<vector<ll>> result;
    int n=arr.size();
    helper(arr,result,0);
    for(auto temp:result)
    {
        for(auto ele :temp)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return result;
}
//seive
vector<bool> SieveOfEratosthenes(int n)
{
    vector<bool> prime(n+1,true);
    prime[0]=false;
    prime[1]=false;
    prime[2]=true;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}