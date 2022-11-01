#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct stackNode {
  unsigned int data;
  struct stackNode *next;
};

struct stackNode *createStackNode(int data) {
  struct stackNode *stackNode =
      (struct stackNode *)malloc(sizeof(struct stackNode));
  stackNode->data = data;
  stackNode->next = NULL;
  return stackNode;
};

int isEmpty(struct stackNode *stack) {
  if (stack == NULL) {
    return 1;
  }
  return 0;
}

void push(struct stackNode **stack, int data) {
  struct stackNode *temp = createStackNode(data);
  temp->next = *stack;
  printf("Element %d Pushed To Stack\n", temp->data);
  *stack = temp;
}

void pop(struct stackNode **stack) {
  if (isEmpty(*stack)) {
    printf("Overflow\n");
  } else {
    struct stackNode *temp = *stack;
    *stack = (*stack)->next;
    printf("Element %d Removed From Stack\n", temp->data);
    free(temp);
  }
}

void peek(struct stackNode *stack) {
  if (isEmpty(stack)) {
    printf("Empty Stack\n");
  } else {
    struct stackNode *temp;
    temp = stack;
    printf("Elements in Stack Are: ");
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
  }
  printf("\n");
}

int main() {
  int ch, val, i = 1;
  struct stackNode *stack = NULL;
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
      push(&stack, val);
      break;
    case 2:
      pop(&stack);
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
  return 0;
}