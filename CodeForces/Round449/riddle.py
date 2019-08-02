def query(n,k):
    f = {}
    f[0] = '''What are you doing at the end of the world? Are you busy? Will you save us?'''
    for i in xrange(1,n+1,1):
        f[i]='''What are you doing while sending "''' + f[i-1] + '''"? Are you busy? Will you send "''' + f[i-1] + '''"?'''

    if len(f[n])<k:
        return '.'
    else:
        return f[n][k-1]

q=int(raw_input().strip())

ans=""
for i in xrange(q):
    args = map(int, raw_input().strip().split(' '))
    n=args[0]
    k=args[1]
    ans+=query(n,k)

print ans
