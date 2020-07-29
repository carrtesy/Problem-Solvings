#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BSYS 31 //base number system.

struct h;

typedef struct hd {
  int cnt; // counting data of hashdata arr
  int cap; // capacity of hashdata arr
  int * arr;
  struct h* nexthash;
} hashdata;

typedef struct h {
  hashdata hasharr[BSYS];
} hashtable;

void initHash(hashtable * h)
{
  for(int i = 0; i < BSYS; i++)
  {
    h->hasharr[i].cnt = 0;
    h->hasharr[i].cap = 2;
    h->hasharr[i].arr = (int *) malloc(sizeof(int) * 2);
    h->hasharr[i].nexthash = NULL;
  }
}

int getmod(int b, int d, int n) // b: base, d: digit, n:number to evaluate 
{
  int num = n;
  for(int i = 1; i < d; i++) num = num/BSYS;
  return num % BSYS;
}


int main(int argc, char * argv[])
{
  // init.
	// 1. connect inputfile
	char * filename = argv[1];
	FILE * inputfile = fopen(filename, "r");
  int data;
  int result = -1;
  int digit;

  hashtable ht;
  hashtable * h = &ht;
  hashtable * ch; // current hash table to evaluate
  initHash(h);


  // first loop.
	while(1)
	{
		// break condition: end of file
		if(fscanf(inputfile, "%d\n", &data) == EOF) break;

    hashdata curhash;
    curhash = h->hasharr[getmod(BSYS, 1, data)];
    curhash.arr[curhash.cnt++] = data;

    //realloc mechanism
    if(curhash.cnt >= curhash.cap) {
      curhash.cap = curhash.cap + 2;
      curhash.arr = (int *) realloc(curhash.arr, sizeof(int) * curhash.cap);
    }
  }


  // second to last loop
  ch = h;
  digit = 2;

  while (1)
  {  
    int curcnt;
    int curidx;
    int * curarr;

    for(int i = 0; i < BSYS; i++)
    {
      curcnt = ch->hasharr[i].cnt;
      if(curcnt % 2){
        curidx = i;
        curarr = ch->hasharr[i].arr;
        break;
      } 
    }

    if(curcnt == 1) {
      result = curarr[0];
      break;
    } else {
      ch = ch->hasharr[curidx].nexthash;
      ch = (hashtable *)malloc(sizeof(hashtable));
      initHash(ch);

      // iterate curarr
      for(int i = 0; i < curcnt; i++) {
        int data = curarr[i];
        hashdata curhash;

        curhash = ch->hasharr[getmod(BSYS, digit, data)];
        curhash.arr[curhash.cnt++] = data;

        if(curhash.cnt >= curhash.cap) {
          curhash.cap = curhash.cap + 2;
          curhash.arr = (int *) realloc(curhash.arr, sizeof(int) * curhash.cap);
        }
      }

      digit++;
    }
  
  }

  printf("Result : %d\n", result);
}
