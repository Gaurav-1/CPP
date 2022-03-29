#include <iostream>
using namespace std;

struct tree
{
    tree *l,*r;
    int data;
}*root=NULL,*p=NULL,*np=NULL,*q;

void create()
{
    int val,c=0;
    cout<<"Enter 7 elements"<<endl;
    while(c<7)
    {
        if(root==NULL)
        {
            root=new tree;
            cout<<"\nEnter the value of node: ";
            cin>>root->data;
            root->r=NULL;
            root->l=NULL;
        }
        else
        {
            p=root;
            cout<<"\nEnter the value of node: ";
            cin>>val;
            while(true)
            {
                if(val<p->data)
                {
                    if(p->l==NULL)
                    {
                        p->l=new tree;
                        p=p->l;
                        p->data=val;
                        p->l=NULL;
                        p->r=NULL;
                        cout<<"Value entered in left"<<endl;
                        break;
                    }
                    else
                    p=p->l;
                }
                else
                    if(p->r==NULL)
                    {
                        p->r=new tree;
                        p=p->r;
                        p->data=val;
                        p->l=NULL;
                        p->r=NULL;
                        cout<<"Value entered in right"<<endl;
                        break;
                    }
                else
                p=p->r;
            }
        }
        c++;
    }
}
void inorder(tree *p)
{
    if(p!=NULL)
    {
        inorder(p->l);
        cout<<p->data<<"  ->  ";
        inorder(p->r);
    }
}
void preorder(tree *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<"  ->  ";
        preorder(p->l);
        preorder(p->r);
    }
}
void postorder(tree *p)
{
    if(p!=NULL)
    {
        postorder(p->l);
        postorder(p->r);
        cout<<p->data<<"  ->  ";
    }
}
int main()
{
    create();
    
    cout<<"\n\nPerforming traversal in Inorder: ";
    inorder(root);

    cout<<"\n\nPerforming traversal in Postorder: ";
    postorder(root);

    cout<<"\n\nPerforming traversal in Preorder: ";
    preorder(root);

    return 0;
}