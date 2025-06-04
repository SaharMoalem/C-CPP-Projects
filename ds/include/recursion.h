#ifndef __RECURSION_H__
#define __RECURSION_H__

#include <stddef.h>     /* size_t */

#include "stack.h"

typedef struct node
{
    int value;
    struct node* next;
} Node;

/*Fibonacci iteratively*/
int IterFibonacci(int element_index);

/*Fibonacci recursively*/
int RecFibonacci(int element_index);

/* Flip List*/
Node* FlipList(Node* node);

/*Sort Stack*/
void SortStack(stack_t* stack);

/*strlen*/
size_t Strlen(const char* str);

/*strcmp*/
int Strcmp(const char* str1, const char* str2);

/* strcpy */
char* Strcpy(char* dst, const char* src);

/* strcat */
char* Strcat(char* dst, const char* src);

/*strstr*/
char* Strstr(const char* haystack, const char* needle);

#endif /* __RECURSION_H__ */ 