n=int(raw_input().strip())
a=str(raw_input().strip()).split(' ')

cl1={}
for i in a:
    try:
        cl1[i]+=1
    except:
        cl1[i]=1

m=int(raw_input().strip())
b=str(raw_input().strip()).split(' ')

cl2={}
for i in b:
    try:
        cl2[i]+=1
    except:
        cl2[i]=1

ub=list(set(b))
missing=[]
for i in ub:
    if cl2[i]!=cl1[i]:
        missing.append(i)

missing.sort()

for i in missing:
    print i,
