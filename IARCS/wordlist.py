n = int(raw_input().strip())
wl = []
for i in range(n):
    wds = str(raw_input()).strip()
    wds = wds.replace("'"," ").replace("."," ").replace(","," ").replace(";"," ").replace(":"," ").replace("\t"," ").replace("\n"," ")
    wds = wds.split(" ")
    for j in wds:
        wl.append(j.lower())

wl = set(wl)
wl = list(wl)
wl.sort()

print len(wl)-1,
for i in wl:
    print i
