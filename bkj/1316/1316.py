import sys

sys.stdin = open("input2.txt", 'r')

# get input
N = int(sys.stdin.readline().rstrip())
words = []
while N:
    word = sys.stdin.readline().rstrip()
    words.append(word)
    N -= 1

# algo
answer = 0
for w in words:
    alphabets = [0] * 26
    idx = 0
    isGroupWord = True
    while idx < len(w):
        char = w[idx]
        if alphabets[ord(char) - ord('a')]:
            isGroupWord = False
            break
        while True:
            idx += 1
            alphabets[ord(char) - ord('a')] += 1
            if idx >= len(w):
                break
            if w[idx] == char:
                idx += 1
                alphabets[ord(char) - ord('a')] += 1
            else:
                break
    answer += isGroupWord

print(answer)