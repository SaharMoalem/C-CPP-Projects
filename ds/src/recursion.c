#include <assert.h>   /*assert*/
#include <string.h>   /*strncmp*/

#include "recursion.h"

int IterFibonacci(int element_index)
{
    int prev_1 = 1, prev_2 = 1;
    int result = 0;
    int i = 3;

    if(element_index <= 2)
    {
        return 1;
    }

    for( ; i <= element_index; ++i)
    {
        result = prev_1 + prev_2;
        prev_2 = prev_1;
        prev_1 = result;
    }

    return result;
}

int RecFibonacci(int element_index)
{
    if(element_index <= 2)
    {
        return 1;
    }

    return RecFibonacci(element_index - 1) + RecFibonacci(element_index - 2);
}

Node* FlipList(Node* node)
{
    Node* next = NULL;

    assert(node);

    if(node == NULL || node->next == NULL)
    {
        return node;
    }

    next = FlipList(node->next);
    node->next->next = node;
    node->next = NULL;

    return next;
}

static void StackPeekPop(stack_t* stack, int* element)
{
    StackPeek(stack, element);
    StackPop(stack);
}

static void InsertToSorted(stack_t* stack, int element)
{
    int curr;

    if(StackIsEmpty(stack))
    {
        StackPush(stack, &element);
        return;
    }

    StackPeek(stack, &curr);
    if(element > curr)
    {
        StackPush(stack, &element);
        return;
    }

    StackPop(stack);
    InsertToSorted(stack, element);
    StackPush(stack, &curr);
}

void SortStack(stack_t* stack)
{
    int curr = 0;

    if(!StackIsEmpty(stack))
    {
        StackPeekPop(stack, &curr);
        SortStack(stack);
        InsertToSorted(stack, curr);
    }
}

size_t Strlen(const char* str)
{
    assert(str);

    if(*str == '\0')
    {
        return 0;
    }

    return 1 + Strlen(++str);
}

int Strcmp(const char* str1, const char* str2)
{
    assert(str1);
    assert(str2);

    if(*str1 == '\0' || *str2 == '\0' || *str1 != *str2)
    {
        return *str1 - *str2;
    }

    return Strcmp(++str1, ++str2);
}

char* Strcpy(char* dst, const char* src)
{
    assert(dst);
    assert(src);

    *dst = *src;
    if(*src == '\0')
    {
        return dst - 1;
    }

    Strcpy(++dst, ++src);

    return dst - 1;
}

char* Strcat(char* dst, const char* src)
{
    assert(dst);
    assert(src);

    if(*dst == '\0')
    {
        return Strcpy(dst, src);
    }

    return Strcat(++dst, src) - 1;
}

char* Strstr(const char* haystack, const char* needle)
{
    assert(haystack);
    assert(needle);

    if(Strlen(haystack) < Strlen(needle))
    {
        return NULL;
    }

    if(strncmp(haystack, needle, Strlen(needle)) == 0)
    {
        return (char*)haystack;
    }

    return Strstr(++haystack, needle);
}