n = int(raw_input().strip())

lines = []

for i in xrange(n):
    columns = raw_input().strip()
    col = columns.split(' ')
    lines.append(col)

ll = raw_input().strip().split(" ")

k = int(ll[0])-1
rev = ll[1]
st = ll[2]

def cmp1(elem):
    global k
    return elem[k]

def cmp2(elem):
    global k
    return int(elem[k])

'''
if st == "lexicographic":
    if rev == "true":
        lines.sort(key = cmp1, reverse = True)
    else:
        lines.sort(key = cmp1, reverse = False)
else:
    if rev == "true":
        lines.sort(key = cmp2, reverse = True)
    else:
        lines.sort(key = cmp2, reverse = False)

for line in lines:
    for col in line:
        print col,
    print

'''

if st == "lexicographic":
    lines.sort(key = cmp1, reverse = False)
else:
    lines.sort(key = cmp2, reverse = False)

if rev == "true":
    for i in xrange(len(lines)-1,-1,-1):
        for j in lines[i]:
            print j,
        print
else:
    for i in xrange(len(lines)):
        for j in lines[i]:
            print j,
        print
