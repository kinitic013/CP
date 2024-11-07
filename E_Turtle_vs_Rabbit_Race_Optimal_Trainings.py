import bisect


t = int(input())  # Number of test cases

for _ in range(t):
    n = int(input())  # Size of the array
    arr = list(map(int, input().split()))  # Array elements
    arr.insert(0,0)
    # print(arr)
    res = []

    sum = 0
    pre = [0]
    for i in range(1,n+1):
        ele = arr[i]
        sum += ele
        pre.append(sum) 

    q = int(input())
    for j in range(q):
        r, u = map(int, input().split()) 
        # print(r,u)
        total = (u*(u+1)/2)
        target = pre[r-1] + u
        pos = bisect.bisect_right(pre,target,1)
        idx = r
        ans = float('-inf')
        if pos != n+1 :
            # print(n,pos,r)
            current = pre[pos] - pre[r-1]
            extra = current - u ;
            result1 = total - (extra*(extra-1)/2)
            if result1 >= ans:
                idx = pos
                ans = result1
            
        if pos != r :
            pos -= 1
            current = pre[pos] - pre[r-1]
            extra = u - current
            result1 = total - (extra*(extra+1)/2)
            if result1 >= ans:
                idx = pos
                ans = result1
        res.append(idx)
    for i in range(0,q):
        print(res[i],end = " ")
    print("\n") 






