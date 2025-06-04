/******************************************************************************
 * File Name: queue
 * Owner: Sahar Moalem                                                             
 * Reviewer: Arthur Morgan
 * Review status: Approved
 ******************************************************************************/
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    void* data;
    struct node* next;
} node_t;

node_t* CreateNode(const void* value)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = (void*)value;
    new_node->next = NULL;
    
    return new_node;
}

void ConnectNodes(node_t* node_1, node_t* node_2)
{
    node_1->next = node_2;
}

void RemoveEdge(node_t* node)
{
    node->next = NULL;
}

void DestroyList(node_t* head)
{
    node_t* tmp;
    while (NULL != head->next)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    free(head);
}

/* Reverses the order of a given slist */
node_t* Flip(node_t* head)
{
    node_t* curr = head;
    node_t* prev = NULL;
    node_t* next = NULL;

    while (NULL != curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

/* Tells wether a given slist has loop */
int HasLoop(const node_t* head)
{
    const node_t* turtle = head;
    const node_t* rabbit = head;
    
    if (NULL == rabbit || NULL == rabbit->next)
    {
        return 0;
    }
    turtle = turtle->next;
    rabbit = rabbit->next->next;
    
    while (turtle != rabbit)
    {
        if (NULL == rabbit->next)
        {
            return 0;
        }
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    
    return turtle == rabbit;
}

/* Returns a pointer to a first node mutual to both slists, if any */
node_t* FindIntersection(const node_t* head_1, const node_t* head_2)
{
    const node_t* curr_1 = head_1;
    const node_t* curr_2 = head_2;
    int flag1 = 0;
    int flag2 = 0;
    
    while (curr_1 != curr_2)
    {
        curr_1 = curr_1->next;
        if (NULL == curr_1)
        {
            if (flag1)
            {
                return NULL;
            }
            flag1 = 1;
            curr_1 = head_2;
        }
        curr_2 = curr_2->next;
        if (NULL == curr_2)
        {
            if (flag2)
            {
                return NULL;
            }
            flag2 = 1;
            curr_2 = head_1;
        }
    }
    return (node_t*)curr_1;
}

int main(void)
{
    node_t* first = CreateNode((const void*)1);
    node_t* second = CreateNode((const void*)2);
    node_t* third = CreateNode((const void*)3);
    node_t* fourth = CreateNode((const void*)4);
    node_t* fifth = CreateNode((const void*)5);
    node_t* sixth = CreateNode((const void*)6);
    node_t* seventh = CreateNode((const void*)7);
    node_t* eight = CreateNode((const void*)8);
    node_t* nine = CreateNode((const void*)9);
    node_t* current;
    
    ConnectNodes(first, second);
    ConnectNodes(second, third);
    ConnectNodes(third, fourth);
    ConnectNodes(fourth, fifth);
    
    /* Check Flip */
    current = first;
    while (NULL != current)
    {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
    
    current = first;
    current = Flip(current);
    while (NULL != current)
    {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
    current = fifth;
    current = Flip(current);
    while (NULL != current)
    {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
    
    /* Check Loop */
    current = first;
    if (!HasLoop((const node_t*)current))
    {
        printf("No loop at start\n");
    }
    ConnectNodes(fifth, third);
    if (HasLoop((const node_t*)current))
    {
        printf("Now theres a loop\n");
    }
    RemoveEdge(fifth);
    if (!HasLoop((const node_t*)current))
    {
        printf("Loop removed successfully\n");
    }
    
    /* Check intersection */
    ConnectNodes(sixth, seventh);
    ConnectNodes(seventh, fourth);
    ConnectNodes(eight, nine);
    if (fourth == FindIntersection((const node_t*)first, (const node_t*)sixth))
    {
        printf("Intersection found successfully\n");
    }
    if (NULL == FindIntersection((const node_t*)first, (const node_t*)eight))
    {
        printf("Intersection not found successfully\n");
    }
    
    RemoveEdge(seventh);
    DestroyList(first);
    DestroyList(sixth);
    DestroyList(eight);
    
    return 0;
}
