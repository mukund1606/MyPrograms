#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 50

char c;
int stack[ms];
int tos = -1, op, n;

void push(int elem) {
  if (tos != ms - 1) {
    stack[++tos] = elem;
    printf("Element %d is Pushed\n", stack[tos]);
  } else {
    printf("Overflow\n");
  }
}

void pop() {
  if (tos != -1) {
    tos--;
    printf("Element %d is Poped\n", stack[tos + 1]);
  } else {
    printf("Undeflow\n");
  }
}

int main() {
  printf("Enter Y for Stack Operation or N to Exit\n");
  scanf("%s", &c);
  while (c == 'Y' || c == 'y') {
    printf("Enter 1 for Push\nEnter 2 for Pop\n");
    scanf("%d", &op);
    switch (op) {
    case 1: {
      printf("Enter The Element: ");
      scanf("%d", &n);
      push(n);
      break;
    }
    case 2: {
      pop();
      break;
    }
    default: {
      printf("Invalid Choice\n");
      break;
    }
    }
    printf("Enter Y to Continue or N to Exit\n");
    scanf("%s", &c);
  }
  for (int i = tos; i > -1; i--) {
    printf("%d\n", stack[i]);
  }
  return 0;
}