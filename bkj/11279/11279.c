#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct MH
{
	int * Data;
	int len;
} MaxHeap;

void initHeap(MaxHeap * MH, int numop)
{
	// allocate space
	// and set len to be 0 
	MH->Data = (uint32_t*)malloc(sizeof(uint32_t)*numop);
	MH->len = 0;
}

// function for printing Heap
void printHeap(MaxHeap * MH)
{
	int len = MH->len;
	printf("[ ");
	for (int i = 1; i <= len; i++)
	{
		printf("%d ", MH->Data[i]);
	}
	printf(" ]\n");
	
}

int emptyHeap(MaxHeap * MH)
{
	return MH->len == 0;
}


// push to the heap
void pushHeap(MaxHeap * MH, uint32_t data)
{
	// 1. increment len
	MH->len++;

	// 2. keep comparing with parent node
	
	// init
	int curIdx = MH->len;
	int parentIdx = curIdx/2;
	
	// repeat changing position
	// until a) child > parent and b) current posiiton is NOT root
	while(data > MH->Data[parentIdx] && curIdx != 1)
	{
		MH->Data[curIdx] = MH->Data[parentIdx];
		curIdx = parentIdx;
		parentIdx = curIdx/2; 
	}

	// 3. if loop has finished, put the data in current Node
	MH->Data[curIdx] = data;
}


int numChild(MaxHeap * MH, int idx)
{
	int lc = idx * 2;
	int len = MH->len;
	
	if(len < lc)
	{
		return 0;
	}
	else if(len == lc)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

// pop function
uint32_t popHeap(MaxHeap * MH)
{
	if(emptyHeap(MH)){
		return 0;
	}

	// 1. Get the last Node's data, and dec the len
	uint32_t root = MH->Data[1];
	uint32_t lastNodeData = MH->Data[(MH->len)--];

	// 2. percolade down
	// until a) parent < child and b) have child
	int p = 1;
	int lc = p * 2;
	int rc = p * 2 + 1;
	int n;

	while(1)
	{
		n = numChild(MH, p);
		if(n == 0)
		{
			// first case: do not have a child
			MH->Data[p] = lastNodeData;
			break;
		}
		else if(n == 1)
		{
			// second case: only left child
			if(lastNodeData < MH->Data[lc])
			{
				MH->Data[p] = MH->Data[lc];
				MH->Data[lc] = lastNodeData;
			}
			else
			{
				MH->Data[p] = lastNodeData;
			}
			break;
		}
		else
		{
			// third case: two childs
			int child = MH->Data[lc]>MH->Data[rc]? lc: rc;
			if(lastNodeData < MH->Data[child])
			{
				MH->Data[p] = MH->Data[child];
				p = child;
				lc = p * 2;
				rc = p * 2 + 1;	
			}
			else
			{
				MH->Data[p] = lastNodeData;
				break;
			}
		}

	}

	return root;
}


int main(void)
{

	int numop;
	uint32_t inputnum;
	scanf("%d", &numop);

	MaxHeap m;
	MaxHeap * MH = &m;
	initHeap(MH, numop);
	
	for(int i = 0; i < numop; i++){
		scanf("%u", &inputnum);
		if(inputnum == 0){
			printf("%u\n", popHeap(MH));
		} else {
			pushHeap(MH, inputnum);
		}

	}
}

