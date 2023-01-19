//it is advisable to maintain two pointer head and tail in order to reduce time complexity from O(N) to O(1) 
#include<stdio.h>
#include<stdlib.h>
struct DCLL{
    int data;
    struct DCLL * prev;
    struct DCLL * next;
};
typedef struct DCLL node;
void insert_at_beginning(node**head,int value)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=value;
    if(*head==NULL)
    {
        *head=new;
        new->next=new;
        new->prev=new;
    }
    else{
        node*start=(*head);
        while(start->next!=*head)
        {
            start=start->next;
        }
        (*head)->prev=new;
        new->next=*head;
        *head=new;
        new->prev=start;
        start->next=new;
}
}
void Print_list(node *head)
{
    node *start=head;
    printf("%d\n",head->prev->data);
    while (start->next!=head)
    {
        printf("%d-->",start->data);
        start=start->next;
    }
    printf("%d\n",start->data);
    printf("%d",start->next->data);
    printf("\n");
}
int main()
{
    node *head=NULL;
    insert_at_beginning(&head,1);
    insert_at_beginning(&head,2);
    insert_at_beginning(&head,3);
    insert_at_beginning(&head,4);
    insert_at_beginning(&head,5);
    insert_at_beginning(&head,6);
    insert_at_beginning(&head,7);
    Print_list(head);
}