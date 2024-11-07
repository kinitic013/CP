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
#define all(x) (x).begin(),(x).end()
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define MOD (ll)(1e9+7)
#define mod (ll)998244353
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
void  solve()
{
    ll n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    vector<vector<ll>> one(n1+1,vi(n2+1,0));
    vector<vector<ll>> two(n1+1,vi(n2+1,0));
    REP(i,1,n1+1)
    {
        if(i<=k1)
        {
            two[i][0]=1;
        }
    }
    REP(i,1,n2+1)
    {
        if(i<=k2)
        {
            one[0][i]=1;
        }
    }
    REP(i,1,n1+1)
    {
        REP(j,1,n2+1)
        {
            //for one
            REP(k,1,k2+1)
            {
                if(j-k<0)
                break;
                else
                {
                    one[i][j]=(one[i][j]+two[i][j-k])%100000000;
                }
            }
            // for two
            REP(k,1,k1+1)
            {
                if(i-k<0)
                break;
                else
                {
                    two[i][j]=(two[i][j]+one[i-k][j])%100000000;
                }
            }
        }
    }
    cout<<(one[n1][n2]+two[n1][n2])%100000000;

}
int main()
{   
    clock_t start, end;
 
    // Start clock
    start = clock();
 
    {
        solve();
        cout<<"\n";
    }
    // End clock
    end = clock();
 
    // Calculate the time difference
    double time_taken
        = double(end - start)
          / double(CLOCKS_PER_SEC);
 
    // Print the Calculated execution time
    cout << "Execution time: " << time_taken
         << " secs";
    
    return 0;
}
