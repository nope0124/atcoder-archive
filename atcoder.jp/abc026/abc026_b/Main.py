import math
a=int(input())
b=sorted([int(input()) for i in range(a)],reverse=True)
c=0
for i in range(a):
  c+=(-1)**i*b[i]**2
print(c*math.pi)