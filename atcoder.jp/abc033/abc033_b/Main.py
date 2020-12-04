a=int(input())
b=[]
c=[]
for i in range(a):
  p,q=input().split()
  b.append(p)
  c.append(int(q))
if max(c)>sum(c)/2:
  print(b[c.index(max(c))])
else:
  print('atcoder')
