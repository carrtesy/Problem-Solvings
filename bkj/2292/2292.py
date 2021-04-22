x = int(input())

n = 1
while 3 * n * (n-1) + 1 < x:
    n += 1

print(n)
