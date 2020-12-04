a=int(input())
b=list(map(int,input().split()))
c,d,e=0,0,0
if sum(b)%a!=0:
  print(-1)
else:
  c=sum(b)//a
  for i,j in enumerate(b):
    d+=j
    if c*(i+1)!=d:
      e+=1
  print(e)