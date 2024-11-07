#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
mii primeFactors(ll n)
{
    mii result;
    // Prll the number of 2s that divide n
    while (n % 2 == 0)
    {
        result[2]++;
        n = n/2;
    }
 
    // n must be odd at this poll. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, prll i and divide n
        while (n % i == 0)
        {
            result[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        result[n]++;

    return result;
}
void  solve()
{
    ll n;cin>>n;
    mii factor=primeFactors(n);
    vi result;
    vector<pii> fact;
    auto it=factor.begin();
    while(it!=factor.end())
    {
        fact.pb({it->ff,it->ss});
        it++;
    }
    sort(fact.begin(),fact.end(),cmps);
    ll i=0;
    while(i!=fact.size())
    {
        ll val=1;ll count=0;
        REP(j,i,fact.size())
        {
            val*=fact[j].ff;
            fact[j].ss--;
            if(fact[j].ss==0)
            {
                count++;
            }
        }
        i+=count;
        result.pb(val);
    }
    cout<<result.size()<<endl;
    reverse(result.begin(),result.end());
    REP(i,0,result.size())
    {
        cout<<result[i]<<" ";
    }
    return;

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
