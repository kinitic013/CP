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
#define vpii vector<pii>
#define pairMinHeap priority_queue<pii , vpii, greater<pii> > 
#define all(x) (x).begin(), (x).end()
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define revREP(i,a,b) for (ll i = a ; i>b ; i--)
#define MOD (ll)(1e9 + 7)
#define mod (ll)998244353
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
long long my_sqrt(long long a)
{
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
bool cmps(pii &a, pii &b)
{
    return a.ss < b.ss;
}
vi path(ll n)
{
    vi res;
    while(n>=1)
    {
        res.pb(n);
        n/=2;
    }
    return res;
}
bool helper(vi&arr , ll l , ll r , ll left , ll right)
{
    if(left == right)
    {
        if((r-l+1)%2 == 0)
        {
            return false;
        }
        if(left*2 <= 1e9)
        {
            ll k = l+1;
            while(k<r)
            {
                arr[k] = 2*left;
                arr[k+1] = left;
                k+=2;
            }
            return true;
        }
        else if(left/2 >=1)
        {
            ll k = l+1;
            while(k<r)
            {
                arr[k] = left/2;
                arr[k+1] = left;
                k+=2;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    vi pathA = path(left);
    vi pathB = path(right);
    ll lastA = pathA.size()-1;
    ll lastB = pathB.size()-1;
    ll last = 0;
    while(pathA.size()>=2 &&  pathB.size()>=2)
    {
        lastA = pathA.size()-1;
        lastB = pathB.size()-1;
        if(pathA[lastA] == pathB[lastB])
        {
            if(pathA[lastA-1] == pathB[lastB-1])
            {
                pathA.pop_back();
                pathB.pop_back();
            }
            else
            {
                last = pathA[lastA];
                break;
            }
        }
    }
    ll mini_need = pathA.size() + pathB.size() - 1;
    if(mini_need > r-l+1)
    {
        return false;
    }
    if((mini_need&1) != ((r-l+1)&1))
    {
        return false;
    }
    int i = 1;
    ll j = l+1;
    while(i<pathA.size() && j<r)
    {
        arr[j] = pathA[i];
        j++;
        i++;
    }
    reverse(all(pathB));
    i = 1;
    while(i<pathB.size() && j<r)
    {
        arr[j] = pathB[i];
        i++;
        j++;
    }

    while(j<r)
    {
        if(arr[j-1]*2 <= 1e9)
        {
            arr[j] = 2*arr[j-1];
            arr[j+1] = arr[j-1];
            j+=2;
        }
        else if(arr[j-1]/2 >=1)
        {
            arr[j] = arr[j-1]/2;
            arr[j+1] = arr[j-1];
            j+=2;
        }
    }
    return true;
}
void solve(ll t)
{
    ll n;
    cin >> n;
    vi arr(n);
    REP(i,0,n) cin >> arr[i];
    vi idx;
    REP(i,0,n)
    {
        if(arr[i] != -1)
            idx.pb(i);
    }
    if(idx.empty())
    {
        REP(i,0,n)
        {
            arr[i] = 1;
            if(i+1 < n) arr[i+1] = 2;
            i++;
        }
        REP(i,0,n) cout << arr[i] << " ";
        return;
    }
    
    // Handle 0 -> idx[0]-1
    for(int i = idx[0]-1; i >= 0 && i < n; i--)
    {
        if(i+1 < n && arr[i+1]*2 <= 1e9)
        {
            arr[i] = 2*arr[i+1];
            if(i-1 >= 0) arr[i-1] = arr[i+1];
            i--;
        }
        else if(i+1 < n && arr[i+1]/2 >= 1)
        {
            arr[i] = arr[i+1]/2;
            if(i-1 >= 0) arr[i-1] = arr[i+1];
            i--;
        }
        else
        {
            cout << -1;
            return;
        }
    }
    
    // Handle idx.last + 1 -> n-1
    for(int i = idx.back()+1; i < n; i++)
    {
        if(i-1 >= 0 && arr[i-1]*2 <= 1e9)
        {
            arr[i] = 2*arr[i-1];
            if(i+1 < n) arr[i+1] = arr[i-1];
            i++;
        }
        else if(i-1 >= 0 && arr[i-1]/2 >= 1)
        {
            arr[i] = arr[i-1]/2;
            if(i+1 < n) arr[i+1] = arr[i-1];
            i++;
        }
        else
        {
            cout << -1;
            return;
        }
    }
    
    REP(i,1,idx.size())
    {
        ll l = idx[i-1];
        ll r = idx[i];
        if(r-l == 1) // consecutive elements
        {
            if(arr[l] == arr[r]/2 || arr[r] == arr[l]/2)
            {
                // valid
            }
            else
            {
                cout << -1;
                return;
            }
        }
        else
        {
            if(!helper(arr,l,r,arr[l],arr[r]))
            {
                cout << -1;
                return;
            }
        }
    }
    
    REP(i,0,n-1)
    {
        if((arr[i] == arr[i+1]/2) || (arr[i+1] == arr[i]/2))
        {
            // valid
        }
        else
        {
            cout << -1;
            return;
        }
    }
    
    REP(i,0,n) cout << arr[i] << " ";
    cout.flush();
}

int main()
{
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;
    REP(T,1,t+1)
    {
        solve(T);
        cout.flush();
        cout << endl;
    }
    return 0;
}