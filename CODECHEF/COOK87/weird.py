t=int(raw_input().strip())
while(t>0):
    t=t-1
    y=int(raw_input().strip())
    ans=0
    i=1
    while i*i<y:
        ans+=y-(i*i)
        i=i+1
    print ans
