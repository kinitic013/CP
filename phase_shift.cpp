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
#define REP(i,start,end) for(auto i=(start<end)?start:start-1;(start<end)?i<end:i>=end;(start<end)?i++:i--)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
bool checker(map<char,char>check,char ele)
{
    auto it=check.find(ele);
    ll count=0;
    set<char> distinct;
    distinct.insert(it->ff);
    while(count<26)
    {
        if(it->ss==0)
        {
            return false;
        }
        else
        {
            it=check.find(it->ss);
            distinct.insert(it->ff);
        }
        count++;
    }
    if(distinct.size()!=26)
    return true;
    else
    return false;

}
void  solve()
{
    int n;cin>>n;
    string arr;
    cin>>arr;
    map<char,char> check;
    vi done(26,0);
    string result;
    REP(i,0,26)
    {
        check.insert({i+'a',0});
    }
    REP(i,0,n)
    {
        auto it=check.begin();
        if(check[arr[i]]!=0)
        {
            result.pb(check[arr[i]]);
            continue;
        }

        while(it!=check.end())
        {
            if(it->ff!=arr[i] && done[it->ff-'a']!=1)
            {
                check[arr[i]]=it->ff;
                if(!checker(check,it->ff))
                {
                    result.pb(it->ff);
                    done[it->ff-'a']=1;
                    break;
                }
                else
                {
                    check[arr[i]]=0;
                    it++;
                    continue;
                }
                
            }
            it++;
        }
    }
    cout<<result;
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
