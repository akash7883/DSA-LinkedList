#include<stdio.h>
//FIFO implementation
struct Queue
{
	int data;
	struct Queue *next;	
}*rear=NULL,*front=NULL;
void enqueue(int data)
{
	struct Queue *temp;
	temp=(struct Queue*)malloc(sizeof(struct Queue));
	temp->next=NULL;
	if(front==NULL)
	{
		temp->data=data;
		front=temp;
		rear=temp;
	}
	else
	{
		temp->data=data;
		rear->next=temp;
		rear=temp;
	}
}
void dequeue()
{
	if(front==NULL)
	{
		printf("Queue Is Empty !!!!!!");
	}
	else
	{
	int popped_value=front->data;
	printf("\n%d\n",popped_value);
	front=front->next;
	}
}
int IsEmpty()
{
	if(front==NULL)
	return 1;
	else
	return 0;
}
void display()
{
	int i;
	struct Queue *temp;
	temp=front;
	if(temp==NULL)
	{
		puts("No Elements in Stack");
	}
	printf("Elements are:\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int data,choice,res;
	puts("Queue operartions");
	while(1)
	{
	puts("-------------------------------------------------------------------------------");
	fprintf(stdout,"Choose The Operation to perform:\n");
	fprintf(stdout,"1.Enqueue\n2.Dequeue\n3.IsEmpty\n4.Dispaly\n5.Exit\n");
	fscanf(stdin,"%d",&choice);
	switch(choice)
	    {
		case 1:
			puts("Enter the data ");
			scanf("%d",&data);
			enqueue(data);
			break;
		case 2:
			dequeue();
			break;
		case 3:{
			res=IsEmpty();
			(res==1)?printf("Queue Is Empty\n"):printf("Queue Is Not Empty\n");
			break;}
		case 4:
			display();
			break;
		case 5:
			exit(1);
			break;		
	    }
	}
	return 0;
	
}
