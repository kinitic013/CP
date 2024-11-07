#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define REP(i, a, b) for (ll i = a; i < b; i++)
bool cmps(pii a, pii b)
{
    return a.ss < b.ss;
}
/*
appraoch -> rather than searching over days we should search over shop in prefix sum manner
i.e. for i=1 to i=n
    for arr[i](shop at i) increamnt in price will be by i after each day to 
    we search for no. of element in AP until arr[i]<=k and add it to count
    we do this till current count of element <0 
*/
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> list;
    vector<ll> arr;
    ll sum = 0;

    REP(i, 0, n)
    {
        ll ele;
        cin >> ele;
        list.push_back(ele);
    }
    sort(list.begin(), list.end());

    //  created a sorted sequence of shops wrt price
    REP(i, 0, n)
    {
        sum += list[i];
        arr.pb(sum);
    }
    // sorted prefix sum
    /*
        Now what we do is-> first search for upperbound of K
    */
    ll count = 0;
    REP(i, 0, n)
    {
        if (arr[i]>k)
        {
            break;
        }
        count += (1 + (k - arr[i]) / (i + 1)); 
    }
    cout << count;
    return;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}