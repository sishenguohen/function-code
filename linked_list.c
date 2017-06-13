#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
	int val;
	struct Node *next;
};

void initList(struct Node *node )
{
	node = NULL;
	printf("initList complete\n");
}

struct Node *createList(struct Node *head)
{
	struct Node *current;
	struct Node *prev;
	
	current = prev = (struct Node *)malloc(sizeof(struct Node));
	if(prev == NULL || current == NULL)
	{
		printf("malloc fail\n");
		exit(0);
	}

	memset(current,0,sizeof(struct Node));
	
	printf("enter a new value (if it<=0,exit)\n");
	scanf("%d",&current->val);
	current->next = NULL;
	
	while(current->val > 0 )
	{
		if(head == NULL)
		{
			head = current;
		}
		else 
		{
			prev->next = current;
		}
		
		prev = current ;
		current  = (struct Node *)malloc(sizeof(struct Node));
		if(prev == NULL || current == NULL)
        	{
        	        printf("malloc fail\n");
        	        exit(0);
        	}
	
	        memset(current,0,sizeof(struct Node));

        	printf("enter a new value\n");
        	scanf("%d",&current->val);
        	current->next = NULL;
	}
	printf("createList complete\n");
	return head;
}
	 
void printList(struct Node *head)
{
	struct Node *current;
	current = head;
	if(current == NULL)
	{
		printf("List is NULL\n");
		return;
	}
	else
		while(current != NULL)
		{
			printf("%d\n",current->val);
			current = current->next;
		}
		printf("\n");	
}
	
void clearList(struct Node *head)
{
	struct Node *current = head;
	struct Node *prev ;
	if(head == NULL)
	{
		printf("List is NULL\n");
		return ;
	}
	else
		while(current != NULL)
		{
			prev = current->next;
			free(current);
			current = prev;
		}
	head->next = NULL;
	printf("clearList complete\n");
}

int listLen(struct Node *head)
{
	int len = 0;
	struct Node *current;
	current = head;
	if(current == NULL)
	{
		return 0;
	}
	while(current != NULL)
	{
		len++;
		current = current->next;
	}
	printf("listLen complete\n");
	return len;
}
		
int isEmptyList(struct Node *head)
{
	if(head == NULL)
	{
		printf("List is NULL\n");
		return -1;
	}
	else 
	{
		printf("List isn't NULL\n");
		return 0;
	}
}
		
int getElement(struct Node *head,int pos)
{
	struct Node *current;
	current = head;
	if(current == NULL)
		return -1;
	if(pos<=0)
	{
		printf("Pos illegl\n");
		return -1;
	}
	if(pos>listLen(head))
	{
		printf("Pos is bigger than list\n");
		return -1;
	}
	for(int i=0; i<pos;i++)
	{
		current = current->next;
	}
	printf("GetElement complete\n");
	return current->val;
}

struct Node *getElementAddr(struct Node *head,int val)
{
	struct Node * current;
	struct Node * prev;
	current = head;
	if(current == NULL)
	{
		printf("List is NULL\n");
		return NULL;
	}
	while(current != NULL)
	{
		if(current->val == val)
		{
			printf("GetElementAddr complete\n");
			return current;
		}
		else
			current = current->next;
	}		
	printf("List haven't the val\n");
	return NULL;
}

int reviseElement(struct Node *head,int pos,int val)
{
	struct Node *current;
	current = head;
	if(current == NULL)
	{
		printf("List is NULL\n");
		return -1;
	}
	if(pos <= 0)
	{
		printf("Pos illegl\n");
		return -1;
	}
	if(pos > listLen(head))
	{
		printf("Pos is bigger than list\n");
                return -1;
	}
	for(int i =0; i<pos;i++)
	{
		current = current->next;
	}
	current->val = val;
	printf("ReviseElement complete\n");
	return 1;
}
	
struct Node *insertHeadList(struct Node  *head,int val)
{
	struct Node *current;
	struct Node *prev;
	current = head;
	if(current = NULL)
	{
		prev = (struct Node *)malloc(sizeof(struct Node));
		prev->val = val;
		prev = NULL;
		return prev;
	}
	prev = (struct Node *)malloc(sizeof(struct Node));
	prev->val = val;
	prev->next = head;
	return prev;
}
		
struct Node *insertLastList(struct Node *head,int val)
{
	struct Node *current;
	struct Node *prev;
	current = head;
	if(current == NULL)
	{
		prev = (struct Node *)malloc(sizeof(struct Node));
		prev->val = val;
		return prev;
	}
	while(current != NULL)
		current=current->next;
	prev = (struct Node *)malloc(sizeof(struct Node));
	prev->val = val;
	current->next = prev;
	prev->next = NULL;
	return head;
}

int insertList(struct Node *head,int pos ,int val)
{
	struct Node *current;
	struct Node *prev;
	current = head;
	if(current == NULL)
	{
		prev = (struct Node *)malloc(sizeof(struct Node));
                prev->val = val;
                return -1;
        }
        for(int i = 0;i<pos;i++)
	{
		current=current->next;
	}
	prev = (struct Node *)malloc(sizeof(struct Node));
        prev->val = val;
	prev->next = current->next->next;
	current->next = prev;
	return 1;
}

int deleteHeadList(struct Node *head)
{
	struct Node *current;
	struct Node *prev;
	current = head->next;
	int value;
	if(current == NULL)
	{
		printf("List is NULL\n");
		return 0;
	}
	value = current->val;
	free(current);
	head = current;
	return value;
}

int deleteLastList(struct Node *head)
{
	struct Node *current;
	struct Node *prev;
	int value;
	current = head;
	if(current == NULL)
	{
		printf("List is  NULL\n");
		return 0;
	}
	while(current != NULL)
	{
		current = current->next;
	}
	prev = current;
	value = current->val;
	free(current);
	prev = NULL;
	return value;
}

int deletePosList(struct Node *head,int pos)
{
	struct Node *current;
	struct Node *prev;
	current = head;
	if(current == NULL)
	{
		printf("List is NULL\n");
		return -1;
	}
	if(pos > listLen(head))
	{
		printf("Pos is bigger than list\n");
		return -1;
	}

}

int main(int argc,char *argv[])
{
	struct Node *list;
	initList(list);
	list = createList(list);
	printf("List len is %d\n",listLen(list));
	printList(list);
	clearList(list);	
	printf("List len is %d\n",listLen(list));
	printList(list);
	getElement(list,1);
//	printList(list);
}	
