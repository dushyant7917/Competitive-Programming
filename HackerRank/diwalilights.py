t=int(raw_input().strip())
m=100000
for i in range(t):
    n=int(raw_input().strip())
    print ((2**n)-1)%m
