a,b=map(int,input().split())
c=[]
d=[list(map(int,input().split())) for i in range(b)]
for i in range(a):
  c.append(0)
for i in range(b):
  for j in range(d[i][0]-1,d[i][1]):
    c[j]=d[i][2]
for i in range(a):
  print(c[i])