#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//using namespace std;
struct node{
	int info;
	struct node *link;
};
struct node *emptylist(struct node *start,int data){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}
struct node *beg(struct node *start,int data){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;

}
struct node *end(struct node *end,int data){
		struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	struct node * p, *start;
	p= start;
	while(p->link!=NULL)
{
	p=p->link;
}
p->link=tmp;
tmp->link=NULL;
return start;
}
struct node *nposition(struct node *start,int data,int position){
	int i;
	struct node *tmp ,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if(position==1)
{	tmp->link=start;
	start=tmp;
	return start;

	}	
	p=start;
	for(i=1;i<position-1 && p!=NULL;i++){
		p=p->link;
	}
	if(p==NULL){
		cout<<"There are less than "<<position<<" element\n";
	}
	else
	{
		tmp->link=p->link;
		p->link=tmp;
	}
	return start;
}

void disp(struct node *start){
	struct node *p;
	if(start==NULL){
		cout<<"List is empty\n";
	}
	else
	{
			p=start;
			cout<<"List\n";
		while(p!=NULL)
		{
			cout<<"\n"<<p->info;
			p=p->link;
		}
		cout<<"\n";
	}
}
int main(){
	struct node *start=NULL;
	int ch,data,postion;
	while(1)
	{
		cout<<"1. Insert in an empty list\n";
		cout<<"2. Insert at begning\n";
		cout<<"3. Insert at end\n";
		cout<<"4. Insert at nth position\n";
		cout<<"5. Display\n";
		cout<<"6. End Program\n";
		cout<<"---Enter your choice---\n";
		cin>>ch;
		switch(ch){
			case 1:
				if(start!=NULL){
					cout<<"List is not empty";
					break;
				}
				cout<<"Enter element";
				cin>>data;
				start=emptylist(start,data);
				break;
			case 2:
				cout<<"Enter element";
				cin>>data;
				start=beg(start,data);
				break;
			case 3:
				cout<<"Enter element";
				cin>>data;
				start=end(start,data);
				break;
			case 4:
				cout<<"Enter element";
				cin>>data;
				cout<<"Enter position";
				cin>>postion;
				start=nposition(start,data,postion);
				break;
			case 5:
				disp(start);
				break;
			case 6:
				exit(0);
			default:
				cout<<"Wrong Entry";
		}
	}
	getch();
}
