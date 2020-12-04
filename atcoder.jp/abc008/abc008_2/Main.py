from collections import Counter
a=int(input())
b=dict(Counter([input() for i in range(a)]))
print(max(b,key=b.get))