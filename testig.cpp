
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
#define pb push_back
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
#define ll long long
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define all(x) (x).begin(),(x).end()
#define viip vector<pair<ll,ll>>
const ll mod = 998244353;
#define fore(i, l, r) for(ll i = ll(l); i < ll(r); i++)
bool cmps(pii &a, pii &b)
{
	return a.ss < b.ss;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
struct testcase{
    ll n;
    vector<ll> arr;
};
ll randomNumber(ll a,ll b){
    return a + (rand() % b);
}
vpii printTreeEdges(vector<int> prufer, int m)
{
	int vertices = m + 2;
    vpii res;
	vector<int> vertex_set(vertices);

	// Initialize the array of vertices
	for (int i = 0; i < vertices; i++)
		vertex_set[i] = 0;

	// Number of occurrences of vertex in code
	for (int i = 0; i < vertices - 2; i++)
		vertex_set[prufer[i] - 1] += 1;

	cout<<("\nThe edge set E(G) is:\n");

	int j = 0;

	// Find the smallest label not present in
	// prufer[].
	for (int i = 0; i < vertices - 2; i++) 
	{
		for (j = 0; j < vertices; j++)
		{

			// If j+1 is not present in prufer set
			if (vertex_set[j] == 0)
			{

				// Remove from Prufer set and print
				// pair.
				vertex_set[j] = -1;
				cout<<j + 1<< " "
								<< prufer[i] << "\n";
                
                res.pb({j+1,prufer[i]});
				vertex_set[prufer[i] - 1]--;

				break;
			}
		}
	}

	j = 0;

	// For the last element
	for (int i = 0; i < vertices; i++)
	{
		if (vertex_set[i] == 0 && j == 0)
		{

			cout<<i + 1<< endl;
			j++;
		}
		else if (vertex_set[i] == 0 && j == 1)
			cout << i + 1 << "\n";
	}
}

// generate random numbers in between l an r
int ran(int l, int r)
{
	return l + (rand() % (r - l + 1));
}

// Function to Generate Random Tree
void generateRandomTree(int n)
{

	int length = n - 2;
	vector<int> arr(length);

	// Loop to Generate Random Array
	for (int i = 0; i < length; i++) 
	{
		arr[i] = ran(0, length + 1) + 1;
	}
	printTreeEdges(arr, length);
}

ll optimizedSolution(testcase T)
{
    ll n;n = T.n;
    vi arr= T.arr;
    vi idx;
    ll maxi = *max_element(all(arr));
    REP(i,0,n)
    {
        if(arr[i] == maxi)
        idx.pb(i);
    }
    ll pos = idx[0];
    if(n&1)
    {
        ll target = n/2;
        REP(i,0,idx.size())
        {
            if(abs(target - pos) > abs(target - idx[i]))
            {
                pos = idx[i];
            }
        }
    }
    else
    {
        ll targetA = n/2;
        ll targetB = n/2 - 1;
        REP(i,0,idx.size())
        {
            ll val1 = abs(targetA - idx[i]);
            ll val2 = abs(targetB - idx[i]);
            ll val = min(val1,val2);
            ll aim1 = abs(targetA - pos);
            ll aim2 = abs(targetB - pos);
            ll aim = min(aim1,aim2);

            if(val < aim)
            {
                pos = idx[i];
            }
        }   
    }
    // most optimal starting point selected
    vi need(n,0);
    ll ans = 0;
    REP(i,0,n)
    {
        if(pos > i)
        {
            need[i] = arr[i] + (n - i - 1) ;
        }
        else if(pos < i)
        {
            need[i] = arr[i] + i;
        }
        else
        {
            need[i] = arr[i];
        }
        ans = max(ans , need[i]);
    }
    return ans;
}

ll bruteForce(testcase T) {
	int t;t = T.n;
	int a[t], p[t];
	for (int i = 0; i < t; i++) {
		a[i] = T.arr[i];
		p[i] = a[i] + t - i - 1;
		if (i) {
			p[i] = max(p[i], p[i - 1]);
		}
	}
	int mx = 0, ans = INT_MAX;
	for (int i = t - 1; i >= 0; i--) {
		ans = min(ans, max(a[i], max(i ? p[i - 1] : 0, mx)));
		mx = max(mx, a[i] + i);
	}
    return ans;
}
bool debugger(){
    testcase random = generateTestCase();
    ll ans1 = bruteForce(random);
    ll ans2 = optimizedSolution(random);
    cout<<"Correct ANS : "<<ans1<<endl<<"Wrong ANS: "<<ans2<<endl;
        cout<<random.n<<endl;
        for(int i =0;i<random.n;i++)
        {
            cout<<random.arr[i]<<" ";
        }
        cout<<endl<<endl<<endl<<endl;
        cout.flush();
    if(ans1 != ans2) {
        return true;
    }
    return false;
}


void solve()
{
    while(1)
    {
        if(debugger())
        break;
    }
}
int32_t main()
{
    solve();
    return 0;
}




