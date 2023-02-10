//unequal_array.cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void  solve(vector<int> arr,int n)
{
    bool is_conti=false;
    int step=0;
    int pair=0;
    int conti=1;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            pair++;
            conti++;
        }
        else
        {
            if(conti>2)
            {
                
            }
        }
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
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            arr.push_back(ele);
        }
        solve(arr,n);
        cout<<"\n";
    }
    return 0;
}