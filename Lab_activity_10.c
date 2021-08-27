#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();  
struct node   
{  
int val;  
struct node *next;  
};  
struct node *head;  
  
void main ()  
{  
    int choice=0;     
    printf("\n****Stack operations using linked list****\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
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
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    };  
}  
}  
void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   //allocates the requested memory.
    if(ptr == NULL)  
    {  
        printf("not able to push the element");  //space is not avilable in RAM 
    }  
    else   
    {  
        printf("Enter the value");  
        scanf("%d",&val);  
        if(head==NULL)  //no node present.
        {         
            ptr->val = val;  //assigning data of val to ptr->val.
            ptr -> next = NULL;  //ie ptr is the only node present.
            head=ptr;  //assigning address of ptr to head as we are adding node at beginning.
        }   
        else        //if one or more nodes are present.
        {  
            ptr->val = val;  //assigning data of val to ptr->val.
            ptr->next = head;  //assigning address of head to ptr->next, 
                                //so that node present at head will become second node.
            head=ptr;  //assigning address of ptr to head as we are adding node at beginning.
               
        }  
        printf("Item pushed");  
          
    }  
}  
  
void pop()  
{   
    struct node *ptr;  
    if (head == NULL)  //no node present.
    {  
        printf("Underflow");  
    }  
    else  
    {     
        ptr = head;  //assigning address of head to ptr as we are going to free the memory later.
        head = head->next;  //assigning address of head->next to head as we are deleting node from beginning.
        free(ptr);      //freeing allocated memory, so other can use it.
        printf("Item popped");  
          
    }  
}  
void display()  
{    
    struct node *ptr;  
    ptr=head;  //assigning address of head to ptr.
    if(ptr == NULL)  //no node present.
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  //traversing to the last node.
        {  
            printf("%d\n",ptr->val);  //printing integer val present at node.
            ptr = ptr->next;  //assigning address of ptr->next to ptr as we have to move to next node.
        }  
    }  
}