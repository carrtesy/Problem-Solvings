/*
	heap structure - header file

	author: Dongmin Kim(dongmin.kim.0220@gmail.com)
*/

#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct MH
{
	int * Data;
	int len;
} MaxHeap;

void initHeap(MaxHeap * MH);

void printHeap(MaxHeap * MH);

void pushHeap(MaxHeap * MH, int data);

int numChild(MaxHeap * MH, int idx);

int popHeap(MaxHeap * MH);

int emptyHeap(MaxHeap * MH);

#endif
