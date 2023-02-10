
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
struct testcase{
    ll n;ll m;
    vi v;
};
ll randomNumber(ll a,ll b){
    return a + (rand() % b);
}
testcase generateTestCase(){
    testcase randomTest;
    randomTest.n = randomNumber(1,100000);
    randomTest.m=randomNumber(1,randomTest.n);
    for(ll i=0;i<randomTest.n;i++)
    {
        ll ele=randomNumber(1,10);
        ll sign=randomNumber(0,2);
        if(sign)
        randomTest.v.pb(ele);
        else
        randomTest.v.pb(-1*ele);
    }
    return randomTest;
}
ll bruteForce(testcase T)
{
    ll p,d;
    p=T.n;
    d=T.m;
    ll n=++p;
    for(ll k=10;;k*=10){
        if(p%k>d)break;
        n=p-(p%k);
    }return n-1;
}
ll optimizedSolution(testcase T){
    string arr;ll num;ll sum;
    num=T.n;
    sum=T.m;
    ll nums=num;
    while (num)
    {
        arr.pb((num%10)+48);
        num/=10;
    }
    ll i=0;
    ll temp=0;
    ll n=arr.size();
    bool flag=0;
    while(i<arr.size() && sum>0)
    {
        flag=0;
        if(i+1<n && arr[i+1]=='0')
        {   flag=1;
            ll val=1+arr[i]-48;
            val*=pow(10,i);
            temp+=val;
            if(sum-temp>=0 && i+1<n)
            {
                ll k=i+1;
                bool mark=0;
                while(k<n)
                {
                    if(arr[k]!='0')
                    {
                        arr[k]--;
                        mark=1;
                        break;
                    }
                    k++;
                }
                k--;
                while(k>i && mark)
                {
                    arr[k]='9';
                    k--;
                }
            }
            else 
            break;
        }

        if(arr[i]=='0')
        {
            ll val=1;
            if(!flag)
            {
                val*=pow(10,i);
                temp+=val;
            }
            if(sum-temp>=0 && i+1<n)
            {
                if(!flag){
                    ll k=i+1;
                    if(k>=n)
                    break;

                    while(k<n && arr[k]=='0' )
                    {
                        arr[k]='9';
                        k++;
                    }
                    if(k!=n && arr[k]!='0')
                    arr[k]--;
                }   
                arr[i]='9';
                sum-=val;
                i++;
            }
            else
            {
                break;
            }
            continue;
        }
        else if(arr[i]=='9')
        {
            i++;
        }
        else
        {
            if(i+1!=n)
            {
                ll val=(arr[i]-48)+1;
                if(!flag)
                {
                    val*=pow(10,i);
                    temp+=val;
                }
                
                if(sum-temp>=0)
                {
                    arr[i]='9';
                    if(!flag)
                    arr[i+1]--;
                    sum-=val;
                    i++;
                }
                else
                {
                    break;
                }
            }
            else
            break;
        }
    }
    reverse(arr.begin(),arr.end());
    ll j=0;
    REP(i,0,n)
    {
        if(arr[i]!='0')
        {
            break;
        }
        else
        j++;
    }
    ll result=0;
    REP(i,j,n)
    {
        result*=pow(n-i-1,10);
        result+=arr[i]-'0';
    }return result;
    
}
bool debugger(){
    testcase random = generateTestCase();
    ll ans1 = bruteForce(random);
    ll ans2 = optimizedSolution(random);
    cout<<"Correct ANS : "<<ans1<<endl<<"Wrong ANS: "<<ans2<<endl;
        cout<<random.n<<" "<<random.m<<endl;
        // for(ll i=0;i<random.n;i++)
        // {
        //     cout<<random.v[i]<<" ";
        // }
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




