a=int(input())
b=[int(input()) for i in range(a)]
print(len(b)-len(set(b)))