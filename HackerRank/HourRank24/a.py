n=int(raw_input().strip())
s=str(raw_input().strip())
num="0123456789"
lc="abcdefghijklmnopqrstuvwxyz"
uc="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
sc="!@#$%^&*()-+"

c=[0,0,0,0]

for i in xrange(len(s)):
    if s[i] in num:
        c[0]+=1
    if s[i] in lc:
        c[1]+=1
    if s[i] in uc:
        c[2]+=1
    if s[i] in sc:
        c[3]+=1

nf=0
for i in xrange(4):
    if c[i]==0:
        nf+=1

if len(s)>=6:
    print nf
else:
    if nf>6-len(s):
        print nf
    else:
        print 6-len(s)
