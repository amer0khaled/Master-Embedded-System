#include "linked_list.h"
int main()
{
    int value;
    node* head='\0' ;
    push_head(&head, 25);
    push_head(&head, 50);
    push_end(&head, 30);
    push_head(&head, 70);
    push_end(&head, 80);
    print_list(head);
    printf("\n");

    value = pop_head(&head);
    printf("poped value from head is: %i\n",value);

    value = pop_end(&head, head);
    printf("poped value from end is: %i\n",value);

    print_list(head);


    return 0;
}
