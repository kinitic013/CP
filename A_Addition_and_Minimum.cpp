#include<bits/stdc++.h>
using namespace std;
vector<long long> segTree;
vector<long long> lazySegTree;

// 
void build(vector<long long>& arr, long long start , long long end , long long index)
{
    if(start == end)
    {
        segTree[index] = arr[start];
        return; 
    }
    long long mid = (start + end)/2;
    long long left = index*2+1;
    long long right = index*2 + 2;
    build(arr,start,mid,left);
    build(arr,mid+1,end,right);
    segTree[index] = min(segTree[left],segTree[right]);
}
void rangeUpdate(vector<long long>& arr, long long start, long long end, long long index, long long l, long long r, long long value) {
    long long segTreeSize = segTree.size();
    long long left = index * 2 + 1;
    long long right = index * 2 + 2;
    long long mid = (start + end) / 2;

    // Apply pending lazy updates
    if (lazySegTree[index] != 0) {
        segTree[index] += lazySegTree[index];
        if (start != end) { // Propagate lazy value to children
            lazySegTree[left] += lazySegTree[index];
            lazySegTree[right] += lazySegTree[index];
        }
        lazySegTree[index] = 0;
    }

    // No overlap
    if (r < start || l > end) {
        return;
    }

    // Total overlap
    if (start >= l && end <= r) {
        segTree[index] += value;
        if (start != end) { // Update lazy for children
            lazySegTree[left] += value;
            lazySegTree[right] += value;
        }
        return;
    }

    // Partial overlap
    rangeUpdate(arr, start, mid, left, l, r, value);
    rangeUpdate(arr, mid + 1, end, right, l, r, value);
    segTree[index] = min(segTree[left], segTree[right]); // Update the current node
}

long long queryRange(long long start, long long end, long long index, long long l, long long r) {
    long long segTreeSize = segTree.size();
    long long left = index * 2 + 1;
    long long right = index * 2 + 2;
    long long mid = (start + end) / 2;

    // Apply pending lazy updates
    if (lazySegTree[index] != 0) {
        segTree[index] += lazySegTree[index];
        if (start != end) { // Propagate lazy value to children
            lazySegTree[left] += lazySegTree[index];
            lazySegTree[right] += lazySegTree[index];
        }
        lazySegTree[index] = 0;
    }

    // No overlap
    if (r < start || l > end) {
        return LONG_LONG_MAX;
    }

    // Total overlap
    if (start >= l && end <= r) {
        return segTree[index];
    }

    // Partial overlap
    long long leftValue = queryRange(start, mid, left, l, r);
    long long rightValue = queryRange(mid + 1, end, right, l, r);
    return min(leftValue, rightValue);
}

int main()
{
    long long n,q;cin>>n>>q;
    vector<long long> arr(n,0);
    segTree.resize(4*n,0);
    lazySegTree.resize(4*n,0);
    
    build(arr,0,n-1,0);
    // polong longUpdate(arr,0,n-1,0,3,10);
    for(long long i=0;i<q;i++)
    {
        long long type;cin>>type;
        long long l,r;cin>>l>>r;
        r--;
        if(type == 1)
        {
            long long v;cin>>v;
            rangeUpdate(arr,0,n-1,0,l,r,v);
        }
        else
        {
            cout<<queryRange(0,n-1,0,l,r)<<"\n";
        }
    }
    // cout<<queryRange(0,n-1,0,0,0)<<endl;
    // rangeUpdate(arr,0,n-1,0,4,7,10);
    // cout<<queryRange(0,n-1,0,0,5)<<endl;
    // for(auto x : segTree)  
    // cout<<x<<" ";
    // cout<<endl;

    // for(auto x : lazySegTree)  
    // cout<<x<<" ";
    // cout<<endl;
    return 0;
}
