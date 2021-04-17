import sys

while True:
    a = sys.stdin.readline()
    if a[0] == "." and len(a) == 2:
        break
    stack = []
    balanced = True
    for c in a:
        if c not in "[]()":
            continue
        else:
            if c in "[(":
                stack.append(c)
            else:
                if not stack:
                    balanced = False
                    break
                elif c == "]":
                    if stack[-1] != "[":
                        balanced = False
                        break
                    else:
                        stack.pop()
                elif c == ")":
                    if stack[-1] != "(":
                        balanced = False
                        break
                    else:
                        stack.pop()
    if stack:
        balanced = False
    if balanced:
        print("yes")
    else:
        print("no")                
