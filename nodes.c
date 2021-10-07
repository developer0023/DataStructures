#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include "stdio.h"
#include "stdlib.h"

//creating Nodes
struct Node{
    int data;
    struct Node *next;
};
void traversal(struct Node*);
void search(struct Node*ptr,int s);
void insert_begin(struct Node *h,int d);
void insert_end(struct Node *h,int d);
void insert_mid(struct Node *p,int d,int i);
void del_first(struct Node *head);
void del_last(struct Node *head);
void del_mid(struct Node *head,int i);
//creating linked list
int main(void){
    struct Node* head=(struct Node*) malloc(sizeof(struct Node));
    struct Node* second=(struct Node*) malloc(sizeof(struct Node));
    struct Node* third=(struct Node*) malloc(sizeof(struct Node));
    printf("enter a number\n");
    scanf("%d",&(head->data));
    printf("enter a number\n");
    scanf("%d",&(second->data));
    printf("enter a number\n");
    scanf("%d",&(third->data));
    head->next=second;
    second->next=third;
    third->next=NULL;
    printf("This Linked List was created Successfully!\n");
    traversal(head);
    search(head,8);
    insert_begin(head,98);
    //insert_end(head,45);
    //insert_mid(head,45,9);
    return 0;
}
//the following function traverses the Linked List to print its contents
void traversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
//the following function performs search ops in a Linked List
void search(struct Node* ptr,int s){
    int c=-1;
    while(ptr!=NULL){
        if(ptr->data==s) {
            printf("Element found\n\n\n");
            c = 1;
            break;
        }
        ptr=ptr->next;
    }
    if(c==-1){
        printf("Element wasn't found!\n\n\n");
    }
}
//insertion in linked list
//At the beginning
void insert_begin(struct Node *h,int d){
    struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
    new_node->data=d;
    new_node->next=h;
    traversal(new_node);
    insert_end(new_node,45);
    insert_mid(new_node,78,9);
    del_first(new_node);
}
//At the end
void insert_end(struct Node *h,int d){
    struct Node *new_node1=(struct Node*) malloc(sizeof(struct Node));
    struct Node *temp;
    temp=h;
    new_node1->data=d;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node1;
    new_node1->next=NULL;
    printf("Insertion at the end\n");
    traversal(h);
}
//Inserting in the middle
void insert_mid(struct Node *p,int d,int i){
    struct Node *new_node2=(struct Node*) malloc(sizeof(struct Node));
    new_node2->data=d;
    struct Node *temp;
    temp=p;
    while(temp->data!=i){
        temp=temp->next;
    }
    new_node2->next=temp->next;
    temp->next=new_node2;
    printf("Insertion in the middle\n");
    traversal(p);
}
//Deleting the first node
void del_first(struct Node *head){
    head->data='\0';
    head=head->next;
    printf("Deletion from the beginning\n");
    traversal(head);
    del_last(head);
    del_mid(head,78);
    free(head);
}
//Deleting the last node
void del_last(struct Node *head){
    struct Node *traverse=head;
    struct Node *prev=head;
    while(traverse->next!=NULL){
        prev=traverse;
        traverse=traverse->next;
    }
    traverse->data='\0';
    prev->next=NULL;
    printf("Deletion from the end\n");
    traversal(head);
    free(traverse);
}
//Deletion in the middle
void del_mid(struct Node *head,int i){
    struct Node* temp=head;
    struct Node* prev_node=head;
    while(temp->data!=i){
        prev_node=temp;
        temp=temp->next;
    }
    prev_node->next=temp->next;
    temp->data='\0';
    printf("Deletion from the middle\n");
    traversal(head);
    free(temp);
}
//for better understanding take the three inputs as 9 8 and 7 in whatever order you wish.