#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init_list(List *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->cur = NULL;
}

void add_to_list(List *list, int data)
{
	while (1)
	{
		Node * newNode;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;

		if (list->head == NULL)
			list->head = newNode;
		else
			list->tail->next = newNode;

		list->tail = newNode;
	}
}
void print_list(List *list)
{
	if (list->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		list->cur = list->head;
		printf("%d ", list->cur->data);

		while (list->cur->next != NULL) 
		{
			list->cur = list->cur->next;
			printf("%d ", list->cur->data);
		}
	}
}

void delete_list(List *list)
{
	if (list->head == NULL)
	{
		return 0;
	}
	else
	{
		Node * delNode = list->head;
		Node * delNextNode = list->head->next;

		printf("%d을(를) 삭제합니다. \n", list->head->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
}