#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define mp make_pair
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vb vector<bool>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<ll> segTree;
vector<ll> sum;
vector<ll> pre;
vector<ll> suff;

void build(vector<ll>& arr, ll start , ll end , ll index)
{
    if(start == end)
    {
        segTree[index] = max<ll>(arr[start] , 0);
        sum[index] = arr[start];
        pre[index] = max<ll>(arr[start] , 0);
        suff[index] = max<ll>(arr[start] ,0);
        return; 
    }
    ll mid = (start + end)/2;
    ll left = index*2+1;
    ll right = index*2 + 2;
    build(arr,start,mid,left);
    build(arr,mid+1,end,right);
    sum[index] = sum[left] + sum[right];
    pre[index] = max<ll>(pre[left] , sum[left] + pre[right]);
    suff[index] = max<ll>(suff[right] , sum[right] + suff[left]);
    segTree[index] =  max<ll>(segTree[left] , max<ll>( segTree[right],(suff[left]+pre[right])));
}
void update(vector<ll>& arr , ll start , ll end , ll index , ll pos , ll value)
{
    if(start == end)
    {
        arr[pos] = value;
        segTree[index] = max<ll>(arr[start] , 0);
        sum[index] = arr[pos];
        pre[index] = max<ll>(arr[pos] , 0);
        suff[index] = max<ll>(arr[pos] ,0);
        return;
    }
    ll mid = (start + end)/2;
    ll left = index*2 + 1;
    ll right = index*2 + 2;
    if(pos<=mid)
    {
        update(arr,start,mid,left,pos,value);
    }
    else
    {
        update(arr,mid+1,end,right,pos,value);
    }
    sum[index] = sum[left] + sum[right];
    pre[index] = max<ll>(pre[left] , sum[left] + pre[right]);
    suff[index] = max<ll>(suff[right] , sum[right] + suff[left]);
    segTree[index] = max<ll>(segTree[left] , max<ll>(segTree[right],(suff[left]+pre[right])));
}
ll query(ll start,ll end,ll index,ll l,ll r)
{
    if(start == end)
    {
        return segTree[start];
    }
    ll mid = (start + end)/2;
    ll left = index*2 + 1;
    ll right = index*2 + 2;
    if(start>= l && end<= r)// fully contrinuting
    {
        return segTree[index];
    }
    else if(end < l || start > r)
    {
        return 0;
    }
    return (query(start,mid,left,l,r) + query(mid+1,end,right,l,r));
}
void solve()
{
    ll n;cin>>n;
    ll m;cin>>m;
    vector<ll> arr(n);
    segTree.resize(4*n,0);
    pre.resize(4*n,0);
    suff.resize(4*n,0);
    sum.resize(4*n,0);

    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(arr,0,n-1,0);
    // cout<<segTree[0]<<endl;

    REP(i,0,m)
    {
        {
            ll pos,value;
            cin>>pos>>value;
            pos--;
            update(arr,0,n-1,0,pos,value);
            cout<<segTree[0];
            cout<<endl;
        }
    }
}
int main()
{
    fast();
    {
        solve();
        cout << endl;

    }
    return 0;
}
