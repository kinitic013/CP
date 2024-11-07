#include<bits/stdc++.h>
using namespace std;
vector<int> segTree;
vector<int> lazySegTree;

// 
void build(vector<int>& arr, int start , int end , int index)
{
    if(start == end)
    {
        segTree[index] = arr[start];
        return; 
    }
    int mid = (start + end)/2;
    int left = index*2+1;
    int right = index*2 + 2;
    build(arr,start,mid,left);
    build(arr,mid+1,end,right);
    segTree[index] = (segTree[left]+segTree[right]);
}
void rangeUpdate(vector<int>&arr , int start , int end , int index , int l , int r , int value)
{
    int n = arr.size();
    int left = index*2 + 1;
    int right = index*2 + 2;
    int mid = (start + end )/2;

    if(lazySegTree[index]!=0)// some update query is queued
    {
        segTree[index] += lazySegTree[index]*(end-start+1);
        if(left<4*n)// physically present 
        lazySegTree[left] +=lazySegTree[index];
        if(right<4*n)// physically present 
        lazySegTree[right] +=lazySegTree[index];

        lazySegTree[index] = 0;
    }
    // if current node contributes entirely
    if(start>=l && end<=r)
    {
        segTree[index] += (end-start+1)*value;
        if(left<4*n)// physically present 
        lazySegTree[left] +=value;
        if(right<4*n)// physically present 
        lazySegTree[right] +=value;
    }
    // if current node contribute nothing
    else if(r<start || end<l)
    {
        // return {INT_MAX,INT_MAX};
    }
    // if contributes partially
    else
    {
        rangeUpdate(arr,start,mid,left,l,r,value);
        rangeUpdate(arr,mid+1,end,right,l,r,value);
    }
}
int queryRange(int start,int end , int index , int l , int r)// sum of l to R
{
    int n = lazySegTree.size();
    int left = index*2 + 1;
    int right = index*2 + 2;
    int mid = (start + end )/2;

    if(lazySegTree[index]!=0)// some update query is queued
    {
        segTree[index] += lazySegTree[index]*(end-start+1);
        if(left<n)// physically present 
        lazySegTree[left] +=lazySegTree[index];
        if(right<n)// physically present 
        lazySegTree[right] +=lazySegTree[index];

        lazySegTree[index] = 0;
    }
    
    // if current node contributes entirely

    if(start>=l && end<=r)
    {
        return segTree[index];
    }
    // if current node contribute nothing
    else if(r<start || end<l)
    {
        return 0;
    }
    // if contributes partially
    else
    {
        int leftValue = queryRange(start,mid,left,l,r);
        int rightValue = queryRange(mid+1,end,right,l,r);
        return leftValue + rightValue;
    }
    return 0;
}

int main()
{
    int n;cin>>n;
    vector<int> arr(n);
    segTree.resize(4*n,0);
    lazySegTree.resize(4*n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(arr,0,n-1,0);
    // pointUpdate(arr,0,n-1,0,3,10);
    cout<<queryRange(0,n-1,0,0,0)<<endl;
    rangeUpdate(arr,0,n-1,0,4,7,10);
    cout<<queryRange(0,n-1,0,0,5)<<endl;
    for(auto x : segTree)  
    cout<<x<<" ";
    cout<<endl;

    for(auto x : lazySegTree)  
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
