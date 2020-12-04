a=input()
b,c=map(int,input().split())
d=input()
e=list(map(int,input().split()))
if len(set(e))==len(e) and b not in e and c not in e:
  print("YES")
else:
  print("NO")