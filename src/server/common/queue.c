/**
 * queue.c file
 * @author    Aaron.Shao
 * @brief     The queue function
 * @date      2019-06-19
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
#include <stdlib.h>
#include "NUC029xGE.h"
#include "tym_global.h"
#include "queue.h"

void InitQueue(QNODE *Q)
{
	NODE *p;
	Q =(QNODE *)malloc(sizeof(QNODE));
	Q->front->next=NULL;
	printf("Queue init is complete!");
}

int QueuePush(QNODE *Q, uint8_t cmd, uint8_t data)
{
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	p->tym_cmd = cmd;
	p->tym_data = data;
	//tym_cmd =cmd;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	printf("The 0x%x has been pushed into the Queue!",p->tym_cmd);/*显示数据成员*/
	return 0;
}

int QueuePop(QNODE *Q, NODE *p)
{
	if(Q->front->next==NULL) return 0;/*判断对前是否为空，如果是就结束*/
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p) 
	{
		Q->rear=Q->front;/*队尾与对头相同*/
		printf("The %d has been pop from the queue! \n",p->tym_cmd);/*显示队列成员*/
	}
	return 0;
}

int PrintQueue(QNODE *Q)
{
	NODE *p;
	p=Q->front->next;
	while(p!=NULL)
	{
		printf("%5d",p->tym_cmd);
		p=p->next;
	}
	return 0;
} 

void test_main()
{
	QNODE *T;
	NODE *p;
	int i=0;
	printf("1.InitQueue 2.QueuePush 3.QueuePop 4.PrintQueue 5.Quit \n");
	while(i!=5)
	{
		printf("Please choose the gongneng:");
		scanf("%d",&i);
		printf("\n");
		switch(i)
		{
		case 1: InitQueue(T); printf("\n"); break;
		case 2: QueuePush(T,12,0); printf("\n"); break;
		case 3: QueuePop(T,p); printf("\n"); break;
		case 4: printf("The queue's numbers are:");
		PrintQueue(T); printf("\n"); break;
		case 5: printf("\n"); break;}
	}
}
