
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
int info;
struct node *ptr;
};


struct node* deleteDuplicates(struct node* head){
    
 struct node* cur = head;
    while (cur && cur->ptr) {
        if(cur->info == cur->ptr->info)
            cur->ptr = cur->ptr->ptr;
        else
            cur = cur->ptr;
    }
    return head;
}

struct node* unsorted_deleteDuplicates(struct node* head){
    
 struct node* cur = head;
 struct node *next;
    while (cur && cur->ptr) {
        next = cur;
        while(next->ptr != NULL)
        {
        if(cur->info == next->ptr->info)
            next->ptr = next->ptr->ptr;
        else
            next = next->ptr;
        }
        cur = cur->ptr;
    }
    return head;
}


struct node *insert_element(struct node *head, int ele)
{
	struct node *cur_node,*new_node;
	int pos,data;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->info=ele;
	new_node->ptr=NULL;
	printf("enter pos \n");
	scanf("%d",&pos);
	if(pos==1||head==NULL)
	{
		new_node->ptr=head;
		head=new_node;
	}
	else
	{
		cur_node=head;
		printf("Enter the data after which you want to insert the element \n");
		scanf("%d",&data);
		while(cur_node!=NULL&&cur_node->info!=data)
		{
			cur_node=cur_node->ptr;
		}
		if(cur_node==NULL)
			printf("Data entered not present \n");
		else
		{
			new_node->ptr=cur_node->ptr;
			cur_node->ptr=new_node;
		}
	}
	return head;
}
void display(struct node *head)
{
	if(head==NULL)
		printf("Empty List\n");
	else
	{
		while(head!=NULL)
		{
			printf("****%d\n",head->info);
			head=head->ptr;
		}
	}
}
int main()
{
	struct node *HEAD;
	HEAD=NULL;
	int x;
	int i;
	while(1)
	{
		printf("choose the option\n 1. Insert\n 2.Display\n 3. duplicate\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("Enter the element to insert\n");
				scanf("%d",&x);
				HEAD=insert_element(HEAD,x);
				break;
			case 2:display(HEAD);
				 break;
			case 3: HEAD = unsorted_deleteDuplicates(HEAD);
      break;
		};
	}
}
