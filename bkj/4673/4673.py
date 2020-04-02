'''
Source: https://www.acmicpc.net/problem/4673
By Dongmin Kim(dongmin.kim.0220@gmail.com)
'''


# function to get the digit of the number
def getDigit(n):
    digit = 1;

    while(n % (10**digit) != n):
        digit+=1

    return digit

# function d(n), which sums the digits, and the number itself
def d(n):
    sum = n
    digit = getDigit(n)

    for i in range(1, digit+1):
        tmp = n %(10)
        n = int(n/10)
        sum +=tmp

    return sum

# memorize the result at the seq -> to speed up
def memoSeq(arr, num, limit):
    n = num

    while(True):
        n = d(n)

        # if selfNum(n) is out of boundary, break.
        if(n > limit):
            break;
        arr[n] = 1


# 1. init
n = 10000
memo = list(bytearray(n+1)) # memorize the data - first index is for 0 (dummy allocation)

# 2. iterate
for i in range(1, n+1):

    # pass if the number has already been considered
    if(memo[i] == 1):
        continue

    # finite loop
    memoSeq(memo, i, n)

    # print if it is selfNum
    if(memo[i] == 0):
        print(i)