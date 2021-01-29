# Data Structure Package in C / CPP

compile
```
gcc -o main main.c stack.c
```

execute
```
./main
```

## LINKS
- [Stack][s]
- [Queue][q] : On working
- [Deque][d]

## Execution Result
- stack
```
This is how to INIT Stack...
Let's set Stack st, and Stack * s = &st; 
Call by function *initStack()*
This is how to push data to the stack...
we can push by calling function *push(s, i)*
Let's Pushing 1 to 100...
realloc called : 10 -> 20. (Capacity Increased)
realloc called : 20 -> 30. (Capacity Increased)
realloc called : 30 -> 40. (Capacity Increased)
realloc called : 40 -> 50. (Capacity Increased)
realloc called : 50 -> 60. (Capacity Increased)
realloc called : 60 -> 70. (Capacity Increased)
realloc called : 70 -> 80. (Capacity Increased)
realloc called : 80 -> 90. (Capacity Increased)
realloc called : 90 -> 100. (Capacity Increased)
realloc called : 100 -> 110. (Capacity Increased)

This is how to check the data of the stack...
we can check by calling function *checkStack(s)*
Let's print 1-100

Chunk 10 :1 2 3 4 5 6 7 8 9 10 
Chunk 20 :11 12 13 14 15 16 17 18 19 20 
Chunk 30 :21 22 23 24 25 26 27 28 29 30 
Chunk 40 :31 32 33 34 35 36 37 38 39 40 
Chunk 50 :41 42 43 44 45 46 47 48 49 50 
Chunk 60 :51 52 53 54 55 56 57 58 59 60 
Chunk 70 :61 62 63 64 65 66 67 68 69 70 
Chunk 80 :71 72 73 74 75 76 77 78 79 80 
Chunk 90 :81 82 83 84 85 86 87 88 89 90 
Chunk 100 :91 92 93 94 95 96 97 98 99 100 

This is how to pop the data of the stack...
we can pop by calling function *pop(s)*
Let's pop 47 times... 

which one is located at the top? use *top(s)*.
Data on top is 53
printing after poping...

Chunk 10 :1 2 3 4 5 6 7 8 9 10 
Chunk 20 :11 12 13 14 15 16 17 18 19 20 
Chunk 30 :21 22 23 24 25 26 27 28 29 30 
Chunk 40 :31 32 33 34 35 36 37 38 39 40 
Chunk 50 :41 42 43 44 45 46 47 48 49 50 
Chunk 60 :51 52 53 

poping until empty...
Is Stack Empty? Check *isEmpty(s)* function. 1
Let's Try poping for empty stack.
Stack is now empty. Nothing left to pop. exit.
```

[s]: https://github.com/dongminkim0220/Problem-Solvings/blob/master/data_structure_package/stack.c
[q]: https://github.com/dongminkim0220/Problem-Solvings/blob/master/data_structure_package/queue.c
[d]: https://github.com/dongminkim0220/Problem-Solvings/blob/master/data_structure_package/deque.cpp
