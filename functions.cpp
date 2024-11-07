#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool is_palindrome(string arr)//check wheather a string is palindrome or not
{
    string reverse="";
    int n=arr.size();
    reverse.resize(n);
    for(int i=0;i<n;i++)
    {
        reverse[i]=arr[n-i-1];
    }
    
    if(arr.compare(reverse)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void print(vector<int> arr)//printing a vector
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    string a="aba";
    cout<<is_palindrome(a);
    return 0;
}
vector<pair<int,int>> table_count(vector<int> arr)//returns a table that contain count of each element in a vector
{
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<pair<int,int>> list;
    int count=1;
    bool corner=false;
    for(int i=0;i<n-1;i++)
    {
        if(i==n-2)
        {
            if(arr[n-1]==arr[n-2])
            {
                corner=true;
            }
        }
        if(arr[i]==arr[i+1])
        {
            count++;
        }
        else
        {
            list.push_back(make_pair(arr[i],count));
            count=1;
        }
        if(corner && i==n-2)//if n-1 and n-2 th element are same
        {
            list.push_back(make_pair(arr[n-1],count));
        }
        else if(i==n-2)//if not same push_back for last element
        {
            list.push_back(make_pair(arr[n-1],count));
        }
    }
    return list;
}
template<typename t2>
bool cmp(pair<char,t2> a,pair<char,t2> b)
{
    return a.second<b.second;
}
/*
int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        auto it=find(arr.begin(),arr.end(),ele);
        if(it==arr.end())//distinct
        {
            arr.push_back(ele);
        }
    }
*/