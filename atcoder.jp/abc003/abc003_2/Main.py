sum=0
a=input()
b=input()
for i in range(len(a)):
  if a[i]==b[i] or (a[i] in "atcoder" and b[i]=="@") or (b[i] in "atcoder" and a[i]=="@"):
    sum+=1
print("You can win" if sum==len(a) else "You will lose")