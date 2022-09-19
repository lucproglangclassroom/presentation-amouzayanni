#include <stdio.h>
#include <stdlib.h>

struct linkedListElement {
	struct linkedListElement* next;
	struct linkedListElement* prev;
	int number; // used for testing
};

struct linkedListElement *listHeadAddress = NULL;

void listAdd(struct linkedListElement *newListElementAddress) {
	if (listHeadAddress == NULL) {
		listHeadAddress = newListElementAddress;
		newListElementAddress->next = NULL;
		newListElementAddress->prev = NULL;
	}
	else
	{
		struct linkedListElement *current = listHeadAddress;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newListElementAddress;
		newListElementAddress->prev = current;
		newListElementAddress->next = NULL;
	}
}

void listRemove(struct linkedListElement *element) {
	struct linkedListElement *current = listHeadAddress;
	while (current != element)
	{
		current = current->next;
	}
	if (current == listHeadAddress)
	{
		listHeadAddress = current->next;
		current->next->prev = NULL;
	}
	else
	{
		current->next->prev = current->prev;
		current->prev->next = current->next;
	}
}

int main() {
	int numberOfListAdditions;
	int numberOfListRemovals;
	printf("Please enter your number of list additions: ");
	scanf("%d", &numberOfListAdditions);
	printf("\nPlease enter your number of list removals: ");
	scanf("%d", &numberOfListRemovals);
	printf("\nList structures after addition(s):\n");
	for (size_t i = 1; i <= numberOfListAdditions; i++)
	{
		struct linkedListElement* newElement = malloc(sizeof(struct linkedListElement));
		newElement->number = i;
		listAdd(newElement);
		struct linkedListElement* current = listHeadAddress;
		int listSize = i;
		for (size_t i = 0; i < listSize; i++)
		{
			printf("%d ", current->number);
			current = current->next;
		}
		printf("\n");
	}
	printf("\nList Structures after deletion(s):\n");
	int addtionsRemoved = 0;
	for (size_t i = 1; i <= numberOfListRemovals; i++)
	{
		listRemove(listHeadAddress);
		addtionsRemoved++;
		struct linkedListElement* current = listHeadAddress;
		for (size_t i = 1; i <= numberOfListAdditions - addtionsRemoved; i++)
		{
			printf("%d ", current->number);
			current = current->next;
		}
		printf("\n");
	}
    return 0;
}
