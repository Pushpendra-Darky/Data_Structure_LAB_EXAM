// Q1: Insert 11 Element At End 

#include<stdio.h>
#include<stdlib.h>

struct node{                                                        //creating struct for linked list
	int data;
	struct node *next;
};
struct node *head;                                                 //creating head pointer

void create_link(int);                                            //
void insert_end();                                                //
void display();                                                   //
void insert_end();                                                //function prototyping

int main()                                                       //main
{
	int n,m;
	printf("ENTER THE NUMBER OF NODE TO CREATE LIST.\n");
	scanf("%d",&n);
	create_link(n);
	printf("\nDATA IN NODES: \n");
	display();
	insert_end();
	display();

	return 0;

}

void create_link(int n)                                               //logic for creating node
{
	struct node *newnode,*temp;
	int data,i;
	head = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("Unable to allocate memory.\n");
		exit(0);
	}
	else
	{
		printf("\nEnter the data in new node 1: ");
		scanf("%d",&data);
		head->data = data;
		head->next = NULL;
		printf("\nNew Node is created.\n");

		temp = head;
	}
	for(i=2;i<=n;i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter the data in new node %d: ",i);
		scanf("%d",&data);

		newnode->data = data;
		newnode->next = NULL;
		printf("\nnew node is created.\n");

		temp->next = newnode;
		temp = temp->next;
	}
}

void display()                                                      //logic for Displaying
{
	struct node *temp;
	if(head == NULL)
	{
		printf("\nLIST IS EMPTY.\n");
		return;
	}
	else
	{
		temp=head;
		int count = 0;
		while(temp != NULL)
		{
			printf("DATA IN NODE %d is %d.\n",count,temp->data);
			temp = temp->next;
			count++;
		}
		printf("TOTAL NO OF NODES IS: %d\n",count);
	}
}

void insert_end()                                                //logic for inserting node at the end in linked list
{
	struct node *temp,*atend;
	int data;
	if(head == NULL)
	{
		printf("unable to allocate memory.\n");
		exit(0);
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		atend = (struct node*)malloc(sizeof(struct node));
		printf("\nENTER THE DATA IN NEW NODE AT END: ");
		scanf("%d",&data);
		atend->data = data;
		atend->next = NULL;
		printf("\nnew node created at the end with data %d\n\n",atend->data);

		temp->next = atend;

	}
}
