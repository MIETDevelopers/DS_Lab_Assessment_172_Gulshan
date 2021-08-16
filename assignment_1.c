// Assignment 1: Find the cheapest walnut in Raghunath Bazaar of Jammu.

#include <stdio.h>
#include <stdlib.h>

//Line 2 & 3: Including libraray files for the predefined functions used in this program.

struct node{
    int price;
    char name[30];
    struct node *next;
} *head, *ptr;

typedef struct node NODE;

int num=0;


int insert()
{
    ptr=(NODE*)malloc(sizeof(NODE));

    if(ptr==NULL){
        printf("\n RAM is FULL!! \n");
    }
    else
    {
        printf("\nshop name: ");
        scanf("%*c%[^\n]",&ptr->name);

        printf("\nprice of the walnuts: ");
        scanf("%d",&ptr->price);

        if(head == NULL){
            head = ptr ;
            head->next = NULL ;
        }
        else
        {
            if(head->price >= ptr->price){
                ptr->next = head;
                head = ptr;
            }
            else
            {
                ptr->next = head->next;
                head->next = ptr;
            }
        }
        num++;
    }
}

int cheapest(){
       
    if(head==NULL)  
    {  
        printf("\nNo data present.\n");  
    }  
    else  
    { 
        printf("\nShop selling the cheapest walnut in Raghunath Bazaar is %s at %d Rs.\n",head->name,head->price);
    }
}

int display(){
    ptr = head;   
    if(ptr==NULL)  
    {  
        printf("\nNo data present.\n");
    }  
    else  
    {  
        printf("\nData collected of all shops :\n");   
        
        while (ptr != NULL)
        {  
            printf("-->Shop name: '%s' sells walnuts at %d Rs.\n", ptr->name, ptr->price);  
            ptr = ptr->next;
        }
    printf("\n-->Data of %d shops in Raghunath Bazaar.\n",num);
    } 
}

int main(){
    int ch;
    do{
        printf("\nEnter\n   1.Enter shop details\n   2.Display shop detailswith the low cost \n   3.Display the cost of walnuts of all shops\n   4.To Exit\n");    
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                insert();
                break;

            case 2:
                cheapest();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProcess ended.\n");
                break;

            default:
                printf("\n!!ERROR!!\n");
        }
    }while (ch != 4);
}