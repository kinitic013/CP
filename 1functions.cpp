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
//Prime cound
vector<ll> PrimeCount(ll n)
{
    vector<bool> arr=SieveOfEratosthenes(n);
    vi ans(n+1,0);
    REP(i,1,n+1)
    {
        if(arr[i])
        {
            ans[i]=ans[i-1]+1;
        }
        else
        {
            ans[i]=ans[i-1];
        }
    }
    return ans;
}

//modular expo
int power(ll x, ll y, ll p=(ll)(1e9+7))
{
    int res = 1;  
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
// array containing all divisors
vi Divisors(ll n)
{
    vi ans;
    // Note that this loop runs till square root
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, prll only one
            if (n/i == i)
                ans.pb(i);
            else
            {
                ans.pb(i);
                ans.pb(n/i);
            }     
        }
    }
    return ans;
}

// all prime factors of n
vi primeFactors(ll n)
{
    vi ans;
    // Print the number of 2s that divide n
    if(n%2==0)
    {
        ans.pb(2);
    }
    while (n % 2 == 0)
    {
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i==0)
        {
            ans.pb(i);
        }
        while (n % i == 0)
        {
            n = n/i;
        }
    }
    if (n > 2)
    ans.pb(n);

    return ans;
}