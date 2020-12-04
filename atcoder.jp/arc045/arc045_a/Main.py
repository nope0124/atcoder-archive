s=input().split()
list=[]
for i in s:
  if i=="Left":
    list.append("<")
  elif i=="Right":
    list.append(">")
  else:
    list.append(i[0])
print(*list)