#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *ptr;
	
}*top,*top1,*temp;

int topelement ();
void push(int data);
void pop();
void display();
void empty();
void destroy();
void stack_count();
void create();
int count=0;
void main()
{
	int data,ch,e;
	printf("\n 1- push");
	printf("\n 2- pop");
	printf("\n 3- top");
	printf("\n 4- empty");
	printf("\n 5- exit");
	printf("\n 6- stack count");
	printf("\n 7- distroy stack");
	create();
	while(1)
	{
		printf("\n enter push element");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter data");
				scanf("\n%d",&data);
				push (data);
				break;				
			case 2:
			pop();
			break;
			case 3:
			if(top==NULL)
			printf("no element in stack");
			else
			{
				e=topelement();
				printf("\n top element:%d",e);
				
			}
			break;
			case 4:
				empty();
				break;
	        case 5:
			exit(0);
			case 6:
			stack_count();
			break;
			case 7:
			destroy();
			break;
			default:
				printf("wrong choice");
				break;
				
				
		}
		
	
}}
void create()
{
	top=NULL;
	
}
void stack_count()
{
	printf("\n number of element in stack:%d",count);
	
}
void push(int data)
{
	if (top==NULL)
{
	top=(struct node*)malloc(1*sizeof(struct node));
	top->ptr=top;
	top->info=data;
	
}
  else
     {
     	temp=(struct node*)malloc(1*sizeof(struct node));
		temp->ptr=top;
    	temp->info=data;
        top=temp;
	   
	 }
	 count++;
	 
}
void pop()
{
	top1=top;
	if(top1==NULL)
	{
		printf("\n error :trying pop from empty stack");
		return;
		
	}
	else
	top1=top1->ptr;
	printf("\n poped value :%d",top->info);
	free(top);
	top=top1;
	count--;
	
}
int topelement()

{
	return(top->info);
	
}
void empty()
{
	if(top==NULL)
	printf("\n stack is empty");
	else
	printf("\n stack is not empty with %d element",count);
	
}
void destroy()
{
	top1=top;
	while(top1!=NULL)
	{
		top1=top->ptr;
		free(top);
		top=top1;
		top1=top1->ptr;
		
	}
	free(top1);
	top=NULL;
	printf("\n all stack element distroy");
	count=0;
	
	
}
