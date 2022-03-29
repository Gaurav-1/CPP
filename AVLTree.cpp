#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
}*root;

class AVL{
    public:
        int height(node *T){
            int h=0;
            if(T!= NULL){
                int lh=height(T->left);
                int rh=height(T->right);
                int mh=max(lh,rh);
                h=mh+1;
            }
            return h;
        }
        int BF(node *T){
            int lh=height(T->left);
            int rh=height(T->right);
            return (lh-rh);
        }
        node *rotright(node *y){
            node *x=y->left;
            node *t2=x->right;
            x->right=y;
            y->left=t2;
            return x;
        }
        node *rotleft(node *x){
            node *y=x->right;
            node *t2=y->left;
            y->left=x;
            x->right=t2;
            return y;
        }
        node *min(node *T){
            while(T->left!=NULL)
                T=T->left;
            return T;
        }
        node *insert(node *T,int x){
            if(T==NULL){
                T=(node *)malloc(sizeof(node));
                T->data=x;
                T->left=NULL;
                T->right=NULL;
                cout<<"Element Inserted\n"<<endl;
                return T;
            }
            else if(x>=T->data)
                T->right=insert(T->right,x);
            else if(x<T->data)
                T->left=insert(T->left,x);
            int bf=BF(T);
            if(bf>1){
                if(x<T->left->data)
                    return rotright(T);
                else if(x>T->left->data){
                    T->left=rotleft(T->left);
                    return rotright(T);
                }
            }
            else if(bf<1){
                if(x>T->right->data)
                    return rotleft(T);
                else if(x<T->right->data){
                    T->right=rotright(T->right);
                    return rotleft(T);
                }
            }
            return(T);
        }
        node *del(node *T,int x){
            if(T==NULL){
                cout<<"Element not found"<<endl;
                return T;
            }
            if(x>T->data)
                T->right=del(T->right,x);
            else if(x<T->data)
                T->left=del(T->left,x);
            else{
                if(T->left==NULL){
                    node *temp=T->right;
                    delete T;
                    cout<<"Element deleted"<<endl;
                    return temp;
                }
                else if(T->right==NULL){
                    node *temp=T->left;
                    delete T;
                    cout<<"Element deleted"<<endl;
                    return temp;
                }
                node *temp=min(T->right);
                T->data=temp->data;
                T->right=del(T->right,temp->data);
            }
            int bf=BF(T);
            if(bf>1){
                if(BF(T->left)>=0)
                    return rotright(T);
                else{
                    T->left=rotleft(T->left);
                    return rotright(T);
                }
            }
            else if(bf<-1){
                if(BF(T->right)<=0)
                    return rotleft(T);
                else{
                    T->right=rotright(T->right);
                    return rotleft(T);
                }
            }
            return(T);
        }
        int search(node *T,int key,int h){
            if(T==NULL)
                return -1;
            if(T->data == key)
                return h;
            if(T->data < key)
                return search(T->right,key,h+1);
            else
                return search(T->left,key,h+1);
        }
        void preorder(node *T){
            if(T!=NULL){
                cout<<T->data<<"  ->  ";
                preorder(T->left);
                preorder(T->right);
            }
        }
        void inorder(node *T){
            if(T!=NULL){
                inorder(T->left);
                cout<<T->data<<"  ->  ";
                inorder(T->right);
            }
        }
        void postorder(node *T){
            if(T!=NULL){
                postorder(T->left);
                postorder(T->right);
                cout<<T->data<<"  ->  ";
            }
        }
        AVL(){
            root=NULL;
        }
};
int main(){
    int x,n,ch,tr;
    AVL a;
    while(ch){
        cout<<"\n1. Insert"<<endl;
        cout<<"2. Traversal"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Delete"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\nEnter value to be inserted: ";
                cin>>n;
                root=a.insert(root,n);
                break;
            case 2:
                tr=0;
                while(tr!=4){
                    cout<<"\nSelect traverse methodn\n"<<endl;
                    cout<<"1. Inorder"<<endl;
                    cout<<"2. Preorder"<<endl;
                    cout<<"3. Postorder"<<endl;
                    cout<<"4. Return"<<endl;
                    cout<<"Enter Choice: ";
                    cin>>tr;
                    switch(tr){
                        case 1:
                            a.inorder(root);
                            break;
                        case 2:
                            a.preorder(root);
                            break;
                        case 3:
                            a.postorder(root);
                            break;
                        case 4:
                            tr=4;
                            break;
                    }
                }
                break;
            case 3:
                cout<<"\nEnter data to be searched: ";
                cin>>n;
                x=a.search(root,n,0);
                if(x==-1)
                    cout<<"\nElement not found!!"<<endl;
                else
                    cout<<"\nFound at level: "<<x<<endl;
                break;
            case 4:
                cout<<"\nEnter the data: ";
                cin>>n;
                root=a.del(root,n);
                break;
            case 5:
                cout<<"\nExited"<<endl;
                exit(1);
                break;
            default:
                cout<<"\nWrong choice. ";
                break;
        }
    }
    return 0;
}