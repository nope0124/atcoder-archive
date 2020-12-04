a=int(input())
b=list(map(int,input().split()))
sum=0
for i in range(a):
    if b[i]==2 or b[i]==4 or b[i]==8:
        sum+=1
    elif b[i]==5:
        sum+=2
    elif b[i]==6:
        sum+=3
print(sum)
