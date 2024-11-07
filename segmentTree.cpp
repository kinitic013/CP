#include<bits/stdc++.h>
using namespace std;
vector<int> segTree;
vector<int> segSecondMin;


void build(vector<int>& arr, int start , int end , int index)
{
    if(start == end)
    {
        segTree[index] = arr[start];
        segSecondMin[index] = INT_MAX;
        return; 
    }
    int mid = (start + end)/2;
    int left = index*2+1;
    int right = index*2 + 2;
    build(arr,start,mid,left);
    build(arr,mid+1,end,right);
    segTree[index] = min(segTree[left],segTree[right]);
    segSecondMin[index] = min(max(segTree[left],segTree[right]),min(segSecondMin[left],segSecondMin[right]));
}
void update(vector<int>& arr , int start , int end , int index , int pos , int value)
{
    if(start == end)
    {
        arr[pos] = value;
        segTree[index] = value;
        segSecondMin[index] = INT_MAX;
        return;
    }
    int mid = (start + end)/2;
    int left = index*2 + 1;
    int right = index*2 + 2;
    if(pos<=mid)
    {
        update(arr,start,mid,left,pos,value);
    }
    else
    {
        update(arr,mid+1,end,right,pos,value);
    }
    segTree[index] = min(segTree[left],segTree[right]);
    segSecondMin[index] = min(max(segTree[left],segTree[right]),min(segSecondMin[left],segSecondMin[right]));
}
pair<int,int> query(int start,int end , int index , int l , int r)
{
    int left = index*2 + 1;
    int right = index*2 + 2;
    int mid = (start + end )/2;
    // if current node contributes entirely
    if(start>=l && end<=r)
    {
        return { segTree[index] , segSecondMin[index]};
    }
    // if current node contribute nothing
    else if(r<start || end<l)
    {
        return {INT_MAX,INT_MAX};
    }
    // if contributes partially
    else
    {
        pair<int,int> leftValue = query(start,mid,left,l,r);
        pair<int,int> rightValue = query(mid+1,end,right,l,r);
        return {min(leftValue.first,rightValue.first),min(max(leftValue.first,rightValue.first),min(leftValue.second,rightValue.second))};
    }
    return {INT_MAX,INT_MAX};
}

int main()
{
    int n;cin>>n;
    vector<int> arr(n);
    segTree.resize(4*n,INT_MAX);
    segSecondMin.resize(4*n,INT_MAX);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(arr,0,n-1,0);
    // update(arr,0,n-1,0,3,10);
    cout<<query(0,n-1,0,5,5).second<<endl;
    for(auto x : segTree)  
    cout<<x<<" ";
    cout<<endl;

    for(auto x : segSecondMin)  
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
