from __future__ import print_function
import sys

N, M, V = map(int, sys.stdin.readline().split())

graph = [[False for i in range(N+1)] for j in range(N+1)]

for e in range(M):
    a, b = map(int, sys.stdin.readline().split())
    graph[a][b] = True
    graph[b][a] = True


def dfs(graph, visited, cur, N):
    # check in
    print(cur, end =" ")
    visited[cur] = True
    
    # iterate
    for nxt in range(1, N+1):
        if not visited[nxt] and graph[cur][nxt]:
            dfs(graph, visited, nxt, N)

def bfs(graph, visited, startnode, N):
    queue = []
    queue.append(startnode)
    visited[startnode] = True
    while queue:
        cur = queue.pop(0)
        print(cur, end = " ")
        for nxt in range(1, N+1):
            if not visited[nxt] and graph[cur][nxt]:
                queue.append(nxt)
                visited[nxt] = True
  
visited = [False for i in range(N+1)]
dfs(graph, visited, V, N)
print("")
visited = [False for i in range(N+1)]
bfs(graph, visited, V, N)
print("")   
