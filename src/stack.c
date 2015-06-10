#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

Stack *stackCreate()
{
  Stack *stack = malloc(sizeof(Stack));
  assert(stack != NULL); //only use it in production code, not in test code
  
  stack->head = NULL;
  stack->tail = NULL;
  stack->length = 0;
}

StackElement *stackElementCreate(int data)
{
  StackElement *element = malloc(sizeof(StackElement));
  assert(element != NULL);
  
  element->data = data;
  element->next = NULL;
  
  return element;
}

void stackAdd(Stack *stack, StackElement *element)
{
  if(element->data == 0)
  {}
  else
  {
    if(stack->head == NULL)
    {
      stack->head = stack->tail = element;
      stack->length = 1;
    }
    else
    {
      element->next = stack->head;
      stack->head = element;
      stack->length++;
    }
  }
}

StackElement *stackRemove(Stack *stack)
{
  StackElement *del,
                *elemRemove = malloc(sizeof(StackElement));
  
  if(stack->head == NULL)
    return NULL;
  else
  {
    del = stack->head;
    elemRemove->data = del->data;
    elemRemove->next = NULL;
    stack->head = stack->head->next;
    stack->length--;
    free(del);
  }
  
  if(stack->head == NULL)
  {
    stack->head = stack->tail = NULL;
    stack->length = 0;
  }
  
  return elemRemove;
}
