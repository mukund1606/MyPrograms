#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  unsigned int size;
  int top;
  int *arr;
};

struct Stack *createStack(unsigned int size) {
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->size = size;
  stack->top = -1;
  stack->arr = (int *)malloc(size * sizeof(int));
  return stack;
};

int isFull(struct Stack *stack) {
  if (stack->size == stack->top + 1) {
    return 1;
  }
  return 0;
}

int isEmpty(struct Stack *stack) {
  if (stack->top == -1) {
    return 1;
  }
  return 0;
}

void push(struct Stack *stack, int elem) {
  if (isFull(stack)) {
    printf("Overflow\n");
  } else {
    stack->top++;
    stack->arr[stack->top] = elem;
    printf("Element %d Pushed to Stack\n", elem);
  }
}

void pop(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Underflow\n");
  } else {
    printf("Element %d Removed From Stack\n", stack->arr[stack->top]);
    stack->arr[stack->top] = 0;
    stack->top--;
  }
}

void peek(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Empty Stack\n");
  } else {
    int temp = stack->top;
    printf("Elements in Stack Are: ");
    while (temp > -1) {
      printf("%d ", stack->arr[temp--]);
    }
    printf("\n");
  }
}

int main() {
  int size, ch, val, i = 1;
  printf("Enter Size of Stack: ");
  scanf("%d", &size);
  struct Stack *stack = createStack(size);
  printf("Enter 1 to Push\n");
  printf("Enter 2 to Pop\n");
  printf("Enter 3 to Peek\n");
  printf("Enter 4 to Quit\n");
  while (i) {
    printf("Enter Your Choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Enter Value to Push: ");
      scanf("%d", &val);
      push(stack, val);
      break;
    case 2:
      pop(stack);
      break;
    case 3:
      peek(stack);
      break;
    case 4:
      i = 0;
      break;
    default:
      printf("Wrong Choice\nTry Again!\n");
      break;
    }
  }
  // push(stack, 10);
  // push(stack, 7);
  // push(stack, 15);
  // peek(stack);
  // pop(stack);
  // peek(stack);
  return 0;
}