a=[input() for i in range(12)]
sum=0
for i in range(12):
  if "r" in a[i]:
    sum+=1
print(sum)