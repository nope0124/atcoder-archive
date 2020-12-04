a=list(input())
b=[1]
c=1
d=[]
for i in range(len(a)-1):
  if a[i]==a[i+1]:
    c+=1
  else:
    c=1
    d+=[a[i]+str(b[-1])]
  b+=[c]
d+=[a[len(a)-1]+str(b[-1])]
print(*d,sep="")