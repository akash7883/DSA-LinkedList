#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
}*s,*top=NULL,*temp;

void pop()
{
	
	int pop_value;
	if(IsEmpty()==1)
	{
		puts("sorry! No More elements In Stack");
		exit(1);
	}
	pop_value=top->data;
	top=top->next;
	fprintf(stdout,"The Popped Value is %d",pop_value);
}
int IsEmpty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}
void push(int data)
{	

	s=(struct stack *)malloc(sizeof(struct stack));
	if(IsEmpty()==1)
	{
		s->data=data;
		s->next=NULL;
		top=s;	
	}
	else
	{
		s->data=data;
		s->next=top;
		top=s;
	}		
}
void display()
{
	puts("The Elements Are:");
	temp=top;
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
	puts("Stack operartions");
	while(1)
	{
	puts("-------------------------------------------------------------------------------");
	fprintf(stdout,"Choose The Operation to perform:\n");
	fprintf(stdout,"1.Push\n2.Pop\n3.IsEmpty\n4.Dispaly\n5.Exit\n");
	fscanf(stdin,"%d",&choice);
	switch(choice)
	    {
		case 1:
			puts("Enter the data ");
			scanf("%d",&data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:{
			res=IsEmpty();
			(res==1)?printf("Stack IS Empty\n"):printf("Stack Is Not Empty\n");
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
