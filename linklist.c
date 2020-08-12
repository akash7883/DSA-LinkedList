#include<stdio.h>
#include<windows.h>
struct Node
{
	int roll;
	struct Node *next;
}*start=NULL,*p,*temp;
void push()
{
	p=(struct Node *)malloc(sizeof(struct Node));
	puts("Enter the roll no;");
	scanf("%d",&p->roll);
	p->next=NULL;
	if(start==NULL)
	{
		temp=start=p;		
	}
	else
	{
		temp->next=p;
		temp=p;
	}
}
void deleteme()
{
	int ele;
	struct Node *m,*temp;
	puts("Enter the elements to remove");
	scanf("%d",&ele);
	m=start;
	while(m->next->roll!=ele)
	{
		m=m->next;	
	}
	temp=m->next;
	m->next=temp->next;
	free(temp);
}
void Addatbegin()
{
	struct Node *m,*temp;
	temp=start;
	m=(struct Node *)malloc(sizeof(struct Node));
	fprintf(stdout,"Enter the element to add at beginning\n");
	scanf("%d",&m->roll);
	m->next=temp;
	start=m;
}
void Addatlast()
{
	struct Node *m,*temp;
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	m=(struct Node *)malloc(sizeof(struct Node));
	fprintf(stdout,"Enter the element to add in last\n");
	scanf("%d",&m->roll);
	temp->next=m;
	m->next=NULL;
}
void insert()
{
	int pos,i;
	struct Node *m,*p1=start,*p2=start;
	puts("Enter the position");
	scanf("%d",&pos);
	for(i=1;i<pos;i++)
	{
		p1=p1->next;
	}
	p2=p1->next;
	m=(struct Node *)malloc(sizeof(struct Node));
	fprintf(stdout,"Enter the element to add after the position\n");
	scanf("%d",&m->roll);
	p1->next=m;
	m->next=p2;
	
	
	
}
void display()
{
	struct Node *m;
	m=start;
	while(m!=NULL)
	{
		printf("%d\t",m->roll);
		m=m->next;
	}
	printf("\n");
}
int main()
{
	int choice;
	puts("Linked list operations:");
	while(1){
	puts("----------------------------------------------------------------------------------\n");
	fprintf(stdout,"Choose The Operation to perform:\n");
	fprintf(stdout,"1.Add An Element\n2.Remove a element\n3.Add At Begin\n4.Add at Last\n5.Insert At Pos\n6.Display Linked Lsit\n7.Exit\n");
	fscanf(stdin,"%d",&choice);
	switch(choice)
	{
		case 1:
			push();
			break;
		case 2:
			deleteme();
			break;
		case 3:
			Addatbegin();
			break;
		case 4:
			Addatlast();
			break;
		case 5:
			insert();
			break;
		case 6:
			display();
			break;
		case 7:
			exit(1);
						
	}
	}
	return 0;
}
