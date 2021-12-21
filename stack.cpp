#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX],top=-1;
void push();
void pop();
void disp();
int main()
 {
 	int ch;
 	printf("\n 1.push or insert");
 	printf("\n 2.pop or delete");
 	printf("\n 3.Display");
 	printf("\n 4.End program");
 	while(1)
 	{
 		printf("\n enter your choice:");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:
 				{
 					push();
 					break;
				 }
				 case 2:
				 	{
				 		pop();
				 		break;
					 }
					 case 3:
					 	{
					 		disp();
					 		break;
					 		
						 }
					 case 4:
					 {
					 	exit(0);
					 	
						  }	 
		 default :{
			printf("wrong choice");
		 }
	}
}
	getch();
}
void push()
{	
	int data;
	if(top==MAX-1)
		printf("\nThe stack is full");
	else
	{
	 printf("enter element to be interested :");
    scanf("%d",&data);
    top++;
    a[top]=data;
    }
}
void pop()
 {
 	if (top==-1)
 {
 	printf("stack is empty");
 	
 } else
 {
 	printf("popped element: %d ",a[top]);
 	
 	top--;
 }}
void disp()
{
 	int i;
 	if(top>=0)
 {
 printf("elements");
 for(i=top;i>=0;i--)
 printf("\n%d",a[i]);
 }
else
 { 
	printf("stack is empty");
 }
}
