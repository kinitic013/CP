t = int(input())
while(t>0):
    t = t-1;
    n = int(input())
    arr = list(map(int, input().split()))
    sum = 0;
    maxi = []
    mini = []
    maxi.append(abs(arr[0]))
    mini.append(arr[0])
    for i in range(1,len(arr)):
        curr_maxi = abs(max(maxi[i-1],abs(mini[i-1])) + arr[i])
        curr_mini = mini[i-1] + arr[i]
        maxi.append(curr_maxi)
        mini.append(curr_mini)

    print(max(maxi[-1],abs(mini[-1])))


