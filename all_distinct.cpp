#include<bits/stdc++.h>
using namespace std;
#define ll long long
void  solve(vector<int> arr,int n,int maxi)
{
    int list[maxi+1]={0};
    int len=0;
    int extra=0;
    for(int i=0;i<n;i++)
    {
        if(list[arr[i]]>1)
        {
            extra++;
        }
        list[arr[i]]++;
    }
    //counting array created
    for(int i=0;i<maxi+1;i++)
    {
        if(list[i]>0)
        {
            len++;
        }
    }
    if(n&1)//if n is odd
    {
        if(len%2==0)//if len is even
        {
            cout<<len-1;
            return;
        }
        else
        {
            cout<<len;
        }
    }
    else
    {
        if(len%2==0)
        {
            cout<<len;
        }
        else
        {
            cout<<len-1;
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
        int a;
        cin>>a;
        vector<int> arr;
        int maxi=0;
        for(int i=0;i<a;i++)
        {
            int ele;
            cin>>ele;
            maxi=max(maxi,ele);
            arr.push_back(ele);
        }

        solve(arr,a,maxi);
        cout<<"\n";
    }
    return 0;
}