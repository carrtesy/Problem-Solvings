'''
Source: https://www.acmicpc.net/problem/2908
By Dongmin Kim(dongmin.kim.0220@gmail.com)
'''

# function to reverse the input integer. returns integer.
def getReverseNum(n):
    nStr = str(n)
    resultStrList = []

    for i in range(len(nStr), 0, -1):
        resultStrList.append(nStr[i-1])

    return int(''.join(resultStrList))


a, b = input().split()

a = getReverseNum(int(a))
b = getReverseNum(int(b))

result = a if a>b else b

print(result)