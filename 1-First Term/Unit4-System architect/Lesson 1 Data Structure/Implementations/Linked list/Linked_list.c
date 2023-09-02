
#include"Linked_list.h"

void print_list(node * head)
{
    if(head == '\0')
    {
        printf("Linked list is empty\n");
    }
    else
    {
        while((head->next) != '\0')
        {
            printf("%i\n",head->val);

            head = head->next;
        }
        printf("%i\n",head->val);
    }
}


void push_head(node ** head_ptr, int data)
{
    node * next_node;

    next_node = *head_ptr;

    * head_ptr = (node *)malloc(sizeof(node));

    (*head_ptr)->val = data;

    (*head_ptr)->next = next_node;

}


void push_end(node ** head_ptr, int data)
{
    if(*head_ptr == '\0')
    {
        push_head(head_ptr, data);
    }
    else
    {
        node * head = *head_ptr;

        while(head->next != '\0')
        {
            head = head->next;
        }

        head->next = (node *)malloc(sizeof(node));

        head->next->val = data;

        head->next->next= '\0';

    }
}


int pop_head(node ** head_ptr)
{
    if(*head_ptr != '\0')
    {
        int ret_val;

        node * temp;

        temp = (*head_ptr)->next;

        ret_val = (*head_ptr)->val;

        free(*head_ptr);

        *head_ptr = temp;

        return ret_val;

    }
}

int pop_end(node ** head_ptr, node * head)
{
    int ret_val;

    if(head->next == '\0')
    {
        ret_val = pop_head(head_ptr);
    }
    else
    {
        while(head->next->next != '\0')
        {
            head = head->next;
        }

        ret_val = head->next->val;
        free(head->next);
        head->next = '\0';
    }

    return ret_val;
}


void push_sequential(node ** head_ptr, int data)
{
    if(*head_ptr == 0)
    {
        push_head(head_ptr, data);
    }
    else
    {
        node * temp = *head_ptr;

        while(temp->next != 0)
        {
            temp = temp->next;
        }

        temp->next = (node *)malloc(sizeof(node));
        temp->next->val = data;
        temp->next->next = 0;

    }

}


