import sys
N, M = map(int, sys.stdin.readline().split())
Dogam = dict()
for i in range(N):
    pokemon = sys.stdin.readline().rstrip()
    Dogam[pokemon] = i + 1
    Dogam[i+1] = pokemon

for i in range(M):
    query = input()
    if query.isdigit():
        print(Dogam[int(query)])
    else:
        print(Dogam[query])
