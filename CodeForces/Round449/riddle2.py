f = {}
f[0] = '''What are you doing at the end of the world? Are you busy? Will you save us?'''

q=int(raw_input().strip())

mn=-1
a=[]

for i in xrange(q):
    args = map(int, raw_input().strip().split(' '))
    n=args[0]
    k=args[1]
    if n>mn:
        mn=n
    a.append([n,k])

for i in xrange(1,mn+1,1):
    f[i]='''What are you doing while sending "''' + f[i-1] + '''"? Are you busy? Will you send "''' + f[i-1] + '''"?'''


ans=""
for i in a:
    x=i[0]
    y=i[1]
    if len(f[x])<y:
        ans+='.'
    else:
        ans+=f[x][y-1]

print(ans)
