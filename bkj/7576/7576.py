import sys
from collections import deque

# input
M, N = map(int, sys.stdin.readline().rstrip().split())
field = []
visited = [[False for c in range(M)] for r in range(N)]
for i in range(N):
    row = list(map(int, sys.stdin.readline().rstrip().split()))
    field.append(row)
    

# init
queue = deque([])
for r in range(N):
    for c in range(M):
        if field[r][c] == 1:
            queue.append((r, c, 0))
            visited[r][c] = True

rstick = [1, -1, 0, 0]
cstick = [0, 0, 1, -1]
moves = 4

# loop
day = 0
from itertools import product
comb = [range(N), range(M)]
while queue:
    r, c, day = queue.popleft()
    field[r][c] = 1

    # another day
    for dr, dc in zip(rstick, cstick):
        nr, nc = r + dr, c + dc
        if (0 <= nr and nr < N) and (0 <= nc and nc < M):
            status = field[nr][nc]
            if status != 1 and status != -1 and (not visited[nr][nc]):
                queue.append((nr, nc, day+1))
                visited[nr][nc] = True

# check
success = True
for r in range(N):
    for c in range(M):
        if field[r][c] == 0:
            success = False
            break

if success:
    print(day)
else:
    print(-1)
