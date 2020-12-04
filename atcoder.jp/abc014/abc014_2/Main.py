a,b=map(int,input().split())
c=list(map(int,input().split()))
sum=0
for i in range(a):
  if format(b,"b").zfill(a)[i]=="1":
    sum+=c[a-i-1]
print(sum)