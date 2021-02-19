import sys

def paramSearch(arr, K, N):
    s = 1
    e = max(arr)
    answer = None
    while s <= e:
        m = (s + e) // 2
        numCables = sum([a // m for a in arr])
        if numCables >= N:
            answer = m
            s = m + 1
        else:
            e = m - 1
    return answer

K, N = map(int, sys.stdin.readline().split())
arr = [int(sys.stdin.readline()) for i in range(K)]
print(paramSearch(arr, K, N))
