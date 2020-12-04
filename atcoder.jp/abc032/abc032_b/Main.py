a=input()
b=int(input())
c=set()
for i in range(len(a)-b+1):
  c.add(a[i:i+b])
print(len(c))