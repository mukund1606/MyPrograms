#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next_node;
};

void traverseList(struct Node *start_node) {
  if (start_node == NULL) {
    printf("Empty Linked List");
  } else {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp = start_node;
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next_node;
    }
    free(temp);
  }
  printf("\n");
}

void insertStart(struct Node **start_node, int data) {
  struct Node *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next_node = *start_node;
  *start_node = temp;
  free(temp);
}

void insertEnd(struct Node **start_node, int data) {
  struct Node *temp, *temp2;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next_node = NULL;
  if (*start_node == NULL) {
    *start_node = temp;
  } else {
    temp2 = *start_node;
    while (temp2->next_node != NULL) {
      temp2 = temp2->next_node;
    }
    temp2->next_node = temp;
  }
  free(temp);
  free(temp2);
}

void insert(struct Node **start_node, int data) {
  struct Node *temp, *temp2;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next_node = NULL;
  if (*start_node == NULL) {
    *start_node = temp;
  } else {
    temp2 = *start_node;
    if (temp2->data > data) {
      temp->next_node = temp2;
      *start_node = temp;
    } else {
      while (temp2->next_node != NULL && temp2->next_node->data < data) {
        temp2 = temp2->next_node;
      }
      temp->next_node = temp2->next_node;
      temp2->next_node = temp;
    }
  }
  free(temp);
}

void delete (struct Node **start_node, int data) {
  struct Node *temp, *temp2;
  temp = (struct Node *)malloc(sizeof(struct Node));
  if (start_node == NULL) {
    printf("Underflow\n");
  } else {
    temp = *start_node;
    if (temp->data == data) {
      *start_node = temp->next_node;
      printf("Element Deleted is %d\n", temp->data);
    } else {
      while (temp->data != data && temp->next_node != NULL) {
        temp2 = temp;
        temp = temp->next_node;
      }
      if (temp->data == data) {
        temp2->next_node = temp->next_node;
        printf("Element Deleted is %d\n", temp->data);
      } else {
        printf("Element %d Not Found\n", data);
      }
    }
  }
}

int main() {
  struct Node *first = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;

  first = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  first->data = 5;
  second->data = 7;
  third->data = 8;

  first->next_node = second;
  second->next_node = third;
  third->next_node = NULL;

  printf("\nOriginal Linked List: ");
  traverseList(first);

  insertEnd(&first, 1);
  insert(&first, 15);
  insertStart(&first, 7);

  printf("\n\nLinked List After Insertion: ");
  traverseList(first);

  printf("\n\n");
  delete (&first, 1);
  delete (&first, 7);
  delete (&first, 9);
  delete (NULL, 9);

  printf("\n\nLinked List After Deletion: ");
  traverseList(first);
  getch();
  return 0;
}