a,b=map(int,input().split())
c=[int(input()) for _ in range(a)]
d=0
for i in range(1,a):
  if c[i]-c[i-1]>=b:
    d+=b
  else:
    d+=c[i]-c[i-1]
print(d+b)