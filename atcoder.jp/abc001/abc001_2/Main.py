a=int(input())
if a<100:
  print("00")
elif a>=100 and a<1000:
  print("0"+str(int(a/100)))
elif a>=1000 and a<=5000:
  print(int(a/100))
elif a>=6000 and a<=30000:
  print(int(a/1000)+50)
elif a>=35000 and a<=70000:
  print(int(((a/1000)-30)/5)+80)
else:
  print("89")