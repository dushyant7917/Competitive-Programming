import sys
n = raw_input()
lines = sys.stdin.readlines()
lines.sort(key=int)
for i in lines:
    print i.strip()
