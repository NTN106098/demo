#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int Id;
	char data[50];
	struct node *next;
}*start, *temp, *temp1, *temp2, *temp3;

void insert();
void sort();
void search();
void traversebeg();
void update();
void del();

int count = 0;

/* TO create an empty node */
void create()
{
	int data;

	temp = (struct node *)malloc(1 * sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\n Enter value to node : ");
	scanf("%d", &data);
	temp->Id = data;
	count++;
}

/*To insert an element*/
void insert()
{
	if (start == NULL)
	{
		create();
		start = temp;
		temp1 = start;
	}
	else
	{
		create();
		temp->next = start;
		start->prev = temp;
		start = temp;
	}
}

/* To delete an element */
void del()
{
	int i = 1, pos;

	printf("\n Enter position to be deleted : ");
	scanf("%d", &pos);
	temp2 = start;

	if ((pos < 1) || (pos >= count + 1))
	{
		printf("\n Error : Position out of range to delete");
		return;
	}
	if (start == NULL)
	{
		printf("\n Error : Empty list no elements to delete");
		return;
	}
	else
	{
		while (i < pos)
		{
			temp2 = temp2->next;
			i++;
		}
		if (i == 1)
		{
			if (temp2->next == NULL)
			{
				printf("Node deleted from list");
				free(temp2);
				temp2 = start = NULL;
				return;
			}
		}
		if (temp2->next == NULL)
		{
			temp2->prev->next = NULL;
			free(temp2);
			printf("Node deleted from list");
			return;
		}
		temp2->next->prev = temp2->prev;
		if (i != 1)
			temp2->prev->next = temp2->next;    /* Might not need this statement if i == 1 check */
		if (i == 1)
			start = temp2->next;
		printf("\n Node deleted");
		free(temp2);
	}
	count--;
}
/*Display*/
void traversebeg()
{
	temp2 = start;

	if (temp2 == NULL)
	{
		printf("List empty to display \n");
		return;
	}
	printf("\n Linked list elements from begining : ");

	while (temp2->next != NULL)
	{
		printf(" %d ", temp2->Id);
		temp2 = temp2->next;
	}
	printf(" %d ", temp2->Id);
}
/* To search for an element in the list */
void search()
{
	int data, count = 0;
	temp2 = start;

	if (temp2 == NULL)
	{
		printf("\n Error : List empty to search for data");
		return;
	}
	printf("\n Enter value to search : ");
	scanf("%d", &data);
	while (temp2 != NULL)
	{
		if (temp2->Id == data)
		{
			printf("\n Data found in %d position", count + 1);
			return;
		}
		else
			temp2 = temp2->next;
		count++;
	}
	printf("\n Error : %d not found in list", data);
}

/* To update a node value in the list */
void update()
{
	int data, data1;

	printf("\n Enter node data to be updated : ");
	scanf("%d", &data);
	printf("\n Enter new data : ");
	scanf("%d", &data1);
	temp2 = start;
	if (temp2 == NULL)
	{
		printf("\n Error : List empty no node to update");
		return;
	}
	while (temp2 != NULL)
	{
		if (temp2->Id == data)
		{

			temp2->Id = data1;
			traversebeg();
			return;
		}
		else
			temp2 = temp2->next;
	}

	printf("\n Error : %d not found in list to update", data);
}

/* To sort the linked list */
void sort()
{
	int i, j, x;

	temp2 = start;
	temp3 = start;

	if (temp2 == NULL)
	{
		printf("\n List empty to sort");
		return;
	}

	for (temp2 = start; temp2 != NULL; temp2 = temp2->next)
	{
		for (temp3 = temp2->next; temp3 != NULL; temp3 = temp3->next)
		{
			if (temp2->Id > temp3->Id)
			{
				x = temp2->Id;
				temp2->Id = temp3->Id;
				temp3->Id = x;
			}
		}
	}
	traversebeg();
}
