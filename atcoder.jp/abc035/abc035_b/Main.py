a=input()
b=int(input())
x=a.count("U")-a.count("D")
y=a.count("R")-a.count("L")
c=abs(x)+abs(y)
if b==1:
  print(c+a.count("?"))
else:
  if c>a.count("?"):
    print(c-a.count("?"))
  else:
    print((a.count("?")-c)%2)