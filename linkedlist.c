#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//creating a structue to support the linked list ds;
 struct node
{
	int data;
	struct node* next;
};
//A funtion to enter array elements to a Linked list;
 struct node* createlist(int *array,int sizeofarr)
 {
 	struct node* head;
 	//creating a head node;
 	head = (struct node*)malloc(sizeof(struct node*));
 	//making the head node;
 	head->data=array[0];
 	head->next=NULL;
 	//linking variables;
 	struct node* temp;
 	temp = head;
 	//iterating over n variables;
 	struct node* itervar;
 	for(int i=1;i<sizeofarr;i++)
 	{
 		
 		//creating memory space for the iterable variable;
 		itervar = (struct node*)malloc(sizeof(struct node*));
 		if(itervar==NULL)
 			break;
 		else
 		{
 			//creating the iterating process;
 			itervar->data = array[i]; 			
 			itervar->next = NULL;
 			//linking the itervar to each of the next itervars;
 			temp->next = itervar;
 			temp = temp->next;
 		}
 		
 	}
 	// to access the first node;
 	return head;


 }
 void printlist(struct node* firstnode)
 {
 	//retrieving the firstnode to start iterating;
 	struct node* printvar = firstnode;
 	while(printvar!= NULL)
 	{
 		printf("%d ",printvar->data );
 		//iterative condition;
 		printvar=printvar->next;
 	}

 }
 int main(int argc, char *argv[])
 {
 	int sizeoflist;
 	sizeoflist=argc -1;
 	int array[sizeoflist];
 	for(int i=0;i<sizeoflist;i++)
 		array[i]=atoi(argv[i+1]);
 	struct node* head;

 	head=createlist(array,sizeoflist);
 	printf("%d\n",head->data );
 	printlist(head);
 	return 0;
 }