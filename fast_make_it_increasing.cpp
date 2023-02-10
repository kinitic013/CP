#include<bits/stdc++.h>
//https://codeforces.com/contest/1675/problem/B
//fast_make_it_increasing.cpp
using namespace std;
#define ll long long
void  solve(ll n,vector<ll> arr)
{
    ll step=0;
    for(ll i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1] && arr[i]>=0 )
        {
            continue;
        }
        ll num1,num2;//calculating bit lenght
        {
             num1=(ll)log2(arr[i])+1;//this line is throwing error "memory overflow"
        }
        {
            num2=(ll)log2(arr[i+1])+1;
        }
        if(num1-num2==0)//if equal and arr[i]>arr[i+1] then divide by2 once
        {
            arr[i]=arr[i]>>1;
            step++;
        }
        else
        {
            ll m=(num1-num2);
            ll ele=arr[i]>>m;//checking wheather less or not if not than divide once more
            if(ele<arr[i+1])
            {
                arr[i]=ele;
                step+=m;
            }
            else
            {
                ele=ele>>1;
                arr[i]=ele;
                step+=m+1;
            }
            
        }
        if(arr[i]<=0 && i!=0)//if element is 0 and that element isn't first then definetly it can form a asc. sequence
        {
            cout<<-1;
            return;
        }
    }
    cout<<step;
    return ;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        vector<ll> arr;
        cin>>n;
        for(ll i=0;i<n;i++)
        {   
            ll ele;
            cin>>ele;
            arr.push_back(ele);
        }        
        solve(n,arr);
        cout<<"\n";
    }
    return 0;
}