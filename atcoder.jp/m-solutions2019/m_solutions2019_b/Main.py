xcounter=0
a=list(input())
for i in range(len(a)):
  if a[i]=="x":
    xcounter+=1
if xcounter>=8:
  print("NO")
else:
  print("YES")
    