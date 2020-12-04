a=list(input())
for i in range(len(a)):
  if i==0:
    a[i]=a[i].upper()
  else:
    a[i]=a[i].lower()
print(*a,sep="")