#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *prev;
	int data;
    struct node *next;
} *a, *temp, *head, *temp2, *tail;

void create(int n)
{
	int i;
	temp = (struct node *)malloc(sizeof(struct node));
	head = (struct node *)malloc(sizeof(struct node));
	a = (struct node *)malloc(sizeof(struct node));

	head->prev = NULL;
	head->data = 1;
	head->next = temp;
	a = head;
    for(i=1;i<=n;i++)
    {
    	temp = (struct node *)malloc(sizeof(struct node));
	
    	temp -> prev = a;
    	temp -> data = i+1;
    	a -> next = temp;
    	a = temp;
    }
    temp->next = NULL;
    tail = temp;
}

void display()
 {
 temp = (struct node *)malloc(sizeof(struct node));
 temp = head;
 while(temp->next != NULL)
 { 
  printf("\n%d",temp->data); 
temp=temp->next;
}
 }
 void displayreverse()
 {
 temp = (struct node *)malloc(sizeof(struct node));
 temp = tail;
 while(temp->prev != NULL)
 { 
  printf("\n%d",temp->data); 
temp=temp->prev;
}
 }

  void insert(int data,int prev)
 {
  temp = (struct node *)malloc(sizeof(struct node));
  temp = head;
  a= head;
  a=a->next;
    while( temp->data != prev)
    {
     temp = temp->next;
     a=a->next;
  }
  temp2 = (struct node *)malloc(sizeof(struct node));
  temp2->data=data;
  temp->next=temp2;
  temp2->next=a;
  }
  
  void delete(int data)
  {
temp = (struct node *)malloc(sizeof(struct node));
a = (struct node *)malloc(sizeof(struct node));
temp=head;
a=head;
a=a->next;

  while(a->data!=data)
  {
    temp=temp->next;
    a=a->next;
  }
  temp->next=a->next;
}

void main()
{
 int n,r,p;
 do{
 printf("\n\n\t\t\t********** MAIN MENU **********\n\n 1) Create List\n 2) Insert data\n 3) Delete\n 4) Display Contents of list\n 5) Exit\n\n");
 scanf("%d",&n);
 
 switch(n)
 {
 case 1:
 printf("\nEnter number of nodes you want to create: ");
 scanf("%d",&r);
 create(r);
 break;
 
 case 2:
 printf("\nEnter data: ");
 scanf("%d",&r);
 printf("\nNow Enter data after which you want to add: ");
 scanf("%d",&p);
 insert(r,p);
 break;
 
 case 3:
 printf("\nEnter data: ");
 scanf("%d",&p);
 delete(p);
 break;
 
 case 4:
 display();
 break; 
 }
 
 }while(n!=5);

}

