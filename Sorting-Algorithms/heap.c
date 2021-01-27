/*
	implementation of heap structure functions

	author: Dongmin Kim(dongmin.kim.0220@gmail.com)
*/

#include "heap.h"

// function for initializing Heap
void initHeap(MaxHeap * MH)
{
	// allocate space
	// and set len to be 0 
	MH->Data = (int*)malloc(sizeof(int)*100);
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

// push to the heap
void pushHeap(MaxHeap * MH, int data)
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
int popHeap(MaxHeap * MH)
{
	// 1. Get the last Node's data, and dec the len
	int root = MH->Data[1];
	int lastNodeData = MH->Data[(MH->len)--];

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


int emptyHeap(MaxHeap * MH)
{
	return MH->len == 0;
}

/*
int main(void)
{
	MaxHeap m;
	MaxHeap * MH = &m;
	initHeap(MH);
	printHeap(MH);
	pushHeap(MH, 3);
	pushHeap(MH, 2);
	pushHeap(MH, 4);
	pushHeap(MH, 1);
	pushHeap(MH, 5);
	printHeap(MH);
	popHeap(MH);
	printHeap(MH);
	popHeap(MH);
	printHeap(MH);
	popHeap(MH);
	printHeap(MH);
}
*/

