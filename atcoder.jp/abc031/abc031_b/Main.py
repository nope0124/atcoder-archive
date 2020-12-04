a,b=map(int,input().split())
c=int(input())
d=[int(input()) for i in range(c)]
for i in range(c):
  if d[i]<a:
    print(a-d[i])
  elif a<=d[i]<=b:
    print(0)
  elif b<d[i]:
    print(-1)