#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}

void
node_pop(struct Node *head, struct Node *elem)
{
    if (head == NULL || elem == NULL) {
        return;
    }
    
    if (elem->prev != elem && elem->next != elem) {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
    }
    
    elem->next = NULL;
    elem->prev = NULL;
}

void
node_append(struct Node *head; struct Node *elem)
{
    if (head == NULL || elem == NULL) {
        return;
    }
    struct Node *tail = head->prev;
    
    elem->next = head;
    elem->prev = tail;
    
    head->prev = elem;
    tail->next = elem;
}

void
node_rearr(struct Node *head)
{
    
    struct Node *tail = head->prev;
    struct Node *curr = head;
    while (*curr != *data)
    {
        struct Node next_elem = curr->next;
        if (curr.data > 100) {
            node_pop(curr);
            node_append(head, curr);
        else if (curr.data % 2 == 1) {
            node_pop(curr);
        }
        curr = next_elem;
    }
}

void
node_reverse()
{
    if (head == NULL) {
        return;
    }
    
    Node *curr = head->prev;
    do {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
}

int
main(void)
{
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    
    while (scanf("%d", &data) == 1) {
        Node *elem = malloc(sizeof elem);
        elem->data = data;
        if (head == NULL) {
            head = elem;
            elem->prev = elem;
            elem->next = elem;
        }
        else {
            node_append(head, elem);
        }
    }
    
    node_rearr(head);
    
    return 0;
}
