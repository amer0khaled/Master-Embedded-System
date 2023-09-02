
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include<stdlib.h>

typedef struct node
{
    int val;
    struct node * next;

}node;

void print_list(node * head);

void push_head(node ** head_ptr, int data);

void push_end(node ** head_ptr, int data);

int pop_head(node ** head_ptr);

int pop_end(node ** head_ptr, node * head);

void push_sequential(node ** head_ptr, int data);


#endif // __LINKED_LIST_H__
