#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 char usn[20];
 char name[20];
 char branch[20];
 char sem[20];
 char phone[20];
 struct node *link;
} NODE;
NODE *first=NULL;
NODE *tail =NULL;
void create()
{
 int n;
 NODE *nn;
 printf("Enter the Number of Nodes you want to create\n");
 scanf("%d", &n);
 for(int i=1; i<=n;i++)
 {
 nn=(NODE*)malloc(sizeof(NODE));
 printf("Enter the Student Details:\n");
 scanf("%s%s%s%s%s", nn->usn, nn->name, nn->branch, nn->sem, nn->phone);
 if(first==NULL)
 tail=nn;
 nn->link=first;
 first=nn;
 }
}
void insert_front()
{
 if(first==NULL)
 printf("List Not Created\n");
 else
 {
 NODE *nn;
 nn=(NODE*)malloc(sizeof(NODE));
 printf("Enter the Student Details:\n");
 scanf("%s%s%s%s%s", nn->usn, nn->name, nn->branch, nn->sem, nn->phone);
 nn->link=first;
 first=nn;
 }
}
void display()
{
 NODE *temp;
 if(first==NULL)
 {
 printf("List is Empty");
 return;
 }
 temp=first;
 int c=0;
 while(temp!=NULL)
 {
 printf("%s\t%s\t%s\t%s\t%s\n", temp->usn, temp->name, temp->branch,
temp->sem, temp->phone);
 temp=temp->link;
 c++;
 }
 printf("No of Nodes in the list is %d", c);
}
void delete_front()
{
 NODE *temp;
 if (first==NULL)
 {
 printf("List is empty");
 return;
 }
 temp=first;
 first=first->link;
 free(temp);
}
void insert_end()
{
 if(first==NULL)
 printf("List Not Created\n");
 else
 {
 NODE *nn;
 nn=(NODE*)malloc(sizeof(NODE));
 printf("Enter the Student Details:\n");
 scanf("%s%s%s%s%s", nn->usn, nn->name, nn->branch, nn->sem, nn->phone);
 nn->link=NULL;
 tail->link=nn;
 tail=nn;
 }
}
void delete_end()
{
 if (first==NULL)
 {
 printf("List is empty");
 return;
 }
 NODE *temp;
 temp=first;
 while(temp->link!=tail)
 temp=temp->link;
 free(tail);
 tail=temp;
 tail->link=NULL;
}
void main()
{
 int ch;
 do
 {
 printf("\n1.Create\t2.Insert Front\t3.Delete Front\n4.Insert End\t5.Delete
End\t6.Display\t7.Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &ch);
 switch(ch)
 {
 case 1: create();
 break;
 case 2: insert_front();
 break;
 case 3: delete_front();
 break;
 case 4: insert_end();
 break;
 case 5: delete_end();
 break;
 case 6: display();
 break;
 case 7: printf("Exiting...\n");
 break;
 default: printf("Invalid Choice\n");
 }
 }while(ch>=1&&ch<=6);
}
