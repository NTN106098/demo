#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "DbLinkedList.h"
int main()
{
	int ch;

	start = NULL;
	temp = temp1 = NULL;

	printf("\n 1 - Insert");
	printf("\n 2 - Delete at i");
	printf("\n 3 - Display");
	printf("\n 4 - Search for element");
	printf("\n 5 - Sort the list");
	printf("\n 6 - Update an element");
	printf("\n 7 - Exit");

	while (1)
	{
		printf("\n Enter choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			traversebeg();
			break;
		case 4:
			search();
			break;
		case 5:
			sort();
			break;
		case 6:
			update();
			break;
		case 7:
			exit(0);
		default:
			printf("\n Wrong choice menu");
		}
	}
	_getch();
}