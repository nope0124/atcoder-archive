a=int(input())
h=a//3600
m=(a-h*3600)//60
s=a-h*3600-m*60
print(str(h).zfill(2)+":"+str(m).zfill(2)+":"+str(s).zfill(2))
