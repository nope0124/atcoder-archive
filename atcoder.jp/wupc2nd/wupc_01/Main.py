a=list(map(int,input().split()))
n=a[0]
m=a[1]
print((n*(n+1)*(2*n+1)//6)%m)