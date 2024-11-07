#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
string subtraction(string big,string smol)
{
    int n=big.size();
    int m=smol.size();
    string result;
    int i=n-1;
    int diff=n-m;
    string small;
    if(diff!=0)
    {
        for(int i=0;i<m;i++)
        {
            while(diff!=0)
            {
                small.push_back('0');
                diff--;
                continue;
            }
            small.push_back(smol[i]);
        }
    }
    else 
    small=smol;
    bool carry=false;
    while(i>=0)
    {
        if(carry)
        {
            if(big[i]!=0)
            {
                big[i]--;
                carry=false;
            }
        }
        int last=(int)(big[i]-48);
        if(big[i]<small[i])
        {
            last+=10;
            carry=true;
        }
        result.push_back((char)(last-(small[i]-48)+48));
        i--;
    }
    reverse(result.begin(),result.end());
    return result;
}
void  solve()
{
    int n;
    cin>>n;
    string arr;
    cin>>arr;
    string result;
    string palin;
    if(arr[0]=='9')
    {
        int j=0;
        while(j!=n+1)
        {
            palin.push_back('1');
            j++;
        }
        result=subtraction(palin,arr);
        int p=0;
        string temp;
        while(p<result.size())
        {
            if(result[p]!='0')
            {
                temp.push_back(result[p]);
            }
            p++;

        }
        cout<<temp;
        return ;
    }
    int j=0;
    while(j!=n)
    {
        palin.push_back('9');
        j++;
    }
    result=subtraction(palin,arr);
    
    int p=0;
    string temp;
    while(p<result.size())
    {
        if(result[p]!='0')
        {
            temp.push_back(result[p]);
        }
        p++;
    }
    cout<<temp;
    return ;
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
    // string a="9999";
    // string b="111";
    // string c=subtraction(a,b);
    // cout<<c;
    return 0;
}