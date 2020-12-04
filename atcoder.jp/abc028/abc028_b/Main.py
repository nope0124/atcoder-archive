a,b,c,d,e,f=0,0,0,0,0,0
l=list(input())
for i in range(len(l)):
  if l[i]=="A":
    a+=1
  elif l[i]=="B":
    b+=1
  elif l[i]=="C":
    c+=1
  elif l[i]=="D":
    d+=1
  elif l[i]=="E":
    e+=1
  else:
    f+=1
print(a,b,c,d,e,f)