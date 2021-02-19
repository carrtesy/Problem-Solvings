import sys
from queue import Queue
import time

class Data:
    def __init__(self, _id, priority):
        self._id = _id
        self.priority = priority

T = int(sys.stdin.readline())

for test_case in range(T):
    N, M = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    q = Queue()
    memo = [0] * 10
    for i in range(N):
        p = a[i]
        memo[p] += 1
        data = Data(i, p)
        q.put(data)
    
    ptr = 9
    cnt = 0
    while q:
        tmp = q.get()
        while memo[ptr] == 0:
            ptr -= 1
        if tmp.priority == ptr:
            memo[ptr] -= 1
            cnt += 1
            if tmp._id == M:
                break
        else:
            q.put(tmp)
    print(cnt)
