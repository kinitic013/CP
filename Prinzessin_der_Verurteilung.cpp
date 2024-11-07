#include<bits/stdc++.h>
using namespace std;
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

bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}
string alpha={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void  solve()
{
    int n;cin>>n;
    string arr;
    cin>>arr;

    {   vi list(26,0);
        // checking for one character in string
        REP(i,0,n)
        {
            list[arr[i]-97]=1;
        }
        REP(i,0,26)
        {
            if(list[i]!=1)
            {
                cout<<(char)(i+97);
                return;
            }
        }
    }
    {// for substring with size two
        set<string> list;
        REP(i,0,26)
        {
            REP(j,0,26)
            {
                string temp;
                temp.pb(alpha[i]);
                temp.pb(alpha[j]);
                list.insert(temp);
            }
        }
        auto it=list.begin();
        while(it!=list.end() )
        {
            string str=*it;
            auto add=arr.find(str);
            if(add==string::npos)//not found
            {
                cout<<str;
                return;
            }
            it++;
        }
        it=list.begin();
        while(it!=list.end() )
        {
            string str='a'+*it;
            auto add=arr.find(str);
            if(add==string::npos)//not found
            {
                cout<<str;
                return;
            }
            it++;
        }
    }
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