#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,x,y;
    cin>>a>>x>>y;
    if((x>a || x<0) || (y>a || y<0)){// outside
    cout<<2;
    return 0;
    }
    if(x==a || x==0)//on Border
    {
        if(y<=a && y>=0)
        {
            cout<<1;
            return 0;
        }
    }
    if(y==a || y==0)
    {
        if(x<=a && x>=0)
        {
            cout<<1;
            return 0;
        }
    }
    if((x<a || x>0) && (y<a ||y>0))
    {
        cout<<0;
    }
    return 0;
}