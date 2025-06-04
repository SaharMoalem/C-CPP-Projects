/******************************************************************************
 * File Name: p_queue
 * Owner: Sahar Moalem                                                             
 * Reviewer: Amit
 * Review status: Approved
 ******************************************************************************/ 
 
#include <stdlib.h>                  /* malloc, free */
#include <assert.h>                  /* assert */

#include "pq_heap.h"
#include "heap.h"

struct priority_queue
{
    heap_t* heap;
};

pq_t* PQCreate(int (*compare_func)(const void*, const void*))
{
    pq_t* pq = NULL;
    
    assert(compare_func);
    pq = (pq_t*)malloc(sizeof(pq_t));
    if (pq == NULL)
    {
        return NULL;
    }
    
    pq->heap = HeapCreate(compare_func);
    if (pq->heap == NULL)
    {
        free(pq);
        return NULL;
    }
    
    return pq;
}

void PQDestroy(pq_t* pq)
{
    assert(pq);
    
    HeapDestroy(pq->heap);
    free(pq);
}

int PQEnqueue(pq_t* pq, void* data)
{
    assert(pq);
    
    return HeapPush(pq->heap, data);
}

void* PQDequeue(pq_t* pq)
{
    void* peek = NULL;

    assert(pq);
    assert(!PQIsEmpty(pq));
    
    peek = HeapPeek(pq->heap);
    HeapPop(pq->heap);
    
    return peek;
}

void* PQPeek(const pq_t* pq)
{
    assert(pq);
    assert(!PQIsEmpty(pq));
    
    return HeapPeek(pq->heap);
}

int PQIsEmpty(const pq_t* pq)
{
    assert(pq);
    
    return HeapIsEmpty(pq->heap);
}

size_t PQSize(const pq_t* pq)
{
    assert(pq);
    
    return HeapSize(pq->heap);
}

void PQClear(pq_t* pq)
{
    assert(pq);
    
    while (!PQIsEmpty(pq))
    {
        PQDequeue(pq);
    }
}

void* PQErase(pq_t* pq, int (*is_match)(const void*, const void*), const void* param)
{
    assert(pq);
    assert(is_match);

    return HeapRemove(pq->heap, (void*)param, is_match);
}
