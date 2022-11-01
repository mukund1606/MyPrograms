#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *ptr;
};

void traverseList(struct Node *start) {
  if (start == NULL) {
    printf("Empty Linked List");
  } else {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp = start;
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->ptr;
    }
  }
  printf("\n");
}

void insertStart(struct Node **start, int data) {
  struct Node *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->ptr = *start;
  *start = temp;
}

void insertEnd(struct Node **start, int data) {
  struct Node *temp, *temp2;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->ptr = NULL;
  if (*start == NULL) {
    *start = temp;
  } else {
    temp2 = *start;
    while (temp2->ptr != NULL) {
      temp2 = temp2->ptr;
    }
    temp2->ptr = temp;
  }
}

void insert(struct Node **start, int data) {
  struct Node *temp, *temp2;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->ptr = NULL;
  if (*start == NULL) {
    *start = temp;
  } else {
    temp2 = *start;
    if (temp2->data > data) {
      temp->ptr = temp2;
      *start = temp;
    } else {
      while (temp2->ptr != NULL && temp2->ptr->data < data) {
        temp2 = temp2->ptr;
      }
      temp->ptr = temp2->ptr;
      temp2->ptr = temp;
    }
  }
}

void delete (struct Node **start, int data) {
  struct Node *temp, *temp2;
  temp = (struct Node *)malloc(sizeof(struct Node));
  if (start == NULL) {
    printf("Underflow\n");
  } else {
    temp = *start;
    if (temp->data == data) {
      *start = temp->ptr;
      printf("Element Deleted is %d\n", temp->data);
    } else {
      while (temp->data != data && temp->ptr != NULL) {
        temp2 = temp;
        temp = temp->ptr;
      }
      if (temp->data == data) {
        temp2->ptr = temp->ptr;
        printf("Element Deleted is %d\n", temp->data);
      } else {
        printf("Element %d Not Found\n", data);
      }
    }
  }
}

int main() {
  struct Node *start = NULL;
  struct Node *second = NULL;
  struct Node *last = NULL;

  start = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  last = (struct Node *)malloc(sizeof(struct Node));

  scanf("%d", &start->data);
  start->data = 5;
  second->data = 7;
  last->data = 8;

  start->ptr = second;
  second->ptr = last;
  last->ptr = NULL;

  printf("\nOriginal Linked List: ");
  traverseList(start);

  insertEnd(&start, 1);
  insert(&start, 15);
  insertStart(&start, 7);

  printf("\n\nLinked List After Insertion: ");
  traverseList(start);

  printf("\n\n");
  delete (&start, 1);
  delete (&start, 7);
  delete (&start, 9);
  delete (NULL, 9);

  printf("\n\nLinked List After Deletion: ");
  traverseList(start);
  printf("Hello");

  return 0;
}