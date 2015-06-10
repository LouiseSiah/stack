#ifndef stack_H
#define stack_H

typedef struct StackElement StackElement;

struct StackElement
{
  StackElement *next;
  int data;
};

typedef struct
{
  StackElement *head;
  StackElement *tail;
  int length;
} Stack;

Stack *stackCreate();
StackElement *stackElementCreate(int data);
void stackAdd(Stack *stack, StackElement *elem);
StackElement *stackRemove(Stack *stack);

#endif // stack_H
