
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
#define pb push_back
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define ll long long
#define endl '\n'
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define input vi arr;REP(i,0,n){ll ele;cin>>ele;arr.pb(ele);}
#define all(x) (x).begin(),(x).end()
#define viip vector<pair<ll,ll>>
const ll mod = 998244353;
#define fore(i, l, r) for(ll i = ll(l); i < ll(r); i++)
ll min(ll a,ll b)
{
	return a<b?a:b;
}
bool cmps(pair<ll,pii> a,pair<ll,pii> b)
{
    return a.ss.ff<b.ss.ff;
}
struct testcase{
    ll n;ll m; ll d;
    vi arr;
};
ll randomNumber(ll a,ll b){
    return a + (rand() % b);
}
testcase generateTestCase(){
    testcase randomTest;
    randomTest.n = randomNumber(1,10);
    randomTest.m = randomNumber(1,randomTest.n);
    randomTest.d = randomNumber(1,10);

    for(ll i=0;i<randomTest.n;i++)
    {
        ll ele=randomNumber(1,100);
        ll state=randomNumber(1,1);
        if(state==1)
        randomTest.arr.push_back(ele);
        else
        randomTest.arr.push_back((-1)*ele);
    }
    return randomTest;
}
ll bruteForce(testcase T)
{
		long long x,k,p;
        x=T.n;
        k=T.m;
        p=T.d;
		long long a[x+1],ans=0,sum=0;
		priority_queue<long long>q;
		for(int i=1;i<=x;i++){
			a[i]=T.arr[i-1];
			if(a[i]<0)continue;
			q.push(-a[i]);sum+=a[i];
			while(q.size()>k){
				sum+=q.top();q.pop();
			}
			ans=max(ans,sum-i*p);
		}
		return ans;
	}
ll optimizedSolution(testcase T)
{
    ll n,m,d;
    n=T.n;
    m=T.m;
    d=T.d;

    vi arr=T.arr;

    if(m==1)
    {
        ll res=0;
        REP(i,0,n)
        {
            res=max(res,arr[i]-(i+1)*d);
        }
        return res;
    }


    multiset<ll> s;
    vi sum;
    ll total=0;
    REP(i,0,n)
    {
        if(arr[i]>0)
        {
            if(s.size()<m-1)
            {
                total+=arr[i];
                sum.pb(total);
                s.insert(arr[i]);
            }
            else if(s.size()==m-1)
            {
                ll top=(*s.begin());
                if(top<arr[i])
                {
                    total+=arr[i]-top;
                    s.erase(s.begin());
                    s.insert(arr[i]);
                    
                }
                sum.pb(total);
            }
        }
        else
        sum.pb(total);
    }
    ll ans=0;
    for(ll i=n-1;i>0;i--)
    {
        ll current = sum[i-1]-(i+1)*d + arr[i];
        ans=max(ans,current);
    }
    return ans;
}
bool debugger(){
    testcase random = generateTestCase();
    ll ans1 = bruteForce(random);
    ll ans2 = optimizedSolution(random);
    cout<<"Correct ANS : "<<ans1<<endl<<"Wrong ANS: "<<ans2<<endl;
        cout<<random.n<<" "<<random.m<<" "<<random.d<<endl;
        REP(i,0,random.arr.size())
        {
            cout<<random.arr[i]<<" ";
        }
        cout<<endl<<endl<<endl<<endl;
    if(ans1 != ans2) {
        return true;
    }
    return false;
}


void solve()
{
    ofstream output("output.txt");
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




