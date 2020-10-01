#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



    struct Node {
        int data;
        struct Node *next;
    };

    void Traverse(struct Node *ptr){
        while(ptr!= NULL){
            printf("Element: %d\n",ptr->data);
            ptr=ptr->next;
        }


    }
    int main(){



        struct Node *head;
        struct Node *second;
        struct Node *third;

      head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // allocating memory in heap

        head->data=1;
        head->next=second;
        second->data=11;
        second->next=third;
        third->data=111;
        third->next=NULL;

        Traverse(head);
        return 0;


    }