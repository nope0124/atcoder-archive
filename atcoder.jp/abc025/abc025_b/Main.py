a,b,c=map(int,input().split())
d=[list(map(str,input().split())) for i in range(a)]
e=0
for i in range(a):
  if d[i][0]=="East":
    if int(d[i][1])<b:
      e+=b
    elif b<=int(d[i][1])<=c:
      e+=int(d[i][1])
    else:
      e+=c
  else:
    if int(d[i][1])<b:
      e-=b
    elif b<=int(d[i][1])<=c:
      e-=int(d[i][1])
    else:
      e-=c
if e>0:
  print("East",abs(e))
elif e<0:
  print("West",abs(e))
else:
  print(0)