#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node *next;
};

struct node *head = NULL;

void insertbig(int value) 
{
    struct node *new1, *temp;
    new1 = (struct node *)malloc(sizeof(struct node));
    
    if (new1 == NULL) 
	{
        printf("Overflow\n");
        exit(0);
    }

    new1->info = value;

    if (head == NULL) 
	{
        head = new1;
        new1->next = head;
    } 
	else 
	{
        temp = head;
        while (temp->next != head)
		 {
            temp = temp->next;
        }
        new1->next = head;
        temp->next = new1;
        head = new1;
    }
}

void insertEnd(int value)
 {
    struct node *new1, *temp;
    new1 = (struct node *)malloc(sizeof(struct node));

    if (new1 == NULL) 
	{
        printf("Overflow\n");
        exit(0);
    }

    new1->info = value;

    if (head == NULL) 
	{
        head = new1;
        new1->next = head;
    }
	 else
	  {
        temp = head;
        while (temp->next != head)
		 {
            temp = temp->next;
        }
        temp->next = new1;
        new1->next = head;
    }
}

void insertAtPosition(int value, int position) 
{
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    if (new1 == NULL) 
    {
        printf("Overflow\n");
        return;
    }

    new1->info = value;

    if (position == 1) 
    {
        insertbig(value);
        return;
    }

    struct node *temp = head;
    int i = 1;

    while (i < position - 1 && temp->next != head) 
    {
        temp = temp->next;
        i++;
    }

    if (i != position - 1) 
    {
        printf("Position out of range\n");
        free(new1);
        return;
    }

    new1->next = temp->next;
    temp->next = new1;
}

// Delete from beginning
void deleteAtBeginning() 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    if (head->next == head) 
    {
        free(head);
        head = NULL;
    } 
    else 
    {
        struct node *last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }

    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteAtEnd() 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    if (head->next == head) 
    {
        free(head);
        head = NULL;
    } 
    else 
    {
        struct node *prev;
        while (temp->next != head) 
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }

    printf("Node deleted from end.\n");
}

// Delete at specific position
void deleteAtPosition(int position) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) 
    {
        deleteAtBeginning();
        return;
    }

    struct node *temp = head, *prev;
    int i = 1;

    while (i < position && temp->next != head) 
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i != position) 
    {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted from position %d.\n", position);
}


void display()
 {
    struct node *temp = head;
    
    if (head == NULL) 
	{
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    do 
	{
        printf("%d  -> \n", temp->info);
        temp = temp->next;
    } while (temp == head);
    printf("(Back to head)\n");
}

int main() 
{
    int data, choice;
    char ch;
    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
       	printf("4. Delete from beginning\n");
		printf("5. Delete from end\n");
		printf("6. Delete from specific position\n");
        printf("7. Display list\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
		 {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertbig(data);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
    			printf("Enter value: ");
    			scanf("%d", &data);
    			int pos;
    			printf("Enter position: ");
    			scanf("%d", &pos);
    			insertAtPosition(data, pos);
    			break;
			case 4:
    			deleteAtBeginning();
    			break;
			case 5:
    			deleteAtEnd();
    			break;
			case 6:
    			printf("Enter position to delete: ");
    			int delPos;
    			scanf("%d", &delPos);
    			deleteAtPosition(delPos);
    			break;
            case 7:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue (y/n)? ");
        while ((getchar()) != '\n'); 
        scanf("%c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

