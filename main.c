#include <stdio.h>
#include <stdlib.h>
 typedef struct linked_list {
   int data ;
   struct linked_list  *next;
    }list;
list* initialzation_linkedlist(list*head){


}
void print_list (list *head){
while(head !=NULL){

  printf("linked_list_data:%d\n",head->data);
  head=head->next;
}

}
void insertion_in_first(list **head,int newdata){
list *ptr;
ptr=(list*)malloc(sizeof(list));
ptr->data=newdata;
ptr->next=(*head);
(*head)=ptr;


}
void insertion_in_middel(list *middel ,int data){
if (middel->next==NULL){
  printf("the prevnode is unvalid");
return;
}
list *temp;
temp=(list*)malloc(sizeof(list));
temp->data=data;
temp->next=middel->next;
middel->next=temp;
}
void insertion_in_last(list **last, int data ){
 list *temp;
 list *ptr=*last;
 temp=(list *)malloc(sizeof(list));
 temp->data=data;
 temp->next=NULL;
 if (*last == NULL) 
    { 
       *last = temp; 
       return; 
    }
    /* 5. Else traverse till the last node */
    while (ptr->next != NULL) 
        ptr = ptr->next; 
   
    /* 6. Change the next of last node */
    ptr->next = temp; 
    return; 
}
void delete_linkedlist(list **head,int key){
list*temp = *head,*prev;
if(temp != NULL && (temp->data == key)){
  *head = temp->next;
  free(temp);
 return;
}
 while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    }
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);
}
void free_list (list * head){
list *prev =head->next;
list *cur=head->next;
while (cur != NULL){
cur=cur->next;
free(prev);
prev =cur;
}
free(head);

}
int main(void) {
 list *head =NULL;
 list * second= NULL;
 list * third =NULL;

 head = (list* )malloc(sizeof(list));
 second =(list*)malloc(sizeof(list));
 third =(list *)malloc(sizeof(list));

 head->data=0;
 head->next=second;

 second->data =5;
 second->next=third;

 third->data=10;
 third->next=NULL;
 insertion_in_first(&head,5);
 insertion_in_middel(&second,5);
 insertion_in_last(&third, 5);
 print_list(head);  
delete_linkedlist(&head, 5);
print_list(head); 
free_list(head);
print_list(head);
  return 0;
}