#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<double, nudouble_type,less<double>, rb_tree_tag,tree_order_statistics_node_update>
#define double long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<double,double>
#define pii pair<double,double>
#define vi vector<double>
#define endl '\n'
#define REP(i,a,b) for(double i=a;i<b;i++)
#define input vi arr;REP(i,0,n){double ele;cin>>ele;arr.pb(ele);}
bool cmps(pii a,pii b)
{
    return a.ss<b.ss;
}

void  solve()
{
    cout.precision(9);
    double W,H;cin>>W>>H;
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double w,h;cin>>w>>h;
    double w1=x2-x1,h1=y2-y1;
    double dist=LONG_LONG_MAX;
    
    // //only 4 possible ways are there
    // if(w+w1>W || h+h1>H)
    // {
    //     cout<<-1;
    //     return;
    // }
    {
        
        // moving table up
        double valh,valw;
        valh=(double)(h-y1);
        if(valh<=0)
        valh=0;
        if(h1+h<=H)
        {
            dist=(double)min(dist,valh);
        }
        //moving right
        valw=w-x1;
        if(valw<=0)
        valw=0;
        if(w1+w<=W)
        {
            dist=(double)min(dist,valw);
        }
        // moving down
        valh=h-(H-y2);
        if(valh<=0)
        valh=0;

        if(h+h1<=H)
        {
            dist=(double)min(dist,valh);
        }
        //moving left
        valw=w-(W-x2);
        if(valw<=0)
        valw=0;
        if(w1+w<=W)
        {
            dist=(double)min(dist,valw);
        }
        if(dist==LONG_LONG_MAX)
        {
            cout<<-1;
            return;
        }
        cout<<fixed<<dist<<".000000000";
    }
    
}
int main()
{
    double t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
