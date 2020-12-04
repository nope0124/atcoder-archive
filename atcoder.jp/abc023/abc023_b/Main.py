a=int(input())
b=input()
c=['b']
for i in range(1,500):
  if i%3==0:
    c+=['b'+c[-1]+'b']
  elif i%3==1:
    c+=['a'+c[-1]+'c']
  elif i%3==2:
    c+=['c'+c[-1]+'a']
if b in c:
  print(c.index(b))
else:
  print(-1)
