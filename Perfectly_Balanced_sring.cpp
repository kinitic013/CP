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
const ll MOD = 1e9+7;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
/*
an array will always be good if before repeatation all distinct elemetns are present in there in that way
for any subarray difference in frequency will not exede 1/
*/
void  solve()
{
    string arr;
    cin>>arr;
    ll n=arr.size();
    unordered_set<char> dis;
    map<char,ll> idx;
    // creating index of all alphabets
    REP(i,0,26)
    {
        idx[97+i]=-1;
    }

    ll len=0;

    REP(i,0,n)
    {
        dis.insert(arr[i]);
    }

    len=dis.size();
    if(len==1)
    {
        cout<<"YES";
        return;
    }
    idx[arr[0]]=0;
    ll count=0;
    REP(i,1,n)
    {
        ll pos=idx[arr[i]];
        if(pos==-1)
        {
            idx[arr[i]]=i;
        }
        else//repetation has taken place
        {
            if((i-pos)<len)
            {
                cout<<"NO";
                return;
            }
            else
            {
                idx[arr[i]]=i;
            }
        }
    }
    cout<<"YES";
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