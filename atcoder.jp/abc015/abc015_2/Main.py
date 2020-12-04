import math
a=int(input())
b=[]
sum=0
c=list(map(int,input().split()))
for i in range(a):
  if c[i]!=0:
    b.append(c[i])
    sum+=c[i]
print(math.ceil(sum/len(b)))