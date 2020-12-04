a=input()
b=[]
for i in a:
  if i not in 'aiueo':
    b.append(i)
print(*b,sep="")
