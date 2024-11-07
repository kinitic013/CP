#include<bits/stdc++.h>
//https://codeforces.com/contest/1675/problem/B
//make_it_increasing.cpp
//accepted but slow
using namespace std;
#define ll long long
void  solve(int n,vector<int> arr)
{
    int step=0;
    bool flag=true;
    for(int i=n-2;i>=0;i--)
    {
        while(arr[i]>=arr[i+1] && arr[i]>0)
        {
            arr[i]/=2;
            step++;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>=arr[i+1])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        cout<<step;
    }
    else
    {
        cout<<"-1";
    }
    return ;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        vector <int> arr;
        cin>>n;
        for(int i=0;i<n;i++)
        {   int ele;
            cin>>ele;
            arr.push_back(ele);
        }        
        solve(n,arr);
        cout<<"\n";
    }
    return 0;
}