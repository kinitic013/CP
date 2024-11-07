//Consecutive_Points_Segment.cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void  solve(vector<int> arr)
{
    int n=arr.size();
    int diff=0,count=0;
    bool yes_no=true;
    bool is_diff_greater=false;
    int last_diff=0;
    bool corner=false;
    for(int i=0;i<n-1;i++)
    {
        diff=arr[i+1]-arr[i];
        if(diff>3)//not possible to form consecutive 
        {
            yes_no=false;
            break;
        }
        if(diff==3 )
        {
            is_diff_greater=true;
            count++;
        }
        if(diff==2)
        {
            if(last_diff==diff)
            {
                if(i<n-2)
                {
                    yes_no=false;
                    break;
                }
                else if(i==n-2)
                {
                    yes_no=true;
                    break;
                }
            }
            last_diff=diff;
            is_diff_greater=true;
            count++;
        }
        else
        {
            last_diff=0;
        }
        if(count>1)
        {
            yes_no=false;
            break;
        }
    }
    if(yes_no)
    {
        cout<<"YES";
    }
    else
    cout<<"NO";
    return ;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            arr.push_back(ele);
        }
        solve(arr);
        cout<<"\n";
    }
    return 0;
}